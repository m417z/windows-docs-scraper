## Description

Returns the dots per inch (dpi) value for the specified window.

## Parameters

### `hwnd` [in]

The window that you want to get information about.

## Return value

The DPI for the window, which depends on the [DPI_AWARENESS](https://learn.microsoft.com/windows/win32/api/windef/ne-windef-dpi_awareness) of the window. See the **Remarks** section for more information. An invalid *hwnd* value will result in a return value of 0.

## Remarks

The following table indicates the return value of **GetDpiForWindow** based on the [DPI_AWARENESS](https://learn.microsoft.com/windows/win32/api/windef/ne-windef-dpi_awareness) of the provided *hwnd*.

| DPI_AWARENESS | Return value |
| --- | --- |
| DPI_AWARENESS_UNAWARE | The base value of DPI is which is set to 96 (defined as `USER_DEFAULT_SCREEN_DPI`) |
| DPI_AWARENESS_SYSTEM_AWARE | The system DPI. |
| DPI_AWARENESS_PER_MONITOR_AWARE | The DPI of the monitor where the window is located. |

## Examples

See [Create a simple Direct2D application](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-quickstart).

## See also

* [DPI_AWARENESS](https://learn.microsoft.com/windows/win32/api/windef/ne-windef-dpi_awareness)
* [Create a simple Direct2D application](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-quickstart)