typedef struct _DS_SELECTION_LIST {
  ULONG        cItems;
  ULONG        cFetchedAttributes;
  DS_SELECTION aDsSelection[ANYSIZE_ARRAY];
} DS_SELECTION_LIST, *PDS_SELECTION_LIST;