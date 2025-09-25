typedef struct _DXGKARGCB_GETCAPTUREADDRESS {
  [in]  D3DKMT_HANDLE    hAllocation;
  [out] UINT             SegmentId;
  [out] PHYSICAL_ADDRESS PhysicalAddress;
} DXGKARGCB_GETCAPTUREADDRESS;