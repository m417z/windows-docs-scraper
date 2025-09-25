# IOleObject::EnumAdvise

## Description

Retrieves a pointer to an enumerator that can be used to enumerate the advisory connections registered for an object, so a container can know what to release prior to closing down.

## Parameters

### `ppenumAdvise` [out]

Address of [IEnumSTATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatdata) pointer variable that receives the interface pointer to the enumerator object. If the object does not have any advisory connections or if an error occurs, the implementation must set *ppenumAdvise* to **NULL**. Each time an object receives a successful call to **IOleObject::EnumAdvise**, it must increase the reference count on *ppenumAdvise*. It is the caller's responsibility to call Release when it is done with the *ppenumAdvise*.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | [IOleObject::EnumAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumadvise) is not implemented. |

## Remarks

The **IOleObject::EnumAdvise** method supplies an enumerator that provides a way for containers to keep track of advisory connections registered for their objects. A container normally would call this function so that it can instruct an object to release each of its advisory connections prior to closing down.

The enumerator to which you get access through **IOleObject::EnumAdvise** enumerates items of type [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata). Upon receiving the pointer, the container can then loop through **STATDATA** and call [IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise) for each enumerated connection.

The usual way to implement this function is to delegate the call to the [IOleAdviseHolder](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleadviseholder) interface. Only the **pAdvise** and **dwConnection** members of [STATDATA](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statdata) are relevant for **IOleObject::EnumAdvise**.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::Advise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-advise)

[IOleObject::Unadvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-unadvise)