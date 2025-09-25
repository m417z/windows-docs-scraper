typedef struct tagHELPINFO {
  UINT      cbSize;
  int       iContextType;
  int       iCtrlId;
  HANDLE    hItemHandle;
  DWORD_PTR dwContextId;
  POINT     MousePos;
} HELPINFO, *LPHELPINFO;