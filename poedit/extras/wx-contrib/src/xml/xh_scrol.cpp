/////////////////////////////////////////////////////////////////////////////
// Name:        xh_scrol.cpp
// Purpose:     XML resource for wxScrollBar
// Author:      Brian Gavin
// Created:     2000/09/09
// RCS-ID:      $Id$
// Copyright:   (c) 2000 Brian Gavin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
 
#ifdef __GNUG__
#pragma implementation "xh_scrol.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/xml/xh_scrol.h"
#include "wx/scrolbar.h"


wxScrollBarXmlHandler::wxScrollBarXmlHandler() 
: wxXmlResourceHandler() 
{
    ADD_STYLE( wxSB_HORIZONTAL );
    ADD_STYLE( wxSB_VERTICAL );
    AddWindowStyles();
}

wxObject *wxScrollBarXmlHandler::DoCreateResource()
{ 
    wxScrollBar *control = new wxScrollBar(m_parentAsWindow,
                                    GetID(),
                                    GetPosition(), GetSize(),
                                    GetStyle(),
                                    wxDefaultValidator,
                                    GetName()
                                    );
    control->SetScrollbar(GetLong( wxT("value"), 0), 
                          GetLong( wxT("thumbsize"),1),
                          GetLong( wxT("range"), 10),
                          GetLong( wxT("pagesize"),1)
                          );
                          
    
    SetupWindow(control);
    
    return control;
}



bool wxScrollBarXmlHandler::CanHandle(wxXmlNode *node)
{
    return IsOfClass(node, wxT("wxScrollBar"));
}


