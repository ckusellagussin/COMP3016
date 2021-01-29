#pragma once

#include <vector>
#include <GL/glew.h>
#include "Renderer.h"
struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeofType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT: return sizeof(GLuint);
		case GL_UNSIGNED_BYTE: return sizeof(GLbyte);
		
		}
		ASSERT(false);
		return 0;

	}
};

//Layout that creates a bunch of elements that maintains the vertexbuffer


class VertexBufferLayout
	
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:
	VertexBufferLayout()
	: m_Stride(0) {}

	template<typename t>
	void Push(unsigned int count)
	{
		static_assert(false);

	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeofType(GL_FLOAT);

	}

	template<>
	void Push<unsigned int>(unsigned int count )
	{
		m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeofType(GL_UNSIGNED_INT) ;

	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count * VertexBufferElement::GetSizeofType(GL_UNSIGNED_BYTE);

	}
	
	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride;  }


};