## Description

The **StorPortGetProcessorCount** routine returns the number of active logical processors in the system.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the hardware device extension for the host bus adapter (HBA).

### `ProcessorCount`

[out] Pointer to the location in which the routine returns the number of active logical processors in the system.

## Return value

**StorPortGetProcessorCount** returns one of the following STOR_STATUS codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid. |

## Remarks

For information about active logical processors, see [**KeQueryActiveProcessorCountEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryactiveprocessorcountex).

## See also

[**StorPortGetCurrentProcessorNumber**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetcurrentprocessornumber)