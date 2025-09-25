PFNKSDEVICEQUERYCAPABILITIES Pfnksdevicequerycapabilities;

NTSTATUS Pfnksdevicequerycapabilities(
  [in]      PKSDEVICE Device,
  [in]      PIRP Irp,
  [in, out] PDEVICE_CAPABILITIES Capabilities
)
{...}