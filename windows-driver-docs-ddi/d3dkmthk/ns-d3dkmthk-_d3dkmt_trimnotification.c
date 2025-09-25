typedef struct _D3DKMT_TRIMNOTIFICATION {
  [in] VOID                          *Context;
  [in] D3DDDI_TRIMRESIDENCYSET_FLAGS Flags;
  [in] D3DKMT_ALIGN64 UINT64         NumBytesToTrim;
} D3DKMT_TRIMNOTIFICATION;