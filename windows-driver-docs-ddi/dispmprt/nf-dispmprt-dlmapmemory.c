VP_STATUS DlMapMemory(
  IN PVOID            DeviceHandle,
  IN PHYSICAL_ADDRESS TranslatedAddress,
  IN OUT PULONG       Length,
  IN PULONG           InIoSpace,
  IN OUT PVOID        *VirtualAddress
);