# CreateDataAdviseHolder function

## Description

Retrieves a pointer to the OLE implementation of [IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder) on the data advise holder object.

## Parameters

### `ppDAHolder` [out]

Address of an [IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder) pointer variable that receives the interface pointer to the new advise holder object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |

## Remarks

Call **CreateDataAdviseHolder** in your implementation of [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) to get a pointer to the OLE implementation of [IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder) interface. With this pointer, you can then complete the implementation of **IDataObject::DAdvise** by calling the [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise) method, which creates an advisory connection between the calling object and the data object.

## See also

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)