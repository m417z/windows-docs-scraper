# GetAwarenessFromDpiAwarenessContext function

## Description

Retrieves the [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness) value from a **DPI_AWARENESS_CONTEXT**.

## Parameters

### `value` [in]

The **DPI_AWARENESS_CONTEXT** you want to examine.

## Return value

The [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness). If the provided *value* is **null** or invalid, this method will return **DPI_AWARENESS_INVALID**.

## Remarks

A [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) contains multiple pieces of information. For example, it includes both the current and the inherited [DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness). This method retrieves the **DPI_AWARENESS** from the structure.

## See also

[DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/windef/ne-windef-dpi_awareness)