PVIDEO_HW_GET_CHILD_DESCRIPTOR PvideoHwGetChildDescriptor;

VP_STATUS PvideoHwGetChildDescriptor(
  [in]  IN PVOID HwDeviceExtension,
  [in]  IN PVIDEO_CHILD_ENUM_INFO ChildEnumInfo,
  [out] OUT PVIDEO_CHILD_TYPE VideoChildType,
  [out] OUT PUCHAR pChildDescriptor,
  [out] OUT PULONG UId,
  [out] OUT PULONG pUnused
)
{...}