typedef struct tagDATETIMEPICKERINFO {
  DWORD cbSize;
  RECT  rcCheck;
  DWORD stateCheck;
  RECT  rcButton;
  DWORD stateButton;
  HWND  hwndEdit;
  HWND  hwndUD;
  HWND  hwndDropDown;
} DATETIMEPICKERINFO, *LPDATETIMEPICKERINFO;