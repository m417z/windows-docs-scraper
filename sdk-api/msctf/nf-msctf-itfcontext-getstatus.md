# ITfContext::GetStatus

## Description

Obtains the document status.

## Parameters

### `pdcs` [out]

Pointer to a [TF_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms629192(v=vs.85)) structure that receives the document status data.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context is not on a document stack. |
| **E_INVALIDARG** | *pdcs* is invalid. |

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext), [TF_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms629192(v=vs.85))