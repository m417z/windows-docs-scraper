# IStream::Stat

## Description

The **Stat** method retrieves the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure for this stream.

## Parameters

### `pstatstg` [out]

Pointer to a
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure where this method places information about this stream object.

### `grfStatFlag` [in]

Specifies that this method does not return some of the members in the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure, thus saving a memory allocation operation. Values are taken from the
[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The STATSTG structure was successfully returned at the specified location.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable. |
|STG_E_ACCESSDENIED | The caller does not have enough permissions for accessing statistics for this storage object.|
|STG_E_INSUFFICIENTMEMORY | The STATSTG structure was not returned due to a lack of memory.|
|STG_E_INVALIDFLAG | The value for the *grfStateFlag* parameter is not valid.|
|STG_E_INVALIDPOINTER | The *pStatStg* pointer is not valid.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**IStream::Stat** retrieves a pointer to the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure that contains information about this open stream. When this stream is within a structured storage and
[IStorage::EnumElements](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-enumelements) is called, it creates an enumerator object with the
[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg) interface on it, which can be called to enumerate the storages and streams through the
**STATSTG** structures associated with each of them.

## See also

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)