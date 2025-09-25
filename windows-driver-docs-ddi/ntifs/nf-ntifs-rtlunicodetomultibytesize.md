# RtlUnicodeToMultiByteSize function

## Description

The **RtlUnicodeToMultiByteSize** routine determines the number of bytes that are required to store the multibyte translation for the specified Unicode string. The translation is assumed to use the current system ANSI code page (ACP).

## Parameters

### `BytesInMultiByteString` [out]

Pointer to a caller-allocated variable that receives the number of bytes required to store the translated string.

### `UnicodeString` [in]

Pointer to the Unicode string for which the multibyte length is to be calculated.

### `BytesInUnicodeString` [in]

Length, in bytes, of the source string.

## Return value

**RtlUnicodeToMultiByteSize** returns STATUS_SUCCESS.

## Remarks

**RtlUnicodeToMultiByteSize** can be called to determine how much memory to allocate, or possibly the value to specify for *MaxBytesInMultiByteString*, before translating a Unicode string to ANSI with **RtlUnicodeToMultiByteN** or **RtlUpcaseUnicodeToMultiByteN**. The returned value does not include space for a NULL terminator for the ANSI string.

Like **RtlUnicodeToMultiByteN**, **RtlUnicodeToMultiByteSize** supports only precomposed Unicode characters that are mapped to the current system ANSI code page installed at system boot.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlMultiByteToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlmultibytetounicodesize)

[RtlUnicodeToMultiByteN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetomultibyten)

[RtlUpcaseUnicodeToMultiByteN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlupcaseunicodetomultibyten)