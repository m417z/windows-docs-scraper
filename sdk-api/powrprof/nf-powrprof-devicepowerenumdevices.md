# DevicePowerEnumDevices function

## Description

Enumerates devices on the system that meet the specified criteria.

## Parameters

### `QueryIndex` [in]

The index of the requested device. For initial calls, this value should be zero.

### `QueryInterpretationFlags` [in]

The criteria applied to the search results.

| Value | Meaning |
| --- | --- |
| **DEVICEPOWER_HARDWAREID**<br><br>0x80000000 | Return a hardware ID string rather than friendly device name. |
| **DEVICEPOWER_FILTER_DEVICES_PRESENT**<br><br>0x20000000 | Ignore devices not currently present in the system. |
| **DEVICEPOWER_AND_OPERATION**<br><br>0x40000000 | Perform an AND operation on *QueryFlags*. |
| **DEVICEPOWER_FILTER_WAKEENABLED**<br><br>0x08000000 | Check whether the device is currently enabled to wake the system from a sleep state. |
| **DEVICEPOWER_FILTER_ON_NAME**<br><br>0x02000000 | Find a device whose name matches the string passed in *pReturnBuffer* and check its capabilities against *QueryFlags*. |

### `QueryFlags` [in]

The query criteria.

| Value | Meaning |
| --- | --- |
| **PDCAP_D0_SUPPORTED**<br><br>0x00000001 | The device supports system power state D0. |
| **PDCAP_D1_SUPPORTED**<br><br>0x00000002 | The device supports system power state D1. |
| **PDCAP_D2_SUPPORTED**<br><br>0x00000004 | The device supports system power state D2. |
| **PDCAP_D3_SUPPORTED**<br><br>0x00000008 | The device supports system power state D3. |
| **PDCAP_S0_SUPPORTED**<br><br>0x00010000 | The device supports system sleep state S0. |
| **PDCAP_S1_SUPPORTED**<br><br>0x00020000 | The device supports system sleep state S1. |
| **PDCAP_S2_SUPPORTED**<br><br>0x00040000 | The device supports system sleep state S2. |
| **PDCAP_S3_SUPPORTED**<br><br>0x00080000 | The device supports system sleep state S3. |
| **PDCAP_S4_SUPPORTED**<br><br>0x01000000 | The device supports system sleep state S4. |
| **PDCAP_S5_SUPPORTED**<br><br>0x02000000 | The device supports system sleep state S5. |
| **PDCAP_WAKE_FROM_D0_SUPPORTED**<br><br>0x00000010 | The device supports waking from system power state D0. |
| **PDCAP_WAKE_FROM_D1_SUPPORTED**<br><br>0x00000020 | The device supports waking from system power state D1. |
| **PDCAP_WAKE_FROM_D2_SUPPORTED**<br><br>0x00000040 | The device supports waking from system power state D2. |
| **PDCAP_WAKE_FROM_D3_SUPPORTED**<br><br>0x00000080 | The device supports waking from system power state D3. |
| **PDCAP_WAKE_FROM_S0_SUPPORTED**<br><br>0x00100000 | The device supports waking from system sleep state S0. |
| **PDCAP_WAKE_FROM_S1_SUPPORTED**<br><br>0x00200000 | The device supports waking from system sleep state S1. |
| **PDCAP_WAKE_FROM_S2_SUPPORTED**<br><br>0x00400000 | The device supports waking from system sleep state S2. |
| **PDCAP_WAKE_FROM_S3_SUPPORTED**<br><br>0x00800000 | The device supports waking from system sleep state S3. |
| **PDCAP_WARM_EJECT_SUPPORTED**<br><br>0x00000100 | The device supports warm eject. |

### `pReturnBuffer` [out, optional]

Pointer to a buffer that receives the requested information.

### `pBufferSize` [in, out]

The size, in bytes, of the return buffer.

**Note** If *pReturnBuffer* is **NULL**,
*pBufferSize* will be filled with the size needed to return the data.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The values of the *QueryFlags* parameter may be combined to query for devices that
support two or more criteria. For example; if **PDCAP_D3_SUPPORTED** |
**PDCAP_D1_SUPPORTED** is passed as the *QueryFlags* parameter, the
function will query for devices that support either D3 or D1.

*QueryFlags* also may be combined with
*QueryInterpretationFlags* set to **DEVICEPOWER_AND_OPERATION** to
produce a query of devices that support all of the requested criteria. For example; if
**PDCAP_D3_SUPPORTED** | **PDCAP_D1_SUPPORTED** is passed as the
*QueryFlags* parameter and **DEVICEPOWER_AND_OPERATION** is passed
as the *QueryInterpretationFlags* parameter, the function will query devices that support
both D3 and D1.

#### Examples

For an example that uses this function, see
[Using the Device Power API](https://learn.microsoft.com/windows/desktop/Power/using-the-device-power-api).

## See also

[Device Power Management](https://learn.microsoft.com/windows/desktop/Power/device-power-management)