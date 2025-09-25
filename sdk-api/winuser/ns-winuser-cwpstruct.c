typedef struct tagCWPSTRUCT {
  LPARAM lParam;
  WPARAM wParam;
  UINT   message;
  HWND   hwnd;
} CWPSTRUCT, *PCWPSTRUCT, *NPCWPSTRUCT, *LPCWPSTRUCT;