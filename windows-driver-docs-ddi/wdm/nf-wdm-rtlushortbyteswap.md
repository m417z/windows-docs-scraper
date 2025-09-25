# RtlUshortByteSwap macro

## Description

The **RtlUshortByteSwap** routine reverses the ordering of the two bytes in a 16-bit unsigned integer value.

## Parameters

### `Source` [in]

A USHORT value to convert to a byte-swapped version.

## Return value

The byte-swapped version of the input parameter value.

## Remarks

For example, if the *Source* parameter value is 0x1234, the routine returns 0x3412.

A typical use of this routine is to convert a USHORT value from little-endian byte format to big-endian byte format, and vice versa.

Use this routine instead of **ntohs** or **htons**.

To reverse the ordering of bytes in a ULONG value, use the [RtlUlongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulongbyteswap) routine. To reverse ordering of bytes in a ULONGLONG value, use the [RtlUlonglongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulonglongbyteswap) routine.

## See also

[RtlUlongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulongbyteswap)

[RtlUlonglongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulonglongbyteswap)