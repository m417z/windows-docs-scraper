# StgSerializePropVariant function

## Description

The **StgSerializePropVariant** function converts a **PROPVARIANT** data type to a **SERIALIZEDPROPERTYVALUE** data type.

## Parameters

### `ppropvar` [in]

A pointer to **PROPVARIANT**.

### `ppProp` [out]

A pointer to the newly allocated **SERIALIZEDPROPERTYVALUE**.

### `pcb` [out]

A pointer to the size of the newly allocated **SERIALIZEDPROPERTYVALUE**.

## Return value

This function can return one of these values.

## Remarks

The
**StgSerializePropVariant** function serializes a **PROPVARIANT**. The function is similar to the [StgConvertVariantToProperty](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertvarianttoproperty) function, but the **StgSerializePropVariant** function automatically handles memory allocation for the new **SERIALIZEDPROPERTYVALUE**. In addition, **StgSerializePropVariant** uses the default values **CP_WINUNICODE** and PID_ILLEGAL for code page and property ID respectively. Use **StgSerializePropVariant** unless control over these arguments is specifically needed.

## See also

[StgConvertVariantToProperty](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertvarianttoproperty)

[StgDeserializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgdeserializepropvariant)