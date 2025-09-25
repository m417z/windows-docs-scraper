# GetSystemDpiForProcess function

## Description

Retrieves the system DPI associated with a given process. This is useful for avoiding compatibility issues that arise from sharing DPI-sensitive information between multiple system-aware processes with different system DPI values.

## Parameters

### `hProcess`

The handle for the process to examine. If this value is null, this API behaves identically to [GetDpiForSystem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdpiforsystem).

## Return value

The process's system DPI value.

## Remarks

The return value will be dependent based upon the process passed as a parameter. If the specified process has a [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) value of **DPI_AWARENESS_UNAWARE**, the return value will be 96. That is because the current context always assumes a DPI of 96. For any other **DPI_AWARENESS** value, the return value will be the actual system DPI of the given process.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)

[GetDpiForSystem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdpiforsystem)