# IDataObject::DUnadvise

## Description

Destroys a notification connection that had been previously set up.

## Parameters

### `dwConnection` [in]

A token that specifies the connection to be removed. Use the value returned by [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) when the connection was originally established.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOCONNECTION** | The specified value for *dwConnection* is not a valid connection. |
| **OLE_E_ADVISENOTSUPPORTED** | This [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) implementation does not support notification. |

## Remarks

This methods destroys a notification created with a call to the [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) method.

If the advisory connection being deleted was initially set up by delegating the [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) call to [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise), you must delegate this call to [IDataAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-unadvise) to delete it.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)