# RtlCompareMemory function

## Description

The **RtlCompareMemory** routine compares two blocks of memory and returns the number of bytes that match until the first difference.

## Parameters

### `Source1` [in]

A pointer to the first block of memory.

### `Source2` [in]

A pointer to the second block of memory.

### `Length` [in]

The number of bytes to compare.

## Return value

**RtlCompareMemory** returns the number of bytes in the two blocks that match. If all bytes match up to the specified *Length* value, the *Length* value is returned.

## Remarks

The routine starts by comparing the first byte in the first block to the first byte in the second block, and continues to compare successive bytes in the two blocks while the bytes match. The routine stops comparing bytes when it encounters the first pair of bytes that are not equal, or when the number of matching bytes equals the *Length* parameter value, whichever occurs first.

Callers of **RtlCompareMemory** can be running at any IRQL if both blocks of memory are resident.

## See also

[**RtlCompareDeviceMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparedevicememory)