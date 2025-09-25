# IStorage::Stat

## Description

The **Stat** method retrieves the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure for this open storage object.

## Parameters

### `pstatstg` [out]

On return, pointer to a
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure where this method places information about the open storage object. This parameter is **NULL** if an error occurs.

### `grfStatFlag` [in]

Specifies that some of the members in the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure are not returned, thus saving a memory allocation operation. Values are taken from the
[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The STATSTG structure was successfully returned at the specified location.|
|E_PENDING | Asynchronous Storage only: Part or all of the storage's data is currently unavailable.|
|STG_E_ACCESSDENIED | The caller does not have enough permissions for accessing statistics for this storage object.|
|STG_E_INSUFFICIENTMEMORY | The STATSTG structure was not returned due to a lack of memory.|
|STG_E_INVALIDFLAG | The value for the *grfStateFlag* parameter is not valid.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|

## Remarks

**IStorage::Stat** retrieves the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure for the current storage object. The
**STATSTG** structure contains statistical information about the storage object. [IStorage::EnumElements](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-enumelements) returns a pointer to an enumerator object. The enumerator object returned by this method implements the
[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg) interface, through which the data stored in the array of the
**STATSTG** structures is enumerated.

## See also

[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg)

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[IStorage::SetClass](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setclass)

[IStorage::SetElementTimes](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setelementtimes)

[IStorage::SetStateBits](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setstatebits)

[STATFLAG](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-statflag)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)