# StgOpenStorage function

## Description

The **StgOpenStorage** function opens an existing root storage object in the file system. Use this function to open compound files. Do not use it to open directories, files, or summary catalogs. Nested storage objects can only be opened using their parent
[IStorage::OpenStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstorage) method.

**Note** Applications should use the new function,
[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex), instead of
**StgOpenStorage**, to take advantage of the enhanced and Windows Structured Storage features. This function,
**StgOpenStorage**, still exists for compatibility with applications running on Windows 2000.

## Parameters

### `pwcsName` [in]

A pointer to the path of the **null**-terminated Unicode string file that contains the storage object to open. This parameter is ignored if the *pstgPriority* parameter is not **NULL**.

### `pstgPriority` [in]

A pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface that should be **NULL**. If not **NULL**, this parameter is used as described below in the Remarks section.

After **StgOpenStorage** returns, the storage object specified in *pStgPriority* may have been released and should no longer be used.

### `grfMode` [in]

Specifies the access mode to use to open the storage object.

### `snbExclude` [in]

If not **NULL**, pointer to a block of elements in the storage to be excluded as the storage object is opened. The exclusion occurs regardless of whether a snapshot copy happens on the open. Can be **NULL**.

### `reserved` [in]

Indicates reserved for future use; must be zero.

### `ppstgOpen` [out]

A pointer to a
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)* pointer variable that receives the interface pointer to the opened storage.

## Return value

The **StgOpenStorage** function can also return any file system errors or system errors wrapped in an **HRESULT**. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

The
**StgOpenStorage** function opens the specified root storage object according to the access mode in the *grfMode* parameter, and, if successful, supplies an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the opened storage object in the *ppstgOpen* parameter.

To support the simple mode for saving a storage object with no substorages, the
**StgOpenStorage** function accepts one of the following two flag combinations as valid modes in the *grfMode* parameter.

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

In direct mode, one of the following three combinations are valid.

``` syntax
    STGM_DIRECT | STGM_READWRITE | STGM_SHARE_EXCLUSIVE
```

``` syntax
    STGM_DIRECT | STGM_READ | STGM_SHARE_DENY_WRITE
```

``` syntax
    STGM_DIRECT | STGM_READ | STGM_SHARE_EXCLUSIVE
```

**Note** Opening a storage object in read/write mode without denying write permission to others (the *grfMode* parameter specifies STGM_SHARE_DENY_WRITE) can be a time-consuming operation because the
**StgOpenStorage** call must make a snapshot of the entire storage object.

Applications often try to open storage objects with the following access permissions. If the application succeeds, it never needs to make a snapshot copy.

``` syntax
STGM_READWRITE | STGM_SHARE_DENY_WRITE
    // transacted versus direct mode omitted for exposition
```

The application can revert to using the permissions and make a snapshot copy, if the previous access permissions fail. The application should prompt the user before making a time-consuming copy.

``` syntax
STGM_READWRITE
    // transacted versus direct mode omitted for exposition
```

If the document-sharing semantics implied by the access modes are appropriate, the application could try to open the storage as follows. In this case, if the application succeeds, a snapshot copy will not have been made (because **STGM_SHARE_DENY_WRITE** was specified, denying others write access).

``` syntax
STGM_READ | STGM_SHARE_DENY_WRITE
    // transacted versus direct mode omitted for exposition
```

**Note** To reduce the expense of making a snapshot copy, applications can open storage objects in priority mode (*grfMode* specifies **STGM_PRIORITY**).

The *snbExclude* parameter specifies a set of element names in this storage object that are to be emptied as the storage object is opened: streams are set to a length of zero; storage objects have all their elements removed. By excluding certain streams, the expense of making a snapshot copy can be significantly reduced. Almost always, this approach is used after first opening the storage object in priority mode, then completely reading the now-excluded elements into memory. This earlier priority-mode opening of the storage object should be passed through the *pstgPriority* parameter to remove the exclusion implied by priority mode. The calling application is responsible for rewriting the contents of excluded items before committing. Thus, this technique is most likely useful only to applications whose documents do not require constant access to their storage objects while they are active.

The *pstgPriority* parameter is intended as a convenience for callers replacing an existing storage object, often one opened in priority mode, with a new storage object opened on the same file but in a different mode. When *pstgPriority* is not **NULL**, it is used to specify the file name instead of *pwcsName*, which is ignored. However, it is recommended that applications always pass **NULL** for *pstgPriority* because **StgOpenStorage** releases the object under some circumstances, and does not release it under other circumstances. In particular, if the function returns a failure result, it is not possible for the caller to determine whether or not the storage object was released.

The functionality of the *pstgPriority* parameter can be duplicated by the caller in a safer manner as shown in the following example:

``` syntax
// Replacement for:
// HRESULT hr = StgOpenStorage(
//         NULL, pstgPriority, grfMode, NULL, 0, &pstgNew);

STATSTG statstg;
HRESULT hr = pstgPriority->Stat(&statstg, 0);
pStgPriority->Release();
pStgPriority = NULL;
if (SUCCEEDED(hr))
{
    hr = StgOpenStorage(statstg.pwcsName, NULL, grfMode, NULL, 0, &pstgNew);
}

```

## See also

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)

[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile)

[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex)