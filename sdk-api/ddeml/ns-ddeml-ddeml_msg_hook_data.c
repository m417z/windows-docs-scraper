typedef struct tagDDEML_MSG_HOOK_DATA {
  UINT_PTR uiLo;
  UINT_PTR uiHi;
  DWORD    cbData;
  DWORD    Data[8];
} DDEML_MSG_HOOK_DATA, *PDDEML_MSG_HOOK_DATA;