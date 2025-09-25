# PifMgr_SetProperties function

## Description

[**PifMgr_SetProperties** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Assigns values to a block of data from a .pif file.

## Parameters

### `hProps` [in, optional]

Type: **HANDLE**

A handle to the application's properties. This parameter should be set to the value that is returned by [PifMgr_OpenProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_openproperties).

### `pszGroup` [in, optional]

Type: **PCSTR**

A null-terminated ANSI string containing the property group name. It can be one of the following, or any other name that corresponds to a valid .pif extension.

####

"WINDOWS 286 3.0"

"WINDOWS 386 3.0"

"WINDOWS VMM 4.0"

"WINDOWS NT 3.1"

"WINDOWS NT 4.0"

### `lpProps` [in]

Type: **const void***

A property group record buffer that holds the data.

### `cbProps`

Type: **int**

The size of the buffer, in bytes, pointed to by *lpProps*.

### `flOpt`

Type: **UINT**

Always SETPROPS_NONE.

## Return value

Type: **int**

Returns the amount of information transferred, in bytes. Returns zero if the group cannot be found or an error occurs.

## See also

[PifMgr_GetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_getproperties)