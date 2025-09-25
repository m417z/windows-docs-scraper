# ILockBytes::Stat

## Description

The **Stat** method retrieves a
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure containing information for this byte array object.

## Parameters

### `pstatstg` [out]

Pointer to a
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure in which this method places information about this byte array object. The pointer is **NULL** if an error occurs.

### `grfStatFlag` [in]

Specifies whether this method should supply the **pwcsName** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure through values taken from the
[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag) enumeration. If the STATFLAG_NONAME is specified, the **pwcsName** member of
**STATSTG** is not supplied, thus saving a memory-allocation operation. The other possible value, STATFLAG_DEFAULT, indicates that all members of the
**STATSTG** structure be supplied.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The STATSTG structure was successfully returned at the specified location.|
|E_OUTOFMEMORY| The STATSTG structure was not returned due to a lack of memory for the name member in the structure.|
|STG_E_ACCESSDENIED | The STATSTG structure was not returned because the caller did not have access to the byte array.|
|STG_E_INSUFFICIENTMEMORY | The STATSTG structure was not returned, due to insufficient memory.|
|STG_E_INVALIDFLAG | The value for the grfStateFlag parameter is not valid.|
|STG_E_INVALIDPOINTER | The value for the pStatStg parameter is not valid.|

## Remarks

**ILockBytes::Stat** should supply information about the byte array object in a
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)