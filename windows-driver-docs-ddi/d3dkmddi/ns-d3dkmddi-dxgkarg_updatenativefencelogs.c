typedef struct _DXGKARG_UPDATENATIVEFENCELOGS {
  UINT                                NumberOfQueues;
  HANDLE                              *hHWQueue;
  DXGKARG_UPDATENATIVEFENCELOGS_FLAGS Flags;
  BYTE                                Reserved[32];
} DXGKARG_UPDATENATIVEFENCELOGS;