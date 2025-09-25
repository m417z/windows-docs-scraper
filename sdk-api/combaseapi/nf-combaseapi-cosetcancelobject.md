# CoSetCancelObject function

## Description

Sets (registers) or resets (unregisters) a cancel object for use during subsequent cancel operations on the current thread.

## Parameters

### `pUnk` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the cancel object to be set or reset on the current thread. If this parameter is **NULL**, the topmost cancel object is reset.

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The cancel object was successfully set or reset. |
| **E_ACCESSDENIED** | The cancel object cannot be set or reset at this time because of a block on cancel operations. |

## Remarks

For objects that support standard marshaling, the proxy object begins marshaling a method call by calling **CoSetCancelObject** to register a cancel object for the current thread.

**CoSetCancelObject** calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls) on the cancel object. If the cancel object does not implement **ICancelMethodCalls**, **CoSetCancelObject** fails with E_NOINTERFACE. To disable cancel operations on a custom-marshaled interface, the implementation of [ICancelMethodCalls::Cancel](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icancelmethodcalls-cancel) should do nothing but return E_NOTIMPL, E_FAIL, or some other appropriate value.

**CoSetCancelObject** calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on objects that it registers and [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on objects that it unregisters.

**CoSetCancelObject** does not set or reset cancel objects for asynchronous methods.

## See also

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)