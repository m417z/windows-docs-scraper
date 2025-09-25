# IDataAdviseHolder::EnumAdvise

## Description

Returns an object that can be used to enumerate the current advisory connections.

## Parameters

### `ppenumAdvise` [out]

A pointer to an [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) pointer variable that receives the interface pointer to the new enumerator object. If the implementation returns **NULL** in **ppenumAdvise*, there are no connections to advise sinks at this time.

## Return value

This method returns S_OK if the enumerator object is successfully instantiated or there are no connections.

## Remarks

This method must supply a pointer to an implementation of the [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) interface. Its methods allow you to enumerate the data stored in an array of [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) structures. You get a pointer to the OLE implementation of [IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder) through a call to [CreateDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-createdataadviseholder), and then call **IDataAdviseHolder::EnumAdvise** to implement [IDataObject::EnumDAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumdadvise).

Adding more advisory connections while the enumerator object is active has an undefined effect on the enumeration that results from this method.

## See also

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)

[IDataObject::EnumDAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumdadvise)

[IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata)