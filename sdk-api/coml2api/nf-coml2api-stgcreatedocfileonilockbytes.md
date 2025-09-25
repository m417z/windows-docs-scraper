# StgCreateDocfileOnILockBytes function

## Description

The **StgCreateDocfileOnILockBytes** function creates and opens a new compound file storage object on top of a byte-array object provided by the caller. The storage object supports the COM-provided, compound-file implementation for the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface.

## Parameters

### `plkbyt` [in]

A pointer to the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface on the underlying byte-array object on which to create a compound file.

### `grfMode` [in]

Specifies the access mode to use when opening the new compound file. For more information, see [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) and the Remarks section below.

### `reserved` [in]

Reserved for future use; must be zero.

### `ppstgOpen` [out]

A pointer to the location of the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer on the new storage object.

## Return value

The **StgCreateDocfileOnILockBytes** function can also return any file system errors, or system errors wrapped in an **HRESULT**, or
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface error return values. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

The
**StgCreateDocfileOnILockBytes** function creates a storage object on top of a byte array object using the COM-provided, compound-file implementation of the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface.
**StgCreateDocfileOnILockBytes** can be used to store a document in an arbitrary data store, such as memory or a relational database. The byte array (indicated by the *pLkbyt* parameter, which points to the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface on the object) is used for the underlying storage in place of a disk file.

Except for specifying a programmer-provided byte-array object,
**StgCreateDocfileOnILockBytes** is similar to the
[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile) function.

The newly created compound file is opened according to the access modes in the *grfMode* parameter, subject to the following restrictions:

Sharing mode behavior and transactional isolation depend on the [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation supporting [LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-lockregion) and [UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-unlockregion) with [LOCK_ONLYONCE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) semantics. Implementations can indicate to structured storage they support this functionality by setting the **LOCK_ONLYONCE** bit in the **grfLocksSupported** member of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg). If an **ILockBytes** implementation does not support this functionality, sharing modes will not be enforced, and root-level transactional commits will not coordinate properly with other transactional instances opened on the same byte array. Applications that use an **ILockBytes** implementation that does not support region locking, such as the [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) implementation, should avoid opening multiple concurrent instances on the same byte array.

**StgCreateDocfileOnILockBytes** does not support simple mode. The [STGM_SIMPLE](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) flag, if present, is ignored.

For conversion purposes, the file is considered to already exist. As a result, it is not useful to use the [STGM_FAILIFTHERE](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) value, because it causes an error to be returned. However, both STGM_CREATE and STGM_CONVERT remain useful.

The ability to build a compound file on top of a byte-array object is provided to support having the data (underneath an
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) and
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) tree structure) live in a nonpersistent space. Given this capability, there is nothing preventing a document that is stored in a file from using this facility. For example, a container might do this to minimize the impact on its file format caused by adopting COM. However, it is recommended that COM documents adopt the
**IStorage** interface for their own outer-level storage. This has the following advantages:

* The storage structure of the document is the same as its storage structure when it is an embedded object, reducing the number of cases the application needs to handle.
* One can write tools to access the OLE embedded and linked objects within the document without special knowledge of the document's file format. An example of such a tool is a copy utility that copies all the documents included in a container containing linked objects. A copy utility like this needs access to the contained links to determine the extent of files to be copied.
* The
  [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) implementation addresses the problem of how to commit the changes to the file. An application using the
  [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface must handle these issues itself.

## See also

[StgCreateDocfile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatedocfile)