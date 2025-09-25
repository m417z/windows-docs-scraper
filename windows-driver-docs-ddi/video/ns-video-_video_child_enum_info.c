typedef struct _VIDEO_CHILD_ENUM_INFO {
  ULONG Size;
  ULONG ChildDescriptorSize;
  ULONG ChildIndex;
  ULONG ACPIHwId;
  PVOID ChildHwDeviceExtension;
} VIDEO_CHILD_ENUM_INFO, *PVIDEO_CHILD_ENUM_INFO;