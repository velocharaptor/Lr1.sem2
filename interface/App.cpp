#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("lr2");
    mainFrame->SetClientSize(850, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}