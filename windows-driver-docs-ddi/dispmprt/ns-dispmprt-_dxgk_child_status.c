typedef struct _DXGK_CHILD_STATUS {
  DXGK_CHILD_STATUS_TYPE Type;
  ULONG                  ChildUid;
  union {
    struct {
      BOOLEAN Connected;
    } HotPlug;
    struct {
      UCHAR Angle;
    } Rotation;
    struct {
      BOOLEAN                         Connected;
      D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY MiracastMonitorType;
    } Miracast;
  };
} DXGK_CHILD_STATUS, *PDXGK_CHILD_STATUS;