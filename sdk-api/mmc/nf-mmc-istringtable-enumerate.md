# IStringTable::Enumerate

## Description

The **IStringTable::Enumerate** method supplies a pointer to an [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface on an enumerator that can return the strings in a snap-in's string table. The [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) interface is a standard COM interface.

## Parameters

### `ppEnum` [out]

The address of [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)* pointer variable that receives the interface pointer to the enumerator. If an error occurs, **ppEnum* is set to **NULL**. If **ppEnum*  is non-**NULL**, MMC's implementation of **IEnumString** calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the **ppEnum*. The snap-in must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the interface is no longer required.

## Return value

This method can return one of these values.

## Remarks

The returned [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) enumeration represents a snapshot of the collection of strings in the underlying string table the time that the enumeration was retrieved. Neither [IEnumString::Reset](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ienumstring-reset), nor IEnumString::Clone takes a new snapshot of the collection.

The implementation of [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring) uses the default OLE task memory allocator to allocate memory for the strings it returns.

## See also

[IStringTable](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-istringtable)

[IStringTable::FindString](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-istringtable-findstring)