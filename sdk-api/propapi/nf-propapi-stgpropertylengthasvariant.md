# StgPropertyLengthAsVariant function

## Description

The **StgPropertyLengthAsVariant** function examines a **SERIALIZEDPROPERTYVALUE** and returns the amount of memory that this property would occupy as a **PROPVARIANT**.

## Parameters

### `pProp` [in]

A pointer to a **SERIALIZEDPROPERTYVALUE**.

### `cbProp` [in]

The size of the *pProp* buffer in bytes.

### `CodePage` [in]

A property set code page.

### `bReserved` [in]

Reserved. Must be 0.

## Return value

Returns the amount of memory the property would occupy as a **PROPVARIANT**.

## Remarks

Use this function to decide whether or not to deserialize a property value in a low-memory scenario. Most applications will have no need to call this function.

## See also

[StgConvertPropertyToVariant](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertpropertytovariant)

[StgDeserializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgdeserializepropvariant)