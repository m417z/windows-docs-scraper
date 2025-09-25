typedef struct _DXGK_CHILD_CONTAINER_ID {
  GUID   ContainerId;
  struct {
    ULONG64 PortId;
    USHORT  ManufacturerName;
    USHORT  ProductCode;
  } EldInfo;
} DXGK_CHILD_CONTAINER_ID, *PDXGK_CHILD_CONTAINER_ID;