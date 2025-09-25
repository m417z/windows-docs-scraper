# MI_QualifierSet_GetQualifierAt function

## Description

Gets a qualifier at the specified index.

## Parameters

### `self` [in]

[MI_QualifierSet](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_qualifierset) structure.

### `index`

Zero-based index of the qualifier to get.

### `name`

Returned qualifier name.

### `qualifierType` [out]

Returned qualifier type.

### `qualifierFlags` [out]

Returned qualifier flags.

### `qualifierValue` [out]

Returned qualifier value. This value has the same scope as the qualifier set.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.