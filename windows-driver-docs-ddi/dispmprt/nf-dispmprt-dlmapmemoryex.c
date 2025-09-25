NTSTATUS DlMapMemoryEx(
  IN PVOID            DeviceHandle,
  IN PHYSICAL_ADDRESS TranslatedAddress,
  IN OUT PULONG       Length,
  IN PULONG           InIoSpace,
  IN HANDLE           ProcessHandle,
  IN OUT PVOID        *VirtualAddress,
  IN BOOLEAN          MapToUserMode
);