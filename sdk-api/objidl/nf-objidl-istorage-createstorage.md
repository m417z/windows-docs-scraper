# IStorage::CreateStorage

## Description

The **CreateStorage** method
creates and opens a new storage object nested within this storage object with the specified name in the specified access mode.

## Parameters

### `pwcsName` [in]

A pointer to a wide character null-terminated Unicode string that contains the name of the newly created storage object. The name can be used later to reopen the storage object. The name must not exceed 31 characters in length, not including the string terminator. The 000 through 01f characters, serving as the first character of the stream/storage name, are reserved for use by OLE. This is a compound file restriction, not a structured storage restriction.

### `grfMode` [in]

A value that specifies the access mode to use when opening the newly created storage object. For more information and a description of possible values, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

### `reserved1` [in]

Reserved for future use; must be zero.

### `reserved2` [in]

Reserved for future use; must be zero.

### `ppstg` [out]

A pointer, when successful, to the location of the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the newly created storage object. This parameter is set to **NULL** if an error occurs.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The storage object was created successfully.|
|E_PENDING | Asynchronous Storage only: Part or all of the necessary data is currently unavailable. |
|STG_E_ACCESSDENIED | Not enough permissions to create storage object.|
|STG_E_FILEALREADYEXISTS | The name specified for the storage object already exists in the storage object and the *grfMode* parameter includes the flag STGM_FAILIFTHERE.|
|STG_E_INSUFFICIENTMEMORY | The storage object was not created due to a lack of memory.|
|STG_E_INVALIDFLAG | The value specified for the *grfMode<* parameter is not a valid *STGM* constant value.|he value specified for the grfMode parameter is not a valid
|STG_E_INVALIDFUNCTION | The specified combination of flags in the *grfMode* parameter is not supported.|
|STG_E_INVALIDNAME | Not a valid value for *pwcsName*.|
|STG_E_INVALIDPOINTER | The pointer specified for the storage object was not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|
|STG_E_TOOMANYOPENFILES | The storage object was not created because there are too many open files.|
|STG_S_CONVERTED | The existing stream with the specified name was replaced with a new storage object containing a single stream called CONTENTS. The new storage object will be added.|

## Remarks

If a storage with the name specified in the *pwcsName* parameter already exists within the parent storage object, and the *grfMode* parameter includes the STGM_CREATE flag, the existing storage is replaced by the new one. If the *grfMode* parameter includes the STGM_CONVERT flag, the existing element is converted to a stream object named CONTENTS and the new storage object is created containing the CONTENTS stream object. The destruction of the old element and the creation of the new storage object are both subject to the transaction mode on the parent storage object. Be aware that you cannot use STGM_CONVERT if you are also using STGM_CREATE.

The COM-provided compound file implementation of the **IStorage::CreateStorage** method does not support the following behavior:

* The STGM_PRIORITY flag for nonroot storages.
* Opening the same storage object more than once from the same parent storage. The STGM_SHARE_EXCLUSIVE flag must be specified.
* The STGM_DELETEONRELEASE flag. If this flag is specified, the function returns STG_E_INVALIDFLAG.

If a storage object with the same name already exists and *grfMode* is set to STGM_FAILIFTHERE, this method fails with the return value STG_E_FILEALREADYEXISTS.

## See also

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::OpenStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstorage)