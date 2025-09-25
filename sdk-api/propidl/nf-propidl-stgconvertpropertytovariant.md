# StgConvertPropertyToVariant function

## Description

The **StgConvertPropertyToVariant** function converts a **SERIALIZEDPROPERTYVALUE** data type to a **PROPVARIANT** data type.

## Parameters

### `pprop` [in]

A pointer to **SERIALIZEDPROPERTYVALUE**.

### `CodePage` [in]

A property set codepage.

### `pvar` [out]

A pointer to **PROPVARIANT**.

### `pma` [in]

A pointer to a class that implements the [IMemoryAllocator](https://learn.microsoft.com/windows/desktop/Stg/imemoryallocator) abstract class.

## Return value

Returns **TRUE** is the property converted was an indirect type (**VT_STREAM** or **VT_STREAMED_OBJECT**); otherwise **FALSE**.

## Remarks

This function converts a property to a **PROPVARIANT** data type. If the function fails, it throws an exception that represents an **NT_STATUS** such as **STATUS_INVALID_PARAMETER**.

## See also

[StgConvertVariantToProperty](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-stgconvertvarianttoproperty)

[StgDeserializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgdeserializepropvariant)