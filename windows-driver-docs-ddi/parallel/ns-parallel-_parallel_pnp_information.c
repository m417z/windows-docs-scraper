typedef struct _PARALLEL_PNP_INFORMATION {
  PHYSICAL_ADDRESS             OriginalEcpController;
  PUCHAR                       EcpController;
  ULONG                        SpanOfEcpController;
  ULONG                        PortNumber;
  ULONG                        HardwareCapabilities;
  PPARALLEL_SET_CHIP_MODE      TrySetChipMode;
  PPARALLEL_CLEAR_CHIP_MODE    ClearChipMode;
  ULONG                        FifoDepth;
  ULONG                        FifoWidth;
  PHYSICAL_ADDRESS             EppControllerPhysicalAddress;
  ULONG                        SpanOfEppController;
  ULONG                        Ieee1284_3DeviceCount;
  PPARALLEL_TRY_SELECT_ROUTINE TrySelectDevice;
  PPARALLEL_DESELECT_ROUTINE   DeselectDevice;
  PVOID                        Context;
  ULONG                        CurrentMode;
  PWSTR                        PortName;
} PARALLEL_PNP_INFORMATION, *PPARALLEL_PNP_INFORMATION;