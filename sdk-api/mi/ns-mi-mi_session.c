typedef struct _MI_Session {
  MI_Uint64          reserved1;
  ptrdiff_t          reserved2;
  const MI_SessionFT *ft;
} MI_Session;