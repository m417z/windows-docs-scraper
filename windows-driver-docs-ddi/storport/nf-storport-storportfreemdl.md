# StorPortFreeMdl function

## Description

The **StorPortFreeMdl** routine frees a memory descriptor list (MDL) describing non-paged pool memory.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Mdl` [in]

A pointer to the MDL to be freed.

## Return value

StorPortFreeMdl returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the MDL was freed successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer to the MDL is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |

## Remarks

A miniport driver calls the **StorPortFreeMdl** routine to free the MDL that was allocated in a previous call to [StorPortAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatemdl).

## See also

[StorPortAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatemdl)