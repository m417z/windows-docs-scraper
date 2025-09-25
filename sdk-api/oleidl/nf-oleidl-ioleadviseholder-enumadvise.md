# IOleAdviseHolder::EnumAdvise

## Description

Creates an enumerator that can be used to enumerate the advisory connections currently established for an object.

## Parameters

### `ppenumAdvise` [out]

A pointer to an [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) pointer variable that receives the interface pointer to the new enumerator. If this parameter is **NULL**, there are presently no advisory connections on the object, or an error occurred. The advise holder is responsible for incrementing the reference count on the **IEnumSTATDATA** pointer this method supplies. It is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is finished with the pointer.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The enumeration operation has failed. |
| **E_NOTIMPL** | [IOleAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-enumadvise) is not implemented. |

## Remarks

**IOleAdviseHolder::EnumAdvise** creates an enumerator that can be used to enumerate an object's established advisory connections. The method supplies a pointer to the [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) interface on this enumerator. Advisory connection information for each connection is stored in the [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) structure, and the enumerator must be able to enumerate these structures.

For this method, the only relevant structure members are **pAdvise** and **dwConnection**. Other members contain data advisory information. When you call the enumeration methods, and while an enumeration is in progress, the effect of registering or revoking advisory connections on what is to be enumerated is undefined.

## See also

[IDataAdviseHolder::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-enumadvise)

[IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder)

[IOleAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-advise)

[IOleAdviseHolder::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleadviseholder-unadvise)

[IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise)

[STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata)