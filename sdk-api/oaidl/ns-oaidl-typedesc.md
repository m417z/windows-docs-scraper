# TYPEDESC structure

## Description

Describes the type of a variable, the return type of a function, or the type of a function parameter.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.lptdesc`

 With VT_PTR, the type pointed to.

### `DUMMYUNIONNAME.lpadesc`

With VT_CARRAY...

### `DUMMYUNIONNAME.hreftype`

With VT_USER_DEFINED, this is used to get a TypeInfo for the UDT.

### `vt`

The variant type.

## Remarks

If the variable is VT_SAFEARRAY or VT_PTR, the union portion of the TYPEDESC contains a pointer to a TYPEDESC that specifies the element type.