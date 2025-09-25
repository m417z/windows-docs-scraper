typedef struct tagFINDREPLACEA {
  DWORD        lStructSize;
  HWND         hwndOwner;
  HINSTANCE    hInstance;
  DWORD        Flags;
  LPSTR        lpstrFindWhat;
  LPSTR        lpstrReplaceWith;
  WORD         wFindWhatLen;
  WORD         wReplaceWithLen;
  LPARAM       lCustData;
  LPFRHOOKPROC lpfnHook;
  LPCSTR       lpTemplateName;
} FINDREPLACEA, *LPFINDREPLACEA;