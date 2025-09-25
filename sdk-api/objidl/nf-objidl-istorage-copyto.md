# IStorage::CopyTo

## Description

The **CopyTo** method copies the entire contents of an open storage object to another storage object.

## Parameters

### `ciidExclude` [in]

The number of elements in the array pointed to by *rgiidExclude*. If *rgiidExclude* is **NULL**, then *ciidExclude* is ignored.

### `rgiidExclude` [in]

An array of interface identifiers (IIDs) that either the caller knows about and does not want copied or that the storage object does not support, but whose state the caller will later explicitly copy. The array can include
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage), indicating that only stream objects are to be copied, and
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), indicating that only storage objects are to be copied. An array length of zero indicates that only the state exposed by the
**IStorage** object is to be copied; all other interfaces on the object are to be ignored. Passing **NULL** indicates that all interfaces on the object are to be copied.

### `snbExclude` [in]

A string name block (refer to
[SNB](https://learn.microsoft.com/windows/desktop/Stg/snb)) that specifies a block of storage or stream objects that are not to be copied to the destination. These elements are not created at the destination. If **IID_IStorage** is in the *rgiidExclude* array, this parameter is ignored. This parameter may be **NULL**.

### `pstgDest` [in]

A pointer to the open storage object into which this storage object is to be copied. The destination storage object can be a different implementation of the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface from the source storage object. Thus, **IStorage::CopyTo** can use only publicly available methods of the destination storage object. If *pstgDest* is open in transacted mode, it can be reverted by calling its
[IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert) method.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The storage object was successfully copied.|
|E_PENDING | Asynchronous Storage only: Part or all of the data to be copied is currently unavailable. |
|STG_E_ACCESSDENIED | The destination storage object is a child of the source storage object.|
|STG_E_INSUFFICIENTMEMORY | The copy was not completed due to a lack of memory.|
|STG_E_INVALIDPOINTER | The pointer specified for the storage object was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_TOOMANYOPENFILES | The copy was not completed because there are too many open files.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_MEDIUMFULL | The copy was not completed because the storage medium is full.|

## Remarks

This method merges elements contained in the source storage object with those already present in the destination. The layout of the destination storage object may differ from the source storage object.

The copy process is recursive, invoking **IStorage::CopyTo** and
[IStream::CopyTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-copyto) on the elements nested inside the source.

When copying a stream on top of an existing stream with the same name, the existing stream is first removed and then replaced with the source stream. When copying a storage on top of an existing storage with the same name, the existing storage is not removed. As a result, after the copy operation, the destination
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) contains older elements, unless they were replaced by newer ones with the same names.

A storage object may expose interfaces other than
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage), including
[IRootStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irootstorage),
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage), or
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage). The *rgiidExclude* parameter permits the exclusion of any or all of these additional interfaces from the copy operation.

A caller with a newer or more efficient copy of an existing substorage or stream object may want to exclude the current versions of these objects from the copy operation. The *snbExclude* and *rgiidExclude* parameters provide two ways of excluding a storage objects existing storages or streams.

### Note to Callers

The most common way to use the **IStorage::CopyTo** method is to copy everything from the source to the destination, as in most full-save and save-as operations.

The following example code shows how to copy everything from the source storage object to the destination storage object.

```cpp
pstg->CopyTo(0, Null, Null, pstgDest)
```

**Note** To compact a document file, call **CopyTo** on the root storage object and copy to a new storage object.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::MoveElementTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-moveelementto)

[IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert)