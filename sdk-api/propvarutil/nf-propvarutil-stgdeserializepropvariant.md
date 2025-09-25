# StgDeserializePropVariant function

## Description

The **StgDeserializePropVariant** function converts a SERIALIZEDPROPERTYVALUE data type to a PROPVARIANT data type.

## Parameters

### `pprop` [in]

A pointer to the **SERIALIZEDPROPERTYVALUE** buffer.

### `cbMax` [in]

The size of the *pprop* buffer in bytes.

### `ppropvar` [out]

A pointer to a **PROPVARIANT**.

## Return value

This function can return one of these values.

## Remarks

This function deserializes a **PROPVARIANT** data type. This function is similar to the [StgConvertPropertyToVariant](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertpropertytovariant) function. The **StgDeserializePropVariant** function uses the default value of **CP_WINUNICODE** for the code page and a system provided allocator that uses task memory. Use **StgDeserializePropVariant** unless you want to specify which code page and memory allocator to use.

## See also

[StgConvertPropertyToVariant](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertpropertytovariant)

[StgSerializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgserializepropvariant)