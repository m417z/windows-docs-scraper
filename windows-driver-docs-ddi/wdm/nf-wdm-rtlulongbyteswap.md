# RtlUlongByteSwap macro

## Description

The **RtlUlongByteSwap** routine reverses the ordering of the four bytes in a 32-bit unsigned integer value.

## Parameters

### `Source` [in]

A ULONG value to convert to a byte-swapped version.

## Return value

The byte-swapped version of the Source input parameter value.

## Remarks

For example, if the *Source* parameter value is 0x12345678, the routine returns 0x78563412.

A typical use of this routine is to convert a ULONG value from little-endian byte format to big-endian byte format, and vice versa.

Use this routine instead of **ntohl** or **htonl**.

To reverse the ordering of bytes in a USHORT value, use the [RtlUshortByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlushortbyteswap) routine. To reverse ordering of bytes in a ULONGLONG value, use the [RtlUlonglongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulonglongbyteswap) routine.

## See also

[RtlUlonglongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulonglongbyteswap)

[RtlUshortByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlushortbyteswap)