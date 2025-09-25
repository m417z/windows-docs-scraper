GET_DMA_ADAPTER GetDmaAdapter;

_DMA_ADAPTER * GetDmaAdapter(
  [in]  PVOID Context,
  [in]  _DEVICE_DESCRIPTION *DeviceDescriptor,
  [out] PULONG NumberOfMapRegisters
)
{...}