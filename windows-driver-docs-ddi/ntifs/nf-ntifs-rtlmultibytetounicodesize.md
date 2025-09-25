# RtlMultiByteToUnicodeSize function

## Description

The **RtlMultiByteToUnicodeSize** routine determines the number of bytes that are required to store the Unicode translation for the specified source string. The translation is assumed to use the current system ANSI code page (ACP). The source string is not necessarily from a multibyte character set.

## Parameters

### `BytesInUnicodeString` [out]

Pointer to a caller-allocated variable that receives the number of bytes that are required to store the translated string.

### `MultiByteString` [in]

Pointer to the source string for which the Unicode length is to be calculated.

### `BytesInMultiByteString` [in]

Length, in bytes, of the source string.

## Return value

**RtlMultiByteToUnicodeSize** returns STATUS_SUCCESS.

## Remarks

**RtlMultiByteToUnicodeSize** can be called to determine how much memory to allocate, or possibly, the value to specify for *MaxBytesInUnicodeString*, before translating a multibyte string into Unicode with **RtlMultiByteToUnicodeN**. The returned value does not include space for a NULL terminator for the Unicode string.

Like **RtlMultiByteToUnicodeN**, **RtlMultiByteToUnicodeSize** supports only precomposed Unicode characters that are mapped to the current system ANSI code page installed at system boot.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlMultiByteToUnicodeN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlmultibytetounicoden)

[RtlUnicodeToMultiByteSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibytesize)