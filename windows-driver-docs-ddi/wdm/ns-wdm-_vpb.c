typedef struct _VPB {
  CSHORT                Type;
  CSHORT                Size;
  USHORT                Flags;
  USHORT                VolumeLabelLength;
  struct _DEVICE_OBJECT *DeviceObject;
  struct _DEVICE_OBJECT *RealDevice;
  ULONG                 SerialNumber;
  ULONG                 ReferenceCount;
  WCHAR                 VolumeLabel[MAXIMUM_VOLUME_LABEL_LENGTH / sizeof(WCHAR)];
} VPB, *PVPB;