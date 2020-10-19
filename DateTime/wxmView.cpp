//
//  wxmView.cpp
//  DateTime
//
//  Created by Joseph Costello on 10/18/20.
//

#include "wxmView.hpp"

#include <wx/grid.h>
#include <wx/clipbrd.h>
#include <wx/url.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/combo.h>
#include <wx/odcombo.h>
#include <wx/valgen.h>



#define frameWidth 600
#define frameHeight 50


enum {
    ID_VALUE_TIMER = 10001,
    
};

//Constructor
wxmView::wxmView()
: wxFrame(NULL, wxID_ANY, "DateTime")
{
    //Set background color and size
    this->wxWindow::SetBackgroundColour(* wxGREEN);
    this->SetSize(frameWidth, frameHeight);
    //Set min and max size (window cannot be resized)
    SetMinSize(GetSize());
    SetMaxSize(GetSize());
    
    //Initialize and start timer with event intervals of 100 milliseconds
    m_timer = new wxTimer(this, ID_VALUE_TIMER);
    m_timer->Start(100);
    
    //Create font for text
    wxFont myFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    //Get current time
    wxDateTime now  = wxDateTime::Now();
    //Initialize text for string
    time = new wxStaticText(this, wxID_ANY, now.Format("%c", wxDateTime::EST).c_str(), wxPoint(1000,500), wxSize(300,50));
    //Set font of text
    time->SetFont(myFont);
    
    //Show application
    this->Refresh();
    //Center frame on window
    this->Center();
}

//Helper function for updating time when timer event is intialized
void wxmView::OnTimer(wxTimerEvent &event){
    //Get current time
    wxDateTime current = wxDateTime::Now();
    //Update text
    time->SetLabel(current.Format("%c", wxDateTime::EST).c_str());
    //End function
    event.Skip();
}

//Destructor
wxmView::~wxmView() {}


BEGIN_EVENT_TABLE(wxmView, wxFrame)
//Listen for timer event and run OnTimer function
EVT_TIMER(ID_VALUE_TIMER, wxmView::OnTimer)
wxEND_EVENT_TABLE()
