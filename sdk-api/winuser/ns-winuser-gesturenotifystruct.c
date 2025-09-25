typedef struct tagGESTURENOTIFYSTRUCT {
  UINT   cbSize;
  DWORD  dwFlags;
  HWND   hwndTarget;
  POINTS ptsLocation;
  DWORD  dwInstanceID;
} GESTURENOTIFYSTRUCT, *PGESTURENOTIFYSTRUCT;