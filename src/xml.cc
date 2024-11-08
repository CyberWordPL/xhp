/*
 * XHP - XML Hating Python - "Best" XML Library for C++
 * 
 * Created By - Karol "CyberWord" Gocłowski
 * 
 * FILEPATH: src/xml.cc
 * FILE DESCRIPTION:
 *  Implementation of include/xhp_xml.hh
*/

#include <xhp_xml.hh>

XML_Document::XML_Document(XML_Element root)
{
	this->_root = root;
}

bool XML_Child::operator==(const XML_Child &xmlchild) const
{
	if(ctype != xmlchild.ctype) return false;
	if(ctype == XML_Child_Type::Element)
	{
		// TODO
		// I need to implement comparison of XML Elements (by checking params and childs, (ignoring parents))
		// return child.element == xmlchild.child.element ?
		return false;
	} else {
		return child.str.compare(xmlchild.child.str);
	}
}
