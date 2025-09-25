# IStorage::CreateStream

## Description

The **CreateStream** method
creates and opens a stream object with the specified name contained in this storage object. All elements within a storage objects, both streams and other storage objects, are kept in the same name space.

## Parameters

### `pwcsName` [in]

A pointer to a wide character null-terminated Unicode string that contains the name of the newly created stream. The name can be used later to open or reopen the stream. The name must not exceed 31 characters in length, not including the string terminator. The 000 through 01f characters, serving as the first character of the stream/storage name, are reserved for use by OLE. This is a compound file restriction, not a structured storage restriction.

### `grfMode` [in]

Specifies the access mode to use when opening the newly created stream. For more information and descriptions of the possible values, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

### `reserved1` [in]

Reserved for future use; must be zero.

### `reserved2` [in]

Reserved for future use; must be zero.

### `ppstm` [out]

On return, pointer to the location of the new
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer. This is only valid if the operation is successful. When an error occurs, this parameter is set to **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The new stream was successfully created.|
|E_PENDING | Asynchronous Storage only: Part or all of the necessary data is currently unavailable. |
|STG_E_ACCESSDENIED | Not enough permissions to create stream.|
|STG_E_FILEALREADYEXISTS | The name specified for the stream already exists in the storage object and the *grfMode* parameter includes the value STGM_FAILIFTHERE.|
|STG_E_INSUFFICIENTMEMORY | The stream was not created due to a lack of memory.|
|STG_E_INVALIDFLAG | The value specified for the *grfMode* parameter is not a valid **STGM** constants value.|
|STG_E_INVALIDFUNCTION | The specified combination of flags in the *grfMode* parameter is not supported; for example, when this method is called without the STGM_SHARE_EXCLUSIVE flag.|
|STG_E_INVALIDNAME | Invalid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the stream object was invalid.|
|STG_E_INVALIDPARAMETER | One of the parameters was invalid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The stream was not created because there are too many open files.|

## Remarks

If a stream with the name specified in the *pwcsName* parameter already exists and the *grfMode* parameter includes the STGM_CREATE flag, the existing stream is replaced by a newly created one. Both the destruction of the old stream and the creation of the new stream object are subject to the transaction mode on the parent storage object.

The COM-provided compound file implementation of the **IStorage::CreateStream** method does not support the following behaviors:

* The STGM_DELETEONRELEASE flag is not supported.
* Transacted mode (STGM_TRANSACTED) is not supported for stream objects.
* Opening the same stream more than once from the same storage is not supported. The STGM_SHARE_EXCLUSIVE sharing-mode flag must be specified in the *grfMode* parameter.

If the stream already exists and *grfMode* is set to STGM_FAILIFTHERE, this method fails with the return value STG_E_FILEALREADYEXISTS.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)