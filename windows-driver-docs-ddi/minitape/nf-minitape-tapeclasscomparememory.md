# TapeClassCompareMemory function

## Description

The **TapeClassCompareMemory** routine compares two memory buffers and returns the number of bytes that are equivalent.

## Parameters

### `Source1` [in, out]

Pointer to the first buffer to be compared.

### `Source2` [in, out]

Pointer to the second buffer to be compared.

### `Length` [in]

Specifies the number of bytes to be compared.

## Return value

**TapeClassCompareMemory** returns the number of bytes that are equivalent.

## Remarks

A tape miniclass driver uses **TapeClassCompareMemory** to compare memory in a portable way. For example, a miniclass driver uses **TapeClassCompareMemory** in its TapeMiniVerifyInquiry routine to determine whether a given product ID matches one of the devices the driver supports.

## See also

[TapeMiniVerifyInquiry](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_verify_inquiry_routine)