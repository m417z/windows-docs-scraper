# StorPortQueryPerformanceCounter function

## Description

The current system performance counter value is queried is returned by the **StorPortQueryPerformanceCounter** routine.. The performance frequency is also returned as an optional parameter.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `PerformanceFrequency` [out, optional]

 A pointer to a large integer to receive the current system performance frequency value. This parameter is optional and can be NULL.

### `PerformanceCounter` [out]

A pointer to a large integer to receive the current system performance counter value.

## Return value

**StorPortQueryPerformanceCounter** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The performance counter value is returned in the large integer pointed to by *PerformanceCounter*. |
| **STOR_STATUS_INVALID_PARAMETER** | The *PerformanceCounter* parameter is **NULL**. |

## See also

[StorPortQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportquerysystemtime)