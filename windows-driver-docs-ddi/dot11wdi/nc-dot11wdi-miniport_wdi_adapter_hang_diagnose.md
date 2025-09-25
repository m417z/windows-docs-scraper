# MINIPORT_WDI_ADAPTER_HANG_DIAGNOSE callback function

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The MiniportWdiAdapterHangDiagnose handler function is used to collect hardware control register states and optionally full firmware state.

This is a WDI miniport handler inside [NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics).

**Note** You must declare the function by using the **MINIPORT_WDI_ADAPTER_HANG_DIAGNOSE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportDriverContext` [in]

The handle to a driver-allocated context area where the driver maintains state and configuration information. The miniport driver passed this context area to the [NdisMRegisterWdiMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nf-dot11wdi-ndismregisterwdiminiportdriver) function.

### `DiagnoseLevel` [in]

The diagnose level, as defined in the [eDiagnoseLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-ediagnoselevel) enumeration. The default level is **DiagnoseLevelHardwareRegisters**, 1KB maximum in the output buffer.

### `BufferSize` [in]

The size of **FirmwareBlob**, in bytes.

### `FirmwareBlob` [out]

A pointer to the buffer that will contain the hardware control registry states, and optionally full firmware state.

### `pOutputSize` [out]

A pointer to the number of bytes written to **FirmwareBlob**.

## Return value

The return value is ignored.

### Remarks

The default diagnose level is **DiagnoseLevelHardwareRegisters**, with 1KB maximum in the output buffer.

## See also

[NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ns-dot11wdi-_ndis_miniport_driver_wdi_characteristics)

[WDI hang detection and recovery](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-hang-detection-and-recovery)

[eDiagnoseLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/ne-dot11wdi-ediagnoselevel)