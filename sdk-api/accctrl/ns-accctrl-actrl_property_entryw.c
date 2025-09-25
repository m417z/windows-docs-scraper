typedef struct _ACTRL_PROPERTY_ENTRYW {
  LPWSTR                    lpProperty;
  PACTRL_ACCESS_ENTRY_LISTW pAccessEntryList;
  ULONG                     fListFlags;
} ACTRL_PROPERTY_ENTRYW, *PACTRL_PROPERTY_ENTRYW;