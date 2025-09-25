STREAM_PHYSICAL_ADDRESS STREAMAPI StreamClassGetPhysicalAddress(
  [in]           PVOID                    HwDeviceExtension,
  [in, optional] PHW_STREAM_REQUEST_BLOCK HwSRB,
  [in]           PVOID                    VirtualAddress,
  [in]           STREAM_BUFFER_TYPE       Type,
  [out]          ULONG                    *Length
);