typedef struct _DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE {
  [in]  HANDLE hDxgkProcess;
  [in]  UINT64 SizeInBytes;
  [in]  UINT   Alignment;
  [out] UINT64 StartVirtualAddress;
  [in]  UINT64 BaseAddress;
  union {
    struct {
      UINT AllowUserModeMapping : 1;
    };
    [in]  UINT Flags;
  };
} DXGKARGCB_RESERVEGPUVIRTUALADDRESSRANGE;