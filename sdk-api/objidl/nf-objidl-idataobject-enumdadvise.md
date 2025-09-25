# IDataObject::EnumDAdvise

## Description

Creates an object that can be used to enumerate the current advisory connections.

## Parameters

### `ppenumAdvise` [out]

A pointer to an [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) pointer variable that receives the interface pointer to the new enumerator object. If the implementation sets **ppenumAdvise* to **NULL**, there are no connections to advise sinks at this time.

## Return value

This method returns S_OK if the enumerator object is successfully instantiated or there are no connections. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory is available for the operation. |
| **OLE_E_ADVISENOTSUPPORTED** | Advisory notifications are not supported by this object. |

## Remarks

The enumerator object created by this method implements the [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) interface. **IEnumSTATDATA** permits the enumeration of the data stored in an array of [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) structures. Each of these structures provides information on a single advisory connection, and includes [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) and [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf) information, as well as the pointer to the advise sink and the token representing the connection.

### Notes to Callers

It is recommended that you use the OLE data advise holder object to handle advisory connections. With the pointer obtained through a call to [CreateDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createdataadviseholder), implementing **IDataObject::EnumDAdvise** becomes a simple matter of delegating the call to [IDataAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-enumadvise). This creates the enumerator and supplies the pointer to the OLE implementation of [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata). At that point, you can call its methods to enumerate the current advisory connections.

## See also

[IDataAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-enumadvise)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata)