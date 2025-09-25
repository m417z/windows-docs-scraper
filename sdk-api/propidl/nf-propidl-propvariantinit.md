# PropVariantInit macro

## Description

The **PropVariantInit** function
initializes a
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

**Note** This function is implemented as a macro, available by including the provided ole2.h header file. This function is not exported from any system-provided DLL.

## Parameters

### `pvar` [out]

Pointer to an uninitialized
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that is initialized.

## Remarks

Initializes a
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure, and sets its type to VT_EMPTY. **PropVariantInit** should not be used to clear a **PROPVARIANT** structure that contains data; for example, when it contains the result of a call to
[IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple). Such a
**PROPVARIANT** structure should be cleared using the
[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear) function.

## See also

[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)

[PropVariantClear](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantclear)