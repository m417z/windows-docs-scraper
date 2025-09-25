# IDataAdviseHolder::Unadvise

## Description

Removes a connection between a data object and an advisory sink that was set up through a previous call to [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise). This method is typically called in the implementation of [IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise).

## Parameters

### `dwConnection` [in]

A token that specifies the connection to be removed. This value was returned by [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise) when the connection was originally established.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOCONNECTION** | The *dwConnection* parameter does not specify a valid connection. |

## See also

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)

[IDataObject::DUnadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dunadvise)