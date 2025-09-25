# GetProcessDpiAwareness function

## Description

Retrieves the dots per inch (dpi) awareness of the specified process.

## Parameters

### `hprocess` [in]

Handle of the process that is being queried. If this parameter is NULL, the current process is queried.

### `value` [out]

The DPI awareness of the specified process. Possible values are from the [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) enumeration.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function successfully retrieved the DPI awareness of the specified process. |
| **E_INVALIDARG** | The handle or pointer passed in is not valid. |
| **E_ACCESSDENIED** | The application does not have sufficient privileges. |

## Remarks

This function is identical to the following code:

`GetAwarenessFromDpiAwarenessContext(GetThreadDpiAwarenessContext());`

## See also

[GetAwarenessFromDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getawarenessfromdpiawarenesscontext)

[GetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddpiawarenesscontext)

[PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness)