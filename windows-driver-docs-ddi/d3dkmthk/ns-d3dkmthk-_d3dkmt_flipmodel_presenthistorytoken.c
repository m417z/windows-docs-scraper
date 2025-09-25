typedef struct _D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN {
  D3DKMT_ALIGN64 UINT64                     FenceValue;
  D3DKMT_ALIGN64 ULONG64                    hLogicalSurface;
  D3DKMT_ALIGN64 D3DKMT_UINT_PTR            dxgContext;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID            VidPnSourceId;
  UINT                                      SwapChainIndex;
  D3DKMT_ALIGN64 UINT64                     PresentLimitSemaphoreId;
  D3DDDI_FLIPINTERVAL_TYPE                  FlipInterval;
  D3DKMT_FLIPMODEL_PRESENTHISTORYTOKENFLAGS Flags;
  D3DKMT_ALIGN64 LONG64                     hCompSurf;
  LUID                                      compSurfLuid;
  D3DKMT_ALIGN64 UINT64                     confirmationCookie;
  D3DKMT_ALIGN64 UINT64                     CompositionSyncKey;
  RECT                                      ScrollRect;
  POINT                                     ScrollOffset;
  UINT                                      PresentCount;
  FLOAT                                     RevealColor[4];
  D3DDDI_ROTATION                           Rotation;
  union {
    D3DKMT_SCATTERBLTS ScatterBlts;
    struct {
      HANDLE                   hSyncObject;
      D3DDDI_HDR_METADATA_TYPE HDRMetaDataType;
      union {
        D3DDDI_HDR_METADATA_HDR10     HDRMetaDataHDR10;
        D3DDDI_HDR_METADATA_HDR10PLUS HDRMetaDataHDR10Plus;
      };
    };
  };
  UINT                                      InkCookie;
  RECT                                      SourceRect;
  UINT                                      DestWidth;
  UINT                                      DestHeight;
  RECT                                      TargetRect;
  FLOAT                                     Transform[6];
  UINT                                      CustomDuration;
  D3DDDI_FLIPINTERVAL_TYPE                  CustomDurationFlipInterval;
  UINT                                      PlaneIndex;
  D3DDDI_COLOR_SPACE_TYPE                   ColorSpace;
  D3DKMT_DIRTYREGIONS                       DirtyRegions;
} D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN;