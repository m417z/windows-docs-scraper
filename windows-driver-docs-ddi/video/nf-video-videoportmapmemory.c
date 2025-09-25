VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortMapMemory(
  PVOID            HwDeviceExtension,
  PHYSICAL_ADDRESS PhysicalAddress,
  PULONG           Length,
  PULONG           InIoSpace,
  PVOID            *VirtualAddress
);