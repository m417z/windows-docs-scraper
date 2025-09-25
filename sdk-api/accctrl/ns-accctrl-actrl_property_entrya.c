typedef struct _ACTRL_PROPERTY_ENTRYA {
  LPSTR                     lpProperty;
  PACTRL_ACCESS_ENTRY_LISTA pAccessEntryList;
  ULONG                     fListFlags;
} ACTRL_PROPERTY_ENTRYA, *PACTRL_PROPERTY_ENTRYA;