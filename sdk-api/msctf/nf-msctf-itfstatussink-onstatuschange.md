# ITfStatusSink::OnStatusChange

## Description

Receives a notification when one of the dynamic flags of the TF_STATUS structure changes.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface whose status has changed.

### `dwFlags` [in]

Indicates that one of the dynamic flags changed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method receives a callback when one of the flags of the **dwDynamicFlags** member of the **TF_STATUS** structure changes value. To obtain the changed flag(s), use the [ITfContext::GetStatus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getstatus) method.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfContext::GetStatus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontext-getstatus)

[ITfStatusSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfstatussink)

[TF_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms629192(v=vs.85))