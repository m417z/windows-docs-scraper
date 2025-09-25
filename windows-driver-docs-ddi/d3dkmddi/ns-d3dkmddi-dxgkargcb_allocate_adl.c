typedef struct _DXGKARGCB_ALLOCATE_ADL {
  [in]  HANDLE   hAdapterMemoryObject;
  [in]  SIZE_T   Offset;
  [in]  SIZE_T   Size;
  union {
    struct {
      UINT32 RequireContiguous : 1;
      UINT32 PreferContiguous : 1;
      UINT32 Reserved : 30;
    };
          UINT32 Value;
  } Flags;
  [out] DXGK_ADL *pAdl;
} DXGKARGCB_ALLOCATE_ADL;