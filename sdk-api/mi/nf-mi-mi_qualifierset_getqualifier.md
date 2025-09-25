# MI_QualifierSet_GetQualifier function

## Description

Gets the qualifier information based on the given qualifier name.

## Parameters

### `self` [in]

[MI_QualifierSet](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_qualifierset) structure.

### `name`

A null-terminated string that represents the name of the qualifier to get.

### `qualifierType` [out]

Returned qualifier type.

### `qualifierFlags` [out]

Returned qualifier flags that indicate the scope of a qualifier.

### `qualifierValue` [out]

Returned qualifier value. This value has the lifetime of the qualifier set.

### `index` [out]

Returned zero-based index of the qualifier.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.