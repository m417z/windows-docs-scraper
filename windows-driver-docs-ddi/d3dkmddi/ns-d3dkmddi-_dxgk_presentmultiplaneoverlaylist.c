typedef struct _DXGK_PRESENTMULTIPLANEOVERLAYLIST {
       UINT             LayerIndex;
       BOOL             Enabled;
       HANDLE           hDeviceSpecificAllocation;
  struct {
    [in] UINT SegmentId : 5;
         UINT Reserved : 27;
  };
  [in] PHYSICAL_ADDRESS PhysicalAddress;
} DXGK_PRESENTMULTIPLANEOVERLAYLIST;