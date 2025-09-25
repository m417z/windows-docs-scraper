typedef struct _MI_Operation {
  MI_Uint64            reserved1;
  ptrdiff_t            reserved2;
  const MI_OperationFT *ft;
} MI_Operation;