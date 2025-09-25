# StgOpenStorageOnILockBytes function

## Description

The **StgOpenStorageOnILockBytes** function opens an existing storage object that does not reside in a disk file, but instead has an underlying byte array provided by the caller.

## Parameters

### `plkbyt` [in]

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) pointer to the underlying byte array object that contains the storage object to be opened.

### `pstgPriority` [in]

A pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface that should be **NULL**. If not **NULL**, this parameter is used as described below in the Remarks section.

After **StgOpenStorageOnILockBytes** returns, the storage object specified in *pStgPriority* may have been released and should no longer be used.

### `grfMode` [in]

Specifies the access mode to use to open the storage object. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) and the Remarks section below.

### `snbExclude` [in]

Can be **NULL**. If not **NULL**, this parameter points to a block of elements in this storage that are to be excluded as the storage object is opened. This exclusion occurs independently of whether a snapshot copy happens on the open.

### `reserved` [in]

Indicates reserved for future use; must be zero.

### `ppstgOpen` [out]

Points to the location of an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the opened storage on successful return.

## Return value

The **StgOpenStorageOnILockBytes** function can also return any file system errors, or system errors wrapped in an **HRESULT**, or
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface error return values. See
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies)
and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

**StgOpenStorageOnILockBytes** opens the specified root storage object. A pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the opened storage object is supplied through the *ppstgOpen* parameter.

The storage object must have been previously created by the
[StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes) function.

Except for specifying a programmer-provided byte-array object,
**StgOpenStorageOnILockBytes** is similar to the
[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage) function. The storage object is opened according to the access modes in the *grfMode* parameter, subject to the following restrictions:

Sharing mode behavior and transactional isolation depend on the [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation supporting [LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-lockregion) and [UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-unlockregion) with [LOCK_ONLYONCE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) semantics. Implementations can indicate to structured storage they support this functionality by setting the **LOCK_ONLYONCE** bit in the **grfLocksSupported** member of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg). If an **ILockBytes** implementation does not support this functionality, sharing modes will not be enforced, and root-level transactional commits will not coordinate properly with other transactional instances opened on the same byte array. Applications that use an **ILockBytes** implementation that does not support region locking, such as the [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) implementation, should avoid opening multiple concurrent instances on the same byte array.

**StgOpenStorageOnILockBytes** does not support simple mode. The [STGM_SIMPLE](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) flag, if present, is ignored.

The *pStgPriority* parameter is intended as a convenience for callers replacing an existing storage object, often one opened in priority mode, with a new storage object opened on the same byte array. Unlike the *pStgPriority* parameter of [StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage), this parameter does not affect the open operation performed by **StgOpenStorageOnILockBytes** and is simply an existing storage object the caller would like released. Callers should always pass **NULL** for this parameter because **StgOpenStorageOnILockBytes** releases the object under some circumstances, and does not release it under other circumstances.
The use of the *pStgPriority* parameter can be duplicated by the caller in a safer manner by instead releasing the object before calling **StgOpenStorageOnILockBytes**, as shown in the following example:

``` syntax
// Replacement for:
// HRESULT hr = StgOpenStorageOnILockBytes(
//         plkbyt, pStgPriority, grfMode, NULL, 0, &pstgNew);

pStgPriority->Release();
pStgPriority = NULL;
hr = StgOpenStorage(plkbyt, NULL, grfMode, NULL, 0, &pstgNew);

```

For more information, refer to
[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage).

## See also

[StgCreateDocfileOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfileonilockbytes)

[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage)