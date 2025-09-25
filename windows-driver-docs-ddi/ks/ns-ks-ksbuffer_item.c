typedef struct {
  KSDPC_ITEM DpcItem;
  LIST_ENTRY BufferList;
} KSBUFFER_ITEM, *PKSBUFFER_ITEM;