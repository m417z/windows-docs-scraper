typedef struct _CRYPT_PROVUI_FUNCS {
  DWORD                     cbStruct;
  struct _CRYPT_PROVUI_DATA *psUIData;
  PFN_PROVUI_CALL           pfnOnMoreInfoClick;
  PFN_PROVUI_CALL           pfnOnMoreInfoClickDefault;
  PFN_PROVUI_CALL           pfnOnAdvancedClick;
  PFN_PROVUI_CALL           pfnOnAdvancedClickDefault;
} CRYPT_PROVUI_FUNCS, *PCRYPT_PROVUI_FUNCS;