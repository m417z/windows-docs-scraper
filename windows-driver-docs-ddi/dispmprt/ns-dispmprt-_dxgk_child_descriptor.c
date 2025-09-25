typedef struct _DXGK_CHILD_DESCRIPTOR {
  DXGK_CHILD_DEVICE_TYPE  ChildDeviceType;
  DXGK_CHILD_CAPABILITIES ChildCapabilities;
  ULONG                   AcpiUid;
  ULONG                   ChildUid;
} DXGK_CHILD_DESCRIPTOR, *PDXGK_CHILD_DESCRIPTOR;