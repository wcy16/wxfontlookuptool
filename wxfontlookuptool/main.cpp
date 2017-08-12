#include <wx/wx.h>
#include <wx/fontdlg.h>

class myFrame : public wxFrame
{
public:
	myFrame(const wxString& title);
	wxTextCtrl* tc_font;
	wxTextCtrl* tc_font_desc;

	wxString font_str;
	wxString font_desc;

	wxButton* btn;

	void OnBtn(wxCommandEvent & WXUNUSED(event));
};

enum {ID_BTN};

myFrame::myFrame(const wxString& title)
	: wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(350, 150))
{
	wxPanel* panel = new wxPanel(this, -1);
	wxBoxSizer* bs = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* bsf = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* bsfd = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* bsb = new wxBoxSizer(wxHORIZONTAL);
	tc_font = new wxTextCtrl(panel, -1);
	tc_font_desc = new wxTextCtrl(panel, -1);
	btn = new wxButton(panel, ID_BTN, _T("选择字体"));
	
	panel->SetSizer(bs);
	bs->Add(bsf, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND);
	bs->Add(bsfd, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND);
	bs->Add(bsb, 0, wxALIGN_RIGHT);

	bsf->Add(new wxStaticText(panel, -1, "font:"), 0, wxALIGN_CENTER);// , wxEXPAND, 0);
	bsf->Add(tc_font, 1, wxALL | wxALIGN_CENTER, 5);
	bsfd->Add(new wxStaticText(panel, -1, "font desc:"), 0, wxALIGN_CENTER);//, wxEXPAND, 0);
	bsfd->Add(tc_font_desc, 1, wxALL | wxALIGN_CENTER, 5);

	bsb->Add(btn, 0, wxALL, 5);
	
	Connect(ID_BTN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(myFrame::OnBtn));

	
}

void myFrame::OnBtn(wxCommandEvent & WXUNUSED(event))
{
	wxFontDialog * fontDialog = new wxFontDialog(this);
	if (fontDialog->ShowModal() == wxID_OK)
	{
		font_str = fontDialog->GetFontData().GetChosenFont().GetNativeFontInfoUserDesc();
		font_desc = fontDialog->GetFontData().GetChosenFont().GetNativeFontInfoDesc();
		tc_font->SetValue(font_str);
		tc_font_desc->SetValue(font_desc);
		this->Refresh();
	}
}

class myApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(myApp)

bool myApp::OnInit()
{
	myFrame* frame = new myFrame("字体工具");
	frame->Show(true);

	return true;
}
