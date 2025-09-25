typedef struct tagFINDREPLACEW {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HINSTANCE    hInstance;
  DWORD        Flags;
  LPWSTR       lpstrFindWhat;
  LPWSTR       lpstrReplaceWith;
  WORD         wFindWhatLen;
  WORD         wReplaceWithLen;
  LPARAM       lCustData;
  LPFRHOOKPROC lpfnHook;
  LPCWSTR      lpTemplateName;
} FINDREPLACEW, *LPFINDREPLACEW;