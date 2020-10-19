//
//  wxmView.hpp
//  DateTime
//
//  Created by Joseph Costello on 10/18/20.
//

#include <wx/wx.h>


class wxmView : public wxFrame {
public:
    wxmView();
    virtual ~wxmView();
    //Text for displaying time
    wxStaticText *time = nullptr;
    //Timer for updating time
    wxTimer *m_timer = nullptr;
    //Function for updating text for time display
    void OnTimer(wxTimerEvent &event);
protected:
    
private:
    //Event table for timer
    DECLARE_EVENT_TABLE()
};
