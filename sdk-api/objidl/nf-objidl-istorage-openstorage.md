# IStorage::OpenStorage

## Description

The **OpenStorage** method
opens an existing storage object with the specified name in the specified access mode.

## Parameters

### `pwcsName` [in]

A pointer to a wide character null-terminated Unicode string that contains the name of the storage object to open. The 000 through 01f characters, serving as the first character of the stream/storage name, are reserved for use by OLE. This is a compound file restriction, not a structured storage restriction. It is ignored if *pstgPriority* is non-**NULL**.

### `pstgPriority` [in]

Must be **NULL**. A non-**NULL** value will return STG_E_INVALIDPARAMETER.

### `grfMode` [in]

Specifies the access mode to use when opening the storage object. For descriptions of the possible values, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). Other modes you choose must at least specify STGM_SHARE_EXCLUSIVE when calling this method.

### `snbExclude` [in]

Must be **NULL**. A non-**NULL** value will return STG_E_INVALIDPARAMETER.

### `reserved` [in]

Reserved for future use; must be zero.

### `ppstg` [out]

When successful, pointer to the location of an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the opened storage object. This parameter is set to **NULL** if an error occurs.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The storage object was opened successfully.|
|E_PENDING | Asynchronous Storage only: Part or all of the storage's data is currently unavailable. |
|STG_E_ACCESSDENIED | Not enough permissions to open storage object.|
|STG_E_FILENOTFOUND | The storage object with the specified name does not exist.|
|STG_E_INSUFFICIENTMEMORY | The storage object was not opened due to a lack of memory.|
|STG_E_INVALIDFLAG | The value specified for the *grfMode* parameter is not a valid **STGM** constants value.|
|STG_E_INVALIDFUNCTION | The specified combination of flags in the *grfMode* parameter is not supported.|
|STG_E_INVALIDNAME | Not a valid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the storage object was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The storage object was not created because there are too many open files.|
|STG_S_CONVERTED | The existing stream with the specified name was replaced with a new storage object containing a single stream called CONTENTS. In direct mode, the new storage is immediately written to disk. In transacted mode, the new storage is written to a temporary storage in memory and later written to disk when it is committed.|

## Remarks

If the *pstgPriority* parameter is **NULL**, it is ignored. If the *pstgPriority* parameter is not **NULL**, it is an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to a previous opening of an element of the storage object, usually one that was opened in priority mode. The storage object should be closed and reopened according to *grfMode*. When the **IStorage::OpenStorage** method returns, *pstgPriority* is no longer valid. Use the value supplied in the *ppstg* parameter.

Storage objects can be opened with STGM_DELETEONRELEASE, in which case the object is destroyed when it receives its final release. This is useful for creating temporary storage objects.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::CreateStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstorage)