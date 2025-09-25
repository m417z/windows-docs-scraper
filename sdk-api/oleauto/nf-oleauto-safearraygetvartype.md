# SafeArrayGetVartype function

## Description

Gets the VARTYPE stored in the specified safe array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `pvt` [out]

The VARTYPE.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One of the arguments is not valid. |

## Remarks

If FADF_HAVEVARTYPE is set, **SafeArrayGetVartype** returns the VARTYPE stored in the array descriptor. If FADF_RECORD is set, it returns VT_RECORD; if FADF_DISPATCH is set, it returns VT_DISPATCH; and if FADF_UNKNOWN is set, it returns VT_UNKNOWN.

**SafeArrayGetVartype** can fail to return VT_UNKNOWN for SAFEARRAY types that are based on **IUnknown**. Callers should additionally check whether the SAFEARRAY type's **fFeatures** field has the FADF_UNKNOWN flag set.

## See also

[SAFEARRAY Data Type](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray)