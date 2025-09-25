# StgOpenStorageEx function

## Description

The **StgOpenStorageEx** function opens an existing root storage object in the file system. Use this function to open [Compound Files](https://learn.microsoft.com/windows/desktop/Stg/compound-files) and regular files. To create a new file, use the
[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex) function.

**Note** To use enhancements, all Windows 2000, Windows XP, and Windows Server 2003 applications should call **StgOpenStorageEx**, instead of
[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage). The
**StgOpenStorage** function is used for compatibility with Windows 2000 and earlier applications.

## Parameters

### `pwcsName` [in]

A pointer to the path of the null-terminated Unicode string file that contains the storage object. This string size cannot exceed **MAX_PATH** characters.

**Windows Server 2003 and Windows XP/2000:** Unlike the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function, the **MAX_PATH** limit cannot be exceeded by using the "\\?\" prefix.

### `grfMode` [in]

A value that specifies the access mode to open the new storage object. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants). If the caller specifies transacted mode together with **STGM_CREATE** or **STGM_CONVERT**, the overwrite or conversion occurs when the commit operation is called for the root storage. If [IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit) is not called for the root storage object, previous contents of the file will be restored. **STGM_CREATE** and **STGM_CONVERT** cannot be combined with the **STGM_NOSNAPSHOT** flag, because a snapshot copy is required when a file is overwritten or converted in transacted mode.

If the storage object is opened in direct mode (**STGM_DIRECT**) with access to either **STGM_WRITE** or **STGM_READWRITE**, the sharing mode must be **STGM_SHARE_EXCLUSIVE** unless the **STGM_DIRECT_SWMR** mode is specified. For more information, see the Remarks section. If the storage object is opened in direct mode with access to **STGM_READ**, the sharing mode must be either **STGM_SHARE_EXCLUSIVE** or **STGM_SHARE_DENY_WRITE**, unless **STGM_PRIORITY** or **STGM_DIRECT_SWMR** is specified. For more information, see the Remarks section.

The mode in which a file is opened can affect implementation performance. For more information, see
[Compound File Implementation Limits](https://learn.microsoft.com/windows/desktop/Stg/structured-storage-interfaces).

### `stgfmt` [in]

A value that specifies the storage file format. For more information, see the
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) enumeration.

### `grfAttrs` [in]

A value that depends upon the value of the *stgfmt* parameter.

**STGFMT_DOCFILE** must be zero (0) or **FILE_FLAG_NO_BUFFERING**. For more information about this value, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea). If the sector size of the file, specified in *pStgOptions*, is not an integer multiple of the physical sector size of the underlying disk, then this operation will fail. All other values of *stgfmt* must be zero.

### `pStgOptions` [in, out]

A pointer to an
[STGOPTIONS](https://learn.microsoft.com/windows/desktop/api/coml2api/ns-coml2api-stgoptions) structure that contains data about the storage object opened. The *pStgOptions* parameter is valid only if the *stgfmt* parameter is set to **STGFMT_DOCFILE**. The **usVersion** member must be set before calling
**StgOpenStorageEx**. For more information, see the **STGOPTIONS** structure.

### `pSecurityDescriptor` [in]

Reserved; must be zero.

### `riid` [in]

A value that specifies the GUID of the interface pointer to return. Can also be the header-specified value for **IID_IStorage** to obtain the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface or for **IID_IPropertySetStorage** to obtain the
[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

### `ppObjectOpen` [out]

The address of an interface pointer variable that receives a pointer for an interface on the storage object opened; contains **NULL** if operation failed.

## Return value

This function can also return any file system errors or system errors wrapped in an **HRESULT**. For more information, see [Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

**StgOpenStorageEx** is a superset of the
[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage) function, and should be used by new code. Future enhancements to structured storage will be exposed through this function. For more information about supported platforms, see the Requirements section.

The
**StgOpenStorageEx** function opens the specified root storage object according to the access mode in the *grfMode* parameter, and, if successful, supplies an interface pointer for the opened storage object in the *ppObjectOpen* parameter. This function can be used to obtain an [IStorage compound file implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation), an [IPropertySetStorage compound file implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-compound-file-implementation), or an
[NTFS file system implementation of IPropertySetStorage](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-ntfs-file-system-implementation).

When you open a file, the system selects a structured storage implementation depending on which
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) flag you specify on the file type and on the type of drive where the file is stored.

Use the
**StgOpenStorageEx** function to access the root storage of a structured storage document or the property set storage of any file that supports property sets. For more information about which interface identifiers (IIDs) are supported for the different
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)) values, see
[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85)).

When a file is opened with this function to access the NTFS property set implementation, special sharing rules apply. For more information, see [IPropertySetStorage-NTFS Implementation](https://learn.microsoft.com/windows/desktop/Stg/ipropertysetstorage-ntfs-file-system-implementation).

If a compound file is opened in transacted mode, by specifying STGM_TRANSACTED, and read-only mode, by specifying STGM_READ, it is possible to change the returned storage object. For example, it is possible to call
[IStorage::CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream). However, it is not possible to commit those changes by calling
[IStorage::Commit](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-commit). Therefore, such changes will be lost.

It is not valid to use the **STGM_CREATE**, **STGM_DELETEONRELEASE**, or **STGM_CONVERT** flags in the *grfMode* parameter for this function.

To support the simple mode for saving a storage object with no substorages, the
**StgOpenStorageEx** function accepts one of the following two flag combinations as valid modes in the *grfMode* parameter:

``` syntax
    STGM_SIMPLE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE
```

``` syntax
    STGM_SIMPLE | STGM_READ | STGM_SHARE_EXCLUSIVE
```

To support the single-writer, multireader, direct mode, the first flag combination is the valid *grfMode* parameter for the writer. The second flag combination is valid for readers.

``` syntax
    STGM_DIRECT_SWMR | STGM_READWRITE | STGM_SHARE_DENY_WRITE
```

``` syntax
    STGM_DIRECT_SWMR | STGM_READ | STGM_SHARE_DENY_NONE
```

For more information about simple mode and single-writer/multiple-reader modes, see
[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

**Note** Opening a transacted mode storage object in read and/or write mode without denying write permissions to others (for example, the *grfMode* parameter specifies **STGM_SHARE_DENY_WRITE**) can be time-consuming because the
**StgOpenStorageEx** call must create a snapshot copy of the entire storage object.

## See also

[Compound Files](https://learn.microsoft.com/windows/desktop/Stg/compound-files)

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)

[STGFMT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380330(v=vs.85))

[STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants)

[STGOPTIONS](https://learn.microsoft.com/windows/desktop/api/coml2api/ns-coml2api-stgoptions)

[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile)

[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex)

[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage)