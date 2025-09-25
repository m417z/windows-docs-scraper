# IStorage::OpenStream

## Description

The **OpenStream** method
opens an existing stream object within this storage object in the specified access mode.

## Parameters

### `pwcsName` [in]

A pointer to a wide character null-terminated Unicode string that contains the name of the stream to open. The 000 through 01f characters, serving as the first character of the stream/storage name, are reserved for use by OLE. This is a compound file restriction, not a structured storage restriction.

### `reserved1` [in]

Reserved for future use; must be **NULL**.

### `grfMode` [in]

Specifies the access mode to be assigned to the open stream. For more information and descriptions of possible values, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). Other modes you choose must at least specify STGM_SHARE_EXCLUSIVE when calling this method in the compound file implementation.

### `reserved2` [in]

Reserved for future use; must be zero.

### `ppstm` [out]

A pointer to
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer variable that receives the interface pointer to the newly opened stream object. If an error occurs, **ppstm* must be set to **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The stream was successfully opened.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream data is currently unavailable. |
|STG_E_ACCESSDENIED | Not enough permissions to open stream.|
|STG_E_FILENOTFOUND | The stream with specified name does not exist.|
|STG_E_INSUFFICIENTMEMORY | The stream was not opened due to a lack of memory.|
|STG_E_INVALIDFLAG | The value specified for the *grfMode* parameter is not a valid **STGM** constants value.|
|STG_E_INVALIDFUNCTION | The specified combination of flags in the *grfMode* parameter is not supported; for example, when this method is called without the STGM_SHARE_EXCLUSIVE flag.|
|STG_E_INVALIDNAME | Invalid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the stream object was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The stream was not opened because there are too many open files.|

## Remarks

**IStorage::OpenStream** opens an existing stream object within this storage object in the access mode specified in *grfMode*. There are restrictions on the permissions that can be given in *grfMode*. For example, the permissions on this storage object restrict the permissions on its streams. In general, access restrictions on streams need to be stricter than those on their parent storages. Compound-file streams must be opened with STGM_SHARE_EXCLUSIVE.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)