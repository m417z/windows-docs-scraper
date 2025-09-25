# ASSOCIATIONLEVEL enumeration

## Description

Specifies the source of the default association for a file name extension. Used by methods of the [IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration) interface.

## Constants

### `AL_MACHINE:0`

The machine-level default application association.

### `AL_EFFECTIVE`

The effective default for the current user. This value should be used by most applications.

### `AL_USER`

The per-user default application association. If this value is used and no per-user default is declared, the calling method fails with a value of `HRESULT_FROM_WIN32(ERROR_NO_ASSOCIATION)`.

## See also

[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32)