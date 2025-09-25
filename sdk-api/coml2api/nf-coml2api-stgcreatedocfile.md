# StgCreateDocfile function

## Description

The **StgCreateDocfile** function creates a new compound file storage object using the COM-provided [compound file implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation) for the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface.

**Note** Applications should use the new function,
[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex), instead of
**StgCreateDocfile**, to take advantage of enhanced Structured Storage features. This function,
**StgCreateDocfile**, still exists for compatibility with Windows 2000.

## Parameters

### `pwcsName` [in]

A pointer to a null-terminated Unicode string name for the compound file being created. It is passed uninterpreted to the file system. This can be a relative name or **NULL**. If **NULL**, a temporary compound file is allocated with a unique name.

### `grfMode` [in]

Specifies the access mode to use when opening the new storage object. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). If the caller specifies transacted mode together with STGM_CREATE or STGM_CONVERT, the overwrite or conversion takes place when the commit operation is called for the root storage. If [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) is not called for the root storage object, previous contents of the file will be restored. STGM_CREATE and STGM_CONVERT cannot be combined with the STGM_NOSNAPSHOT flag, because a snapshot copy is required when a file is overwritten or converted in the transacted mode.

### `reserved` [in]

Reserved for future use; must be zero.

### `ppstgOpen` [out]

A pointer to the location of the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the new storage object.

## Return value

**StgCreateDocfile** can also return any file system errors or system errors wrapped in an **HRESULT**. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

The
**StgCreateDocfile** function creates a new storage object using the COM-provided, compound-file implementation for the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface. The name of the open compound file can be retrieved by calling the
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat) method.

**StgCreateDocfile** creates the file if it does not exist. If it does exist, the use of the STGM_CREATE, STGM_CONVERT, and STGM_FAILIFTHERE flags in the *grfMode* parameter indicate how to proceed. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

If the compound file is opened in transacted mode (the *grfMode* parameter specifies STGM_TRANSACTED) and a file with this name already exists, the existing file is not altered until all outstanding changes are committed. If the calling process lacks write access to the existing file (because of access control in the file system), the *grfMode* parameter can only specify STGM_READ and not STGM_WRITE or STGM_READWRITE. The resulting new open compound file can still be written to, but a subsequent commit operation will fail (in transacted mode, write permissions are enforced at commit time).

Specifying STGM_SIMPLE provides a much faster implementation of a compound file object in a limited, but frequently used case. This can be used by applications that require a compound-file implementation with multiple streams and no storages. The simple mode does not support all of the methods on
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage). For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

If the *grfMode* parameter specifies STGM_TRANSACTED and no file yet exists with the name specified by the *pwcsName* parameter, the file is created immediately. In an access-controlled file system, the caller must have write permissions in the file system directory in which the compound file is created. If STGM_TRANSACTED is not specified, and STGM_CREATE is specified, an existing file with the same name is destroyed before the new file is created.

**StgCreateDocfile** can be used to create a temporary compound file by passing a **NULL** value for the *pwcsName* parameter. However, these files are temporary only in the sense that they have a system-provided unique name — likely one that is meaningless to the user. The caller is responsible for deleting the temporary file when finished with it, unless STGM_DELETEONRELEASE was specified for the *grfMode* parameter.

## See also

[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants)

[StgCreateDocFileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes)

[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex)