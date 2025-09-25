# RtlUlonglongByteSwap macro

## Description

The **RtlUlonglongByteSwap** routine reverses the ordering of the eight bytes in a 64-bit unsigned integer value.

## Parameters

### `Source`

A ULONGLONG value to convert to a byte-swapped version.

## Return value

The byte-swapped version of the input parameter value.

## Remarks

For example, if the *Source* parameter value is 0x0123456789abcdef, the routine returns 0xefcdab8967452301.

A typical use of this routine is to convert a ULONGLONG value from little-endian byte format to big-endian byte format, and vice versa.

To reverse the ordering of bytes in a USHORT value, use the [RtlUshortByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlushortbyteswap) routine. To reverse ordering of bytes in a ULONG value, use the [RtlUlongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulongbyteswap) routine.

## See also

[RtlUlongByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlulongbyteswap)

[RtlUshortByteSwap](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlushortbyteswap)