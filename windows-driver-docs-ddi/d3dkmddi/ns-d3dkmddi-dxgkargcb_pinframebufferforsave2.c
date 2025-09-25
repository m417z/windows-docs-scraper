typedef struct _DXGKARGCB_PINFRAMEBUFFERFORSAVE2 {
  [in]  UINT     PhysicalAdapterIndex;
  [in]  SIZE_T   CommitSize;
  union {
    struct {
      UINT PreferContiguous : 1;
      UINT Reserved : 31;
    };
          UINT Value;
  } Flags;
  [out] DXGK_ADL *pAdl;
} DXGKARGCB_PINFRAMEBUFFERFORSAVE2;