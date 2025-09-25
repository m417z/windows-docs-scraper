# CoRegisterMessageFilter function

## Description

Registers with OLE the instance of an [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface, which is to be used for handling concurrency issues on the current thread. Only one message filter can be registered for each thread. Threads in multithreaded apartments cannot have message filters.

## Parameters

### `lpMessageFilter` [in, optional]

A pointer to the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface on the message filter. This message filter should be registered on the current thread, replacing the previous message filter (if any). This parameter can be **NULL**, indicating that no message filter should be registered on the current thread.

Note that this function calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the interface pointer to the message filter.

### `lplpMessageFilter` [out, optional]

Address of the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter)* pointer variable that receives the interface pointer to the previously registered message filter. If there was no previously registered message filter for the current thread, the value of **lplpMessageFilter* is **NULL**.

## Return value

If the instance was registered or revoked successfully, the return value is S_OK; otherwise, it is S_FALSE.

## Remarks

To revoke the registered message filter, pass the previous message filter (possibly **NULL**) as the *lpMessageFilter* parameter to **CoRegisterMessageFilter**.

## See also

[IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter)