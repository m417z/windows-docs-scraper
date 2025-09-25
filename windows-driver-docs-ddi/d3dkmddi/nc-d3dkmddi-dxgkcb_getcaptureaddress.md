# DXGKCB_GETCAPTUREADDRESS callback function

## Description

**DXGKCB_GETCAPTUREADDRESS** retrieves the physical address and segment identifier of a capture buffer that is associated with the given allocation handle.

## Parameters

### `unnamedParam1` [in/out]

A pointer to a [**DXGKARGCB_GETCAPTUREADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_getcaptureaddress) structure that describes parameters for retrieving information about a capture buffer.

## Return value

**DXGKCB_GETCAPTUREADDRESS** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | **DXGKCB_GETCAPTUREADDRESS** successfully retrieved the capture buffer information. |
| **STATUS_INVALID_PARAMETER** | The allocation handle that is specified in the **hAllocation** member of the [DXGKARGCB_GETCAPTUREADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_getcaptureaddress) structure that the pData parameter pointed to was either invalid or did not represent a capture buffer. |

**DXGKCB_GETCAPTUREADDRESS** might also return other error codes that are defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_GETCAPTUREADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_getcaptureaddress) and then call **DxgkCbGetCaptureAddress** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_GETCAPTUREADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_getcaptureaddress)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)