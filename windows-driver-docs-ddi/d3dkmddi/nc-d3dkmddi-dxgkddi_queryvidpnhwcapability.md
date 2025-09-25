# DXGKDDI_QUERYVIDPNHWCAPABILITY callback function

## Description

The **DxgkDdiQueryVidPnHWCapability** function requests that the display miniport driver report the capabilities of the hardware on a functional VidPn path.

## Parameters

### `i_hAdapter` [in]

A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `io_pVidPnHWCaps` [in/out]

A pointer to a [**DXGKARG_QUERYVIDPNHWCAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryvidpnhwcapability) structure that describes the hardware capabilities of a functional VidPN.

## Return value

**DxgkDdiQueryVidPnHwCapability** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

For more information on how to process this function, see [Querying VidPN Hardware Capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/querying-vidpnhardware-capabilities).

**DxgkDdiQueryInterface** should be made pageable.

## See also

[**DXGKARG_QUERYVIDPNHWCAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryvidpnhwcapability)