# ITfContext::GetActiveView

## Description

Obtains the active view for the context.

## Parameters

### `ppView` [out]

Pointer to an [ITfContextView](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextview) interface pointer that receives a reference to the active view.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [ITfContextView interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextview)