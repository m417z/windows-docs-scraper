# GetDpiForSystem function

## Description

Returns the system DPI.

## Return value

The system DPI value.

## Remarks

The return value will be dependent based upon the calling context. If the current thread has a [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) value of **DPI_AWARENESS_UNAWARE**, the return value will be 96. That is because the current context always assumes a DPI of 96. For any other **DPI_AWARENESS** value, the return value will be the actual system DPI.

You should not cache the system DPI, but should use **GetDpiForSystem** whenever you need the system DPI value.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)