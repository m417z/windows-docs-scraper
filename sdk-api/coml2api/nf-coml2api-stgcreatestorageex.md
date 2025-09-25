# StgCreateStorageEx function

## Description

The **StgCreateStorageEx** function
creates a new storage object using a provided implementation for the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) or
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interfaces. To open an existing file, use the
[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex) function instead.

Applications written for Windows 2000, Windows Server 2003 and Windows XP must use
**StgCreateStorageEx** rather than
[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile) to take advantage of the enhanced Windows 2000 and Windows XP Structured Storage features.

## Parameters

### `pwcsName` [in]

A pointer to the path of the file to create. It is passed uninterpreted to the file system. This can be a relative name or **NULL**. If **NULL**, a temporary file is allocated with a unique name. If non-**NULL**, the string size must not exceed MAX_PATH characters.

**Windows 2000:** Unlike the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function, you cannot exceed the MAX_PATH limit by using the "\\?\" prefix.

### `grfMode` [in]

A value that specifies the access mode to use when opening the new storage object. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). If the caller specifies transacted mode together with STGM_CREATE or STGM_CONVERT, the overwrite or conversion takes place when the commit operation is called for the root storage. If [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) is not called for the root storage object, previous contents of the file will be restored. STGM_CREATE and STGM_CONVERT cannot be combined with the STGM_NOSNAPSHOT flag, because a snapshot copy is required when a file is overwritten or converted in the transacted mode.

### `stgfmt` [in]

A value that specifies the storage file format. For more information, see the
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) enumeration.

### `grfAttrs` [in]

A value that depends on the value of the *stgfmt* parameter.

| Parameter Values | Meaning |
| --- | --- |
| **STGFMT_DOCFILE** | 0, or FILE_FLAG_NO_BUFFERING. For more information, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). If the sector size of the file, specified in *pStgOptions*, is not an integer multiple of the underlying disk's physical sector size, this operation will fail. |
| **All other values of *stgfmt*** | Must be 0. |

### `pStgOptions` [in]

The *pStgOptions* parameter is valid only if the *stgfmt* parameter is set to STGFMT_DOCFILE. If the *stgfmt* parameter is set to STGFMT_DOCFILE, *pStgOptions* points to the
[STGOPTIONS](https://learn.microsoft.com/windows/desktop/api/coml2api/ns-coml2api-stgoptions) structure, which specifies features of the storage object, such as the sector size. This parameter may be **NULL**, which creates a storage object with a default sector size of 512 bytes. If non-**NULL**, the **ulSectorSize** member must be set to either 512 or 4096. If set to 4096, STGM_SIMPLE may not be specified in the *grfMode* parameter. The **usVersion** member must be set before calling
**StgCreateStorageEx**. For more information, see **STGOPTIONS**.

### `pSecurityDescriptor` [in]

Enables the ACLs to be set when the file is created. If not **NULL**, needs to be a pointer to the [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. See [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) for information on how to set ACLs on files.

**Windows Server 2003, Windows 2000 Server, Windows XP and Windows 2000 Professional:** Value must be **NULL**.

### `riid` [in]

A value that specifies the interface identifier (IID) of the interface pointer to return. This IID may be for the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface or the
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

### `ppObjectOpen` [out]

A pointer to an interface pointer variable that receives a pointer for an interface on the new storage object; contains **NULL** if operation failed.

## Return value

This function can also return any file system errors or system errors wrapped in an **HRESULT**. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

When an application modifies its file, it usually creates a copy of the original. The **StgCreateStorageEx** function is one way for creating a copy. This function works indirectly with the Encrypting File System (EFS) duplication API. When you use this function, you will need to set the options for the file storage in the [STGOPTIONS](https://learn.microsoft.com/windows/desktop/api/coml2api/ns-coml2api-stgoptions) structure.

**StgCreateStorageEx** is a superset of the
[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile) function, and should be used by new code. Future enhancements to Structured Storage will be exposed through the
**StgCreateStorageEx** function. See the following Requirements section for information on supported platforms.

The
**StgCreateStorageEx** function creates a new storage object using one of the system-provided, structured-storage implementations. This function can be used to obtain an
[IStorage compound file implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation), an [IPropertySetStorage compound file implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-compound-file-implementation), or to obtain an
[IPropertySetStorage NTFS implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-ntfs-file-system-implementation).

When a new file is created, the storage implementation used depends on the
flag that you specify and on the type of drive on which the file is stored. For more information, see the
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) enumeration.

**StgCreateStorageEx** creates the file if it does not exist. If it does exist, the use of the STGM_CREATE, STGM_CONVERT, and STGM_FAILIFTHERE flags in the *grfMode* parameter indicate how to proceed. For more information on these values, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). It is not valid, in direct mode, to specify the STGM_READ mode in the *grfMode* parameter (direct mode is indicated by not specifying the STGM_TRANSACTED flag). This function cannot be used to open an existing file; use the
[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex) function instead.

You can use the
**StgCreateStorageEx** function to get access to the root storage of a structured-storage document or the property set storage of any file that supports property sets. See the
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) documentation for information about which IIDs are supported for different
**STGFMT** values.

When a file is created with this function to access the NTFS property set implementation, special sharing rules apply. For more information, see
[IPropertySetStorage-NTFS Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-ntfs-file-system-implementation).

If a compound file is created in transacted mode (by specifying STGM_TRANSACTED) and read-only mode (by specifying STGM_READ), it is possible to make changes to the returned storage object. For example, it is possible to call
[IStorage::CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream). However, it is not possible to commit those changes by calling
[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit). Therefore, such changes will be lost.

Specifying STGM_SIMPLE provides a much faster implementation of a compound file object in a limited, but frequently used case involving applications that require a compound file implementation with multiple streams and no storages. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). It is not valid to specify that STGM_TRANSACTED if STGM_SIMPLE is specified.

The simple mode does not support all the methods on
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage). Specifically, in simple mode, supported
**IStorage** methods are [CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream), [Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit), and
[SetClass](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setclass) as well as the COM [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) methods of [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) and [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). In addition,
[SetElementTimes](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setelementtimes) is supported with a **NULL** name, allowing applications to set times on a root storage. All the other methods of
**IStorage** return STG_E_INVALIDFUNCTION.

If the *grfMode* parameter specifies STGM_TRANSACTED and no file yet exists with the name specified by the *pwcsName* parameter, the file is created immediately. In an access-controlled file system, the caller must have write permissions for the file system directory in which the compound file is created. If STGM_TRANSACTED is not specified, and STGM_CREATE is specified, an existing file with the same name is destroyed before creating the new file.

You can also use
**StgCreateStorageEx** to create a temporary compound file by passing a **NULL** value for the *pwcsName* parameter. However, these files are temporary only in the sense that they have a unique system-provided name – one that is probably meaningless to the user. The caller is responsible for deleting the temporary file when finished with it, unless STGM_DELETEONRELEASE was specified for the *grfMode* parameter. For more information on these flags, see
[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85))

[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants)

[STGOPTIONS](https://learn.microsoft.com/windows/desktop/api/coml2api/ns-coml2api-stgoptions)

[StgCreateDocFileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes)

[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile)

[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex)