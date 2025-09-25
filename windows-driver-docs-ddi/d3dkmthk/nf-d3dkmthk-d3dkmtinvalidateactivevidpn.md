# D3DKMTInvalidateActiveVidPn function

## Description

The **D3DKMTInvalidateActiveVidPn** function invalidates the active video present network (VidPN) currently in use.

> [!NOTE]
> This function is obsolete in Windows 7 and later versions of Windows operating systems.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn) structure that describes parameters that invalidate the active VidPN currently in use.

## Return value

**D3DKMTInvalidateActiveVidPn** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The VidPN currently in use was successfully invalidated. |
| STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER | No graphics adapter was specified in the hAdapter member of [D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn) to invalidate the VidPN for. |
| STATUS_NO_MEMORY | **D3DKMTInvalidateActiveVidPn** could not complete because of insufficient memory. |
| STATUS_NOT_SUPPORTED | The display mode that is requested by the OpenGL installable client driver (ICD) in the buffer pointed to by the pPrivateDriverData member of [D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn) is not supported by the display miniport driver. This status value will also be returned if this function is called on a computer running Windows 7 and later by a display miniport driver with DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WIN7. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped. |
| STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN | The display miniport driver did not recommend a VidPN to replace the VidPN currently in use. |

This function might also return other **NTSTATUS** values.

## Remarks

When the **D3DKMTInvalidateActiveVidPn** function is called to invalidate the VidPN currently in use, the current VidPN is replaced with a new VidPN that the display miniport driver recommends. Because the display miniport driver must recommend a new VidPN, the display miniport driver must be able to determine the display mode that the OpenGL ICD requires from the buffer pointed to by the **pPrivateDriverData** member of [D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn).

The OpenGL ICD can call **D3DKMTInvalidateActiveVidPn** for display modes (for example, clone-view mode) that are not supported by using the more general call to the [D3DKMTSetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode) function.

## See also

[D3DKMTSetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode)

[D3DKMT_INVALIDATEACTIVEVIDPN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_invalidateactivevidpn)