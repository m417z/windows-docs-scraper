# D3DKMTSetDisplayMode function

## Description

The **D3DKMTSetDisplayMode** function sets the allocation that is used to scan out to the display.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode) structure that describes the allocation that is used to scan out.

## Return value

**D3DKMTSetDisplayMode** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The display mode was successfully set. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER | Before the call to **D3DKMTSetDisplayMode**, the device did not acquire exclusive ownership of the view. Therefore, the device could not set the display mode. |
| D3DDDIERR_INCOMPATIBLEPRIVATEFORMAT | The OpenGL installable client driver (ICD) must convert the format of the surface that is associated with the allocation that the *hPrimaryAllocation* member of [D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode) specifies into the format attribute that the *PrivateDriverFormatAttribute* member of **D3DKMT_SETDISPLAYMODE** specifies. The ICD should then call **D3DKMTSetDisplayMode** again. The ICD could allocate a new allocation, perform a conversion bit-block transfer (bitblt) from the old primary to the new, and then destroy the old primary as long as the ICD uses the new allocation handle for this allocation for all subsequent operations. The ICD should repeat this process until **D3DKMTSetDisplayMode** returns a different return value. |

This function might also return other **NTSTATUS** values.

## Remarks

Before the OpenGL ICD calls **D3DKMTSetDisplayMode** to set a new display mode that uses an extended format, a multiple-sampling method, or both, the ICD must ensure that the current GDI display mode has the same resolution as the new display mode. Otherwise, **D3DKMTSetDisplayMode** returns **STATUS_INVALID_PARAMETER**.

## See also

[D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode)