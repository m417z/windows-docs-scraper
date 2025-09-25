# StorPortGetCurrentProcessorNumber function

## Description

The **StorPortGetCurrentProcessorNumber** routine retrieves the current processor number from the kernel.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `ProcNumber` [out]

Pointer to a [**PROCESSOR_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that holds the return data.

## Return value

The **StorPortGetCurrentProcessorNumber** routine returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid, for example, if **ProcNumber** is set to **NULL**. |

## See also

[**PROCESSOR_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)

[**StorPortGetProcessorCount**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetprocessorcount)