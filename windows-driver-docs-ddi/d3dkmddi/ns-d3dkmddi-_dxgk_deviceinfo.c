typedef struct _DXGK_DEVICEINFO {
  [out] UINT                 DmaBufferSize;
  [out] UINT                 DmaBufferSegmentSet;
  [out] UINT                 DmaBufferPrivateDataSize;
  [out] UINT                 AllocationListSize;
  [out] UINT                 PatchLocationListSize;
  [out] DXGK_DEVICEINFOFLAGS Flags;
} DXGK_DEVICEINFO;