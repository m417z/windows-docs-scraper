## Description

KMD's **DxgkDdiDestroyMemoryBasis** function destroys a memory basis that was created by a previous call to [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis).

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `hMemoryBasis`

Handle to the memory basis to destroy. This handle was previously created by a call to [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis).

## Return value

**DxgkDdiDestroyMemoryBasis** returns STATUS_SUCCESS if the memory basis was successfully destroyed. Otherwise, it returns an NTSTATUS error code. See Remarks.

## Remarks

*Dxgkrnl* interprets any returned NTSTATUS that isn't STATUS_SUCCESS as a catastrophic error notification return. There should be no correct-functioning path to return anything but success from this function, as it should be an assumed invariant that the supplied handle is one that was created and has not yet been destroyed. If KMD detects bad input, a returned error code lets *Dxgkrnl* assign the invariant failure to the OS kernel instead of a driver crash.

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)