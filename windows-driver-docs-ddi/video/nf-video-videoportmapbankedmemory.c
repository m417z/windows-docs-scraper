VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortMapBankedMemory(
  PVOID                   HwDeviceExtension,
  PHYSICAL_ADDRESS        PhysicalAddress,
  PULONG                  Length,
  PULONG                  InIoSpace,
  PVOID                   *VirtualAddress,
  ULONG                   BankLength,
  UCHAR                   ReadWriteBank,
  PBANKED_SECTION_ROUTINE BankRoutine,
  PVOID                   Context
);