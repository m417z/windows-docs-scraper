# CreateAsyncBindCtx function

## Description

Creates an asynchronous bind context for use with asynchronous monikers.

## Parameters

### `reserved` [in]

This parameter is reserved and must be 0.

### `pBSCb` [in]

A pointer to the [IBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060(v=vs.85)) interface used for receiving data availability and progress notification.

### `pEFetc` [in]

A pointer to the [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interface that can be used to enumerate formats for format negotiation during binding. This parameter can be **NULL**, in which case the caller is not interested in format negotiation during binding, and the default format of the object will be bound to.

### `ppBC` [out]

Address of an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)* pointer variable that receives the interface pointer to the new bind context.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_OUTOFMEMORY** | The method ran out of memory and did not complete. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

This function automatically registers the [IBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060(v=vs.85)) and [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interfaces with the bind context. The client can specify flags from BSCO_OPTION to indicate which callback notifications the client is capable of receiving. If the client does not wish to receive certain notification, it can choose to implement those callback methods as empty function stubs (returning E_NOTIMPL), and they should not be called.

The [RegisterBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775115(v=vs.85)) function can also be used to register callback interfaces in the bind context.

## See also

[IBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060(v=vs.85))

[RegisterBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775115(v=vs.85))