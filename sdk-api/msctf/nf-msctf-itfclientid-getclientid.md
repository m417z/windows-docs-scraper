# ITfClientId::GetClientId

## Description

Obtains a client identifier for a CLSID.

## Parameters

### `rclsid` [in]

CLSID to obtain the client identifier for.

### `ptid` [out]

Pointer to a [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid) value that receives the client identifier.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

An application obtains its client identifier by calling [ITfThreadMgr::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-activate) and a text service receives its client identifier in its [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate) method. **ITfClientId::GetClientId** enables TSF objects that do not fit either of these categories to obtain their own client identifier.

## See also

[ITfClientId interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfclientid), [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itftextinputprocessor-activate), [ITfThreadMgr::Activate](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfthreadmgr-activate), [TfClientId](https://learn.microsoft.com/windows/desktop/TSF/tfclientid)