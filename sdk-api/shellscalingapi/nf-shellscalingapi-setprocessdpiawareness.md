# SetProcessDpiAwareness function

## Description

Sets the process-default DPI awareness level. This is equivalent to calling [SetProcessDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setprocessdpiawarenesscontext) with the corresponding [DPI_AWARENESS_CONTEXT](https://learn.microsoft.com/windows/desktop/hidpi/dpi-awareness-context) value.

> [!NOTE]
> It is recommended that you set the process-default DPI awareness via application manifest, not an API call. See [Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process) for more information. Setting the process-default DPI awareness via API call can lead to unexpected application behavior.

## Parameters

### `value` [in]

The DPI awareness value to set. Possible values are from the [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) enumeration.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The DPI awareness for the app was set successfully. |
| **E_INVALIDARG** | The value passed in is not valid. |
| **E_ACCESSDENIED** | The DPI awareness is already set, either by calling this API previously or through the application (.exe) manifest. |

## Remarks

Previous versions of Windows only had one DPI awareness value for the entire application. For those applications, the recommendation was to set the DPI awareness value in the manifest as described in [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness). Under that recommendation, you were not supposed to use **SetProcessDpiAwareness** to update the DPI awareness. In fact, future calls to this API would fail after the DPI awareness was set once. Now that DPI awareness is tied to a thread rather than an application, you can use this method to update the DPI awareness. However, consider using [SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext) instead.

**Important**

For older applications, it is strongly recommended to not use **SetProcessDpiAwareness** to set the DPI awareness for your application. Instead, you should declare the DPI awareness for your application in the application manifest. See [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) for more information about the DPI awareness values and how to set them in the manifest.

You must call this API before you call any APIs that depend on the dpi awareness. This is part of the reason why it is recommended to use the application manifest rather than the **SetProcessDpiAwareness** API. Once API awareness is set for an app, any future calls to this API will fail. This is true regardless of whether you set the DPI awareness in the manifest or by using this API.

If the DPI awareness level is not set, the default value is **PROCESS_DPI_UNAWARE**.

## See also

[PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness)

[SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext)

[Setting the default DPI awareness for a process](https://learn.microsoft.com/windows/win32/hidpi/setting-the-default-dpi-awareness-for-a-process)