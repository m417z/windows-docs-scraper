## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The *MiniportWdiAdapterHangDiagnose* handler function is used to collect hardware control register states and optionally full firmware state.

This is a WDI miniport handler inside [**NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ns-dot11wificxintf-ndis_miniport_driver_wdi_characteristics).

> [!NOTE]
> You must declare the function by using the **MINIPORT_WDI_ADAPTER_HANG_DIAGNOSE** type.

## Parameters

### `MiniportDriverContext`

[in]
The handle to a driver-allocated context area where the driver maintains state and configuration information. The miniport driver passed this context area to the [*NdisMRegisterWdiMiniportDriver*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/nf-dot11wificxintf-ndismregisterwdiminiportdriver) function.

### `DiagnoseLevel`

[in]
The diagnose level, as defined in the [**eDiagnoseLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ne-dot11wificxintf-ediagnoselevel) enumeration. The default level is **DiagnoseLevelHardwareRegisters**, 1KB maximum in the output buffer.

### `BufferSize`

[in]
The size of **FirmwareBlob**, in bytes.

### `FirmwareBlob`

[out]
A pointer to the buffer that will contain the hardware control registry states, and optionally full firmware state.

### `pOutputSize`

[out]
A pointer to the number of bytes written to **FirmwareBlob**.

## Return value

The return value is ignored.

## Remarks

The default diagnose level is **DiagnoseLevelHardwareRegisters**, with 1KB maximum in the output buffer.

## See also

[WDI hang detection and recovery](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-hang-detection-and-recovery)

[**NDIS_MINIPORT_DRIVER_WDI_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ns-dot11wificxintf-ndis_miniport_driver_wdi_characteristics)

[**eDiagnoseLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/ne-dot11wificxintf-ediagnoselevel)

[*NdisMRegisterWdiMiniportDriver*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wificxintf/nf-dot11wificxintf-ndismregisterwdiminiportdriver)