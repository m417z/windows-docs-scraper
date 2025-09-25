# StgConvertVariantToProperty function

## Description

The **StgConvertVariantToProperty** function converts a **PROPVARIANT** data type to a **SERIALIZEDPROPERTYVALUE** data type.

## Parameters

### `pvar` [in]

A pointer to **PROPVARIANT**.

### `CodePage` [in]

A property set codepage.

### `pprop` [out, optional]

Optional. A pointer to **SERIALIZEDPROPERTYVALUE**.

### `pcb` [in, out]

A pointer to the remaining stream length, updated to the actual property size on return.

### `pid` [in]

The propid (used if indirect).

### `fReserved` [in]

Reserver. The value must be **FALSE**.

### `pcIndirect` [in, out, optional]

Optional. A pointer to the indirect property count.

## Return value

Returns a pointer to **SERIALIZEDPROPERTYVALUE**.

## Remarks

This function converts a **PROPVARIANT** to a property. If the function fails it throws an exception that represents **STATUS_INVALID_PARAMETER NT_STATUS**.

## See also

[StgConvertPropertyToVariant](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertpropertytovariant)

[StgSerializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgserializepropvariant)