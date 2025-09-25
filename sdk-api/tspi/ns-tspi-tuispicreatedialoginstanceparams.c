typedef struct tuispicreatedialoginstanceparams_tag {
  DRV_REQUESTID       dwRequestID;
  HDRVDIALOGINSTANCE  hdDlgInst;
  HTAPIDIALOGINSTANCE htDlgInst;
  LPCWSTR             lpszUIDLLName;
  LPVOID              lpParams;
  DWORD               dwSize;
} TUISPICREATEDIALOGINSTANCEPARAMS, *LPTUISPICREATEDIALOGINSTANCEPARAMS;