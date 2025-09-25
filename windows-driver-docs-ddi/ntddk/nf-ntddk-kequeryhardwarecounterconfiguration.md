## Description

The **KeQueryHardwareCounterConfiguration** routine queries the operating system for the list of hardware counters to use for thread profiling.

## Parameters

### `CounterArray` [out]

A pointer to a caller-allocated buffer into which the routine writes an array of elements of type [**HARDWARE_COUNTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_hardware_counter). Each array element is a structure that contains information about a hardware counter. The array contains one element for each hardware counter that is assigned to thread profiling. If the routine fails, it writes nothing to this buffer.

### `MaximumCount` [in]

Specifies the maximum number of elements that the routine can write to the buffer that is pointed to by the *CounterArray* parameter. The size of the caller-allocated buffer must be at least *MaximumCount* * **sizeof**(**HARDWARE_COUNTER**) bytes.

### `Count` [out]

A pointer to a location into which the routine writes the number of array elements that it has written to the buffer that is pointed to by the *CounterArray* parameter. If the buffer length that is specified by *MaximumCount* is not large enough to contain the entire array, the routine writes the required length to **Count* and returns STATUS_BUFFER_TOO_SMALL.

## Return value

**KeQueryHardwareCounterConfiguration** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|--|--|
| **STATUS_BUFFER_TOO_SMALL** | The *MaximumCount* parameter specifies a buffer length that is not large enough to contain the counter configuration information. |
| **STATUS_NOT_IMPLEMENTED** | This routine is not implemented for the processor architecture that the caller is running on. |

## Remarks

In Windows 7, this routine is implemented only for the x86-based, x64-based, and Itanium-based architectures. If the caller is running on a processor architecture that is not supported, the routine returns STATUS_NOT_IMPLEMENTED.

To set the hardware counter configuration to use for thread profiling, call the [KeSetHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesethardwarecounterconfiguration) routine.

## See also

[**HARDWARE_COUNTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_hardware_counter)

[KeSetHardwareCounterConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesethardwarecounterconfiguration)