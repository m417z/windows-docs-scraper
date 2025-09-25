# TYPEATTR structure

## Description

Contains attributes of a type.

## Members

### `guid`

The GUID of the type information.

### `lcid`

The locale of member names and documentation strings.

### `dwReserved`

Reserved.

### `memidConstructor`

The constructor ID, or MEMBERID_NIL if none.

### `memidDestructor`

The destructor ID, or MEMBERID_NIL if none.

### `lpstrSchema`

Reserved.

### `cbSizeInstance`

The size of an instance of this type.

### `typekind`

The kind of type.

### `cFuncs`

The number of functions.

### `cVars`

The number of variables or data members.

### `cImplTypes`

The number of implemented interfaces.

### `cbSizeVft`

The size of this type's VTBL.

### `cbAlignment`

The byte alignment for an instance of this type. A value of 0 indicates alignment on the 64K boundary; 1 indicates no special alignment. For other values, *n* indicates aligned on byte *n*.

### `wTypeFlags`

The type flags. See [TYPEFLAGS](https://learn.microsoft.com/windows/desktop/api/oaidl/ne-oaidl-typeflags).

### `wMajorVerNum`

The major version number.

### `wMinorVerNum`

The minor version number.

### `tdescAlias`

If **typekind** is TKIND_ALIAS, specifies the type for which this type is an alias.

### `idldescType`

The IDL attributes of the described type.