typedef struct _STOR_SCATTER_GATHER_LIST {
  ULONG                       NumberOfElements;
  ULONG_PTR                   Reserved;
  STOR_SCATTER_GATHER_ELEMENT List[];
} STOR_SCATTER_GATHER_LIST, *PSTOR_SCATTER_GATHER_LIST;