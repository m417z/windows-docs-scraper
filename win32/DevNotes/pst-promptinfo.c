typedef struct {
  DWORD      cbSize;
  DWORD      dwPromptFlags;
  DWORD_PTR  hwndApp;
  LPCWSTR    szPrompt;
} PST_PROMPTINFO, *PPST_PROMPTINFO;