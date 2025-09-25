typedef struct _SCATTER_GATHER_LIST {
  ULONG                  NumberOfElements;
  ULONG_PTR              Reserved;
  SCATTER_GATHER_ELEMENT Elements[];
} SCATTER_GATHER_LIST, *PSCATTER_GATHER_LIST;