# DELEGATEITEMID structure

## Description

Used by delegate folders in place of a standard [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

## Members

### `cbSize`

Type: **WORD**

The size, in bytes, of this structure.

### `wOuter`

Type: **WORD**

Private data owned by the delegating (outer) folder.

### `cbInner`

Type: **WORD**

The size, in bytes, of the delegate's data. The first **cbInner** bytes of the **rgb** array contain this data. The remaining data in **rgb** belongs to the outer folder.

### `rgb`

Type: **BYTE[1]**

An array holding the inner folder's data, which is opaque to the outer folder, followed by outer folder's data.