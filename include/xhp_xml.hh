/*
 * XHP - XML Hating Python - "Best" XML Library for C++
 * 
 * Created By - Karol "CyberWord" Gocłowski
 * 
 * FILEPATH: include/xhp_xml.hh
 * FILE DESCRIPTION:
 *  XML objects header for XHP library
*/

#ifndef _XHP_XML_HH_GUARD
#define _XHP_XML_HH_GUARD

#include <string_view>
#include <vector>

class XML_Element
{
	std::vector<XML_Element> childs;
};

class XML_Document
{
	XML_Element _root;
	public:
		inline constexpr XML_Element getRoot()
		{
			return _root;
		}

		XML_Document(XML_Element root);
};

enum class XML_Child_Type
{
	Element,
	Text,
};

union XML_Child_Union
{
	XML_Element element;
	std::string_view str;
};

struct XML_Child
{
	XML_Child_Type ctype;
	XML_Child_Union child;
	bool operator == (const XML_Child& xmlchild) const;
	
	bool operator != (const XML_Child& xmlchild)
	{
		return !(*this == xmlchild);
	}
};

#endif
