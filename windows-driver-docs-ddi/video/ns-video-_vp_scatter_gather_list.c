typedef struct _VP_SCATTER_GATHER_LIST {
  ULONG                     NumberOfElements;
  ULONG_PTR                 Reserved;
  VP_SCATTER_GATHER_ELEMENT Elements[];
} VP_SCATTER_GATHER_LIST, *PVP_SCATTER_GATHER_LIST;