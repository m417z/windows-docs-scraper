typedef struct _DXGK_DIAGNOSTIC_HEADER {
  DXGK_DIAGNOSTIC_CATEGORIES Category;
  DXGK_DIAGNOSTIC_TYPES      Type;
  union {
    struct {
      UINT Size : 16;
      UINT Reserved : 16;
    };
    UINT Value;
  };
  UINT                       SequenceNumber;
  union {
    D3DDDI_VIDEO_PRESENT_TARGET_ID TargetId;
    D3DDDI_VIDEO_PRESENT_SOURCE_ID SourceId;
    UINT                           Id;
  };
} DXGK_DIAGNOSTIC_HEADER;