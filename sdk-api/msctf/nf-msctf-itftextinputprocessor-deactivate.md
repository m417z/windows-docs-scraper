# ITfTextInputProcessor::Deactivate

## Description

Deactivates a text service when a user session ends.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TSF calls this method immediately before releasing its final reference to a text service. This provides the opportunity to perform operations necessary to shut down the text service.

This method usually unadvises sinks for events that involve the text service. It can also close any user interface elements of the text service.

Before this method returns, it must release all references to the *ptim* parameter passed to the text service by the [ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate) method.

## See also

[ITfTextInputProcessor](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftextinputprocessor)

[ITfTextInputProcessor::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-activate)