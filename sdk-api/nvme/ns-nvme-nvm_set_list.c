typedef struct {
  UCHAR                     IdentifierCount;
  UCHAR                     Reserved[127];
  NVME_SET_ATTRIBUTES_ENTRY Entry[ANYSIZE_ARRAY];
} NVM_SET_LIST, *PNVM_SET_LIST;