typedef struct tagTRACKMOUSEEVENT {
  DWORD cbSize;
  DWORD dwFlags;
  HWND  hwndTrack;
  DWORD dwHoverTime;
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;