#ifndef LR2_MAINFRAME_H
#define LR2_MAINFRAME_H

#include "Chartcontrol.h"
#include "Presenter.h"
#include "tests.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title);
private:
    wxChoice* choice;
    wxChoice* choice1;
    wxButton* btnTests;
    wxTextCtrl* txtPrint;
    wxStaticText* txtSlider;
    wxPanel* panel;
    ChartControl* chart1, * chart2;
    wxRadioBox* rbFirstSort, * rbSecondSort;
    wxSlider* slider;
    wxButton* btnPrint, * btnSort, * btnGraphs, * btnCreate;
    wxArrayString sorts;
    string sorts_std[3] = {"Insertion", "Quick", "Shell"};
    Presenter presenter1, presenter2;
    void OnCreateBtnClickedI(wxCommandEvent& evt);
    void OnPrintBtnClicked(wxCommandEvent& evt);
    void OnSortBtnClicked(wxCommandEvent& evt);
    void OnGraphBtnClicked(wxCommandEvent& evt);
    void OnTestsBtnClicked(wxCommandEvent& evt);
};

#endif //LR2_MAINFRAME_H
