# ITfTextInputProcessor::Activate

## Description

Activates a text service when a user session starts.

## Parameters

### `ptim` [in]

Pointer to the [ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr) interface for the thread manager that owns the text service.

### `tid` [in]

Specifies the client identifier for the text service.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TSF calls this method after creating an instance of a text service with a call to [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance). This enables operations necessary to start the text service.

This method usually adds a reference to the thread manager for the session and advise sinks for events that involve the text service, such as change of focus, keystrokes, and window events. It also customizes the language bar for the text service.

The corresponding [ITfTextInputProcessor::Deactivate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-deactivate) method that shuts down the text service must release all references to the *ptim* parameter.

## See also

[ITfTextInputProcessor](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftextinputprocessor)

[ITfTextInputProcessor::Deactivate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftextinputprocessor-deactivate)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)