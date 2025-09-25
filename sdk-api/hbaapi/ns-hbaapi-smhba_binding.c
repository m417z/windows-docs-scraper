typedef struct SMHBA_Binding {
  HBA_UINT32         NumberOfEntries;
  SMHBA_BINDINGENTRY entry[1];
} SMHBA_BINDING, *PSMHBA_BINDING;