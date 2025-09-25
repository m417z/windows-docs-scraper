typedef struct _DXGKARG_SETVIDPNSOURCEADDRESS {
       D3DDDI_VIDEO_PRESENT_SOURCE_ID   VidPnSourceId;
       UINT                             PrimarySegment;
       PHYSICAL_ADDRESS                 PrimaryAddress;
  [in] HANDLE                           hAllocation;
  [in] UINT                             ContextCount;
       HANDLE                           Context[1 + D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] DXGK_SETVIDPNSOURCEADDRESS_FLAGS Flags;
       UINT                             Duration;
       DXGK_PRIMARYDATA                 PrimaryData[D3DDDI_MAX_BROADCAST_CONTEXT];
       UINT                             DriverPrivateDataSize;
       PVOID                            pDriverPrivateData;
} DXGKARG_SETVIDPNSOURCEADDRESS;