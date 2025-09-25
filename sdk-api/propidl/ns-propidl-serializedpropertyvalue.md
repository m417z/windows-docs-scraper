# SERIALIZEDPROPERTYVALUE structure

## Description

A range of memory of arbitrary type that represents a serialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. Programs should not inspect the contents of a **SERIALIZEDPROPERTYVALUE**; instead, they should manipulate it with the [StgSerializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgserializepropvariant) and [StgDeserializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgdeserializepropvariant) functions.

## Members

### `dwType`

Type: **DWORD**

Encodes type information about the serialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. Programs should not inspect this member directly; instead, they should use the [StgDeserializePropVariant](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-stgdeserializepropvariant) function and inspect the **vt** member of the resulting **PROPVARIANT** structure.

### `rgb`

Type: **BYTE[1]**

A variable-length additional data that depends on the type passed in **dwType**.