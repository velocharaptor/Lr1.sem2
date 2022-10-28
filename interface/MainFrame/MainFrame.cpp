#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/listbook.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    panel = new wxPanel(this);
    //panel->SetBackgroundColour(*wxLIGHT_GREY);
    panel->SetBackgroundColour(wxTheColourDatabase->Find("WHITE"));

    sorts.Add("Quick");
    sorts.Add("Shell");
    sorts.Add("Insertion");
    //rbFirstSort = new wxRadioBox(panel, wxID_ANY, "Sort №1", wxPoint(30, 20), wxDefaultSize, sorts);
    //rbSecondSort = new wxRadioBox(panel, wxID_ANY, "Sort №2", wxPoint(30, 80), wxDefaultSize, sorts);
    //rbSecondSort->SetSelection(1);
    choice = new wxChoice(panel, wxID_ANY, wxPoint(30, 25), wxDefaultSize, sorts);
    choice1 = new wxChoice(panel, wxID_ANY, wxPoint(140, 25), wxDefaultSize, sorts);
    choice->SetSelection(1);

    //default buttons for graph window
    txtSlider = new wxStaticText(panel, wxID_ANY, "Number of items: ", wxPoint(30, 55), wxDefaultSize);
    //txtSlider->SetOwnForegroundColour(wxTheColourDatabase->Find("GREEN"));
    slider = new wxSlider(panel, wxID_ANY, 10, 5, 10000, wxPoint(30, 70), wxSize(200, -1), wxSL_LABELS);

    btnCreate = new wxButton(panel, wxID_ANY, "Create arrays", wxPoint(300, 25), wxSize(120, -1));
    btnCreate->SetOwnForegroundColour(wxTheColourDatabase->Find("GREEN"));
    btnPrint = new wxButton(panel, wxID_ANY, "Print arrays", wxPoint(300, 55), wxSize(120, -1));
    btnPrint->SetForegroundColour(wxTheColourDatabase->Find("GREEN"));
    btnSort = new wxButton(panel, wxID_ANY, "Sort arrays", wxPoint(300, 85), wxSize(120, -1));
    btnSort->SetForegroundColour(wxTheColourDatabase->Find("GREEN"));
    btnGraphs = new wxButton(panel, wxID_ANY, "Calculate graphs", wxPoint(300, 115), wxSize(120, -1));
    btnGraphs->SetForegroundColour(wxTheColourDatabase->Find("GREEN"));
    btnTests = new wxButton(panel, wxID_ANY, "Tests", wxPoint(500, 25), wxSize(120, -1));

    txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(30, 150), wxSize(500, 75), wxTE_MULTILINE);
    txtPrint->SetBackgroundColour(wxColour(245, 245, 245));

    btnCreate->Bind(wxEVT_BUTTON, &MainFrame::OnCreateBtnClickedI, this);
    btnPrint->Bind(wxEVT_BUTTON, &MainFrame::OnPrintBtnClicked, this);
    btnSort->Bind(wxEVT_BUTTON, &MainFrame::OnSortBtnClicked, this);
    btnGraphs->Bind(wxEVT_BUTTON, &MainFrame::OnGraphBtnClicked, this);
    btnTests->Bind(wxEVT_BUTTON, &MainFrame::OnTestsBtnClicked, this);

    chart1 = new ChartControl(panel, 121, wxPoint(30, 240), wxSize(350, 350));
    chart1->SetBackgroundColour(wxColour(245, 245, 245));
    chart1->values = { 0.34, -0.17, 0.98, 0.33 };

    chart2 = new ChartControl(panel, wxID_ANY, wxPoint(420, 240), wxSize(350, 350));
    chart2->SetBackgroundColour(wxColour(245, 245, 245));
    chart2->values = { 0.34, -0.17, 0.98, 0.33 };
}

void MainFrame::OnCreateBtnClickedI(wxCommandEvent& evt) {
    presenter1.createArr(slider->GetValue());
    presenter2.createArr(slider->GetValue());
    txtPrint->WriteText("Arrays were created!\n\n");
}

void MainFrame::OnTestsBtnClicked(wxCommandEvent& evt) {
    txtPrint->WriteText(SortTests());
}

void MainFrame::OnPrintBtnClicked(wxCommandEvent& evt) {
    string arr1 = presenter1.getArr();
    string arr2 = presenter2.getArr();
    txtPrint->WriteText("First array: " + arr1 + "\n" + "Second array: " + arr2 + "\n\n");
}

void MainFrame::OnSortBtnClicked(wxCommandEvent& evt) {
    string time1 = presenter1.sortArr(sorts_std[choice->GetSelection()]);
    string time2 = presenter2.sortArr(sorts_std[choice1->GetSelection()]);
    txtPrint->WriteText("Arrays were sorted!\n");
    txtPrint->WriteText("Sorting time first array: " + time1 + " ms" + "\n");
    txtPrint->WriteText("Sorting time second array: " + time2 + " ms" + "\n\n");
}

void MainFrame::OnGraphBtnClicked(wxCommandEvent& evt) {
    vector<double> valVec1 = presenter1.getPointForGraph(sorts_std[choice->GetSelection()]);
    vector<double> valVec2 = presenter2.getPointForGraph(sorts_std[choice1->GetSelection()]);
    chart1 = new ChartControl(panel, 121, wxPoint(30, 240), wxSize(350, 350));
    chart1->title = sorts[choice->GetSelection()] + " Sort";
    chart1->SetBackgroundColour(wxColour(245, 245, 245));
    chart1->values = valVec1;
    chart2 = new ChartControl(panel, wxID_ANY, wxPoint(420, 240), wxSize(350, 350));
    chart2->title = sorts[choice1->GetSelection()] + " Sort";
    chart2->SetBackgroundColour(wxColour(245, 245, 245));
    chart2->values = valVec2;
}