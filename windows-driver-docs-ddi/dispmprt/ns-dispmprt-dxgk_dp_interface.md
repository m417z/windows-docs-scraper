## Description

A kernel-mode component that needs to use the **DXGK_DP_INTERFACE** DisplayPort (DP) interface calls the display miniport driver's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function.

## Members

### `Size`

Size, in bytes, of this structure.

### `Version`

Version number of the DP interface. Version numbers constants are defined in *dispmprt.h* (for example, DXGK_DP_INTERFACE_VERSION_1).

### `Context`

Pointer to a private context block provided by the display miniport driver.

### `InterfaceReference`

[**PINTERFACE_REFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) interface reference function that is implemented by the display miniport driver.

### `InterfaceDereference`

[**PINTERFACE_DEREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) interface dereference function that is implemented by the display miniport driver.

### `DxgkDdiQueryDPCaps`

Pointer to the display miniport driver's [DXGKDDI_QUERYDPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps) function.

### `DxgkDdiGetDPAddress`

Pointer to the display miniport driver's [DXGKDDI_GETDPADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdpaddress) function.

### `DxgkDdiDPAuxIoTransmission`

Pointer to the display miniport driver's [DXGKDDI_DPAUXIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission) function.

### `DxgkDdiDPI2CIoTransmission`

Pointer to the display miniport driver's [DXGKDDI_DPI2CIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission) function.

### `DxgkDdiDPSBMTransmission`

Pointer to the display miniport driver's [DXGKDDI_DPSBMTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission) function.

## Remarks

| Minimum supported client | Header | IRQL |
|--|--|--|
| Available in WDDM 2.7 and later version | dispmprt.h(include Dispmprt.h) | PASSIVE_LEVEL |

## See also

[DXGKDDI_DPAUXIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission)

[DXGKDDI_DPI2CIOTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission)

[DXGKDDI_DPSBMTRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission)

[DXGKDDI_GETDPADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdpaddress)

[DXGKDDI_QUERYDPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps)

[**PINTERFACE_DEREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[**PINTERFACE_REFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)