# PifMgr_GetProperties function

## Description

[**PifMgr_GetProperties** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Returns a specified block of data from a .pif file.

## Parameters

### `hProps` [in, optional]

Type: **HANDLE**

A handle to an application's properties. This parameter should be set to the value that is returned by [PifMgr_OpenProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_openproperties).

### `pszGroup` [in, optional]

Type: **PCSTR**

A null-terminated string that contains the property group name. It can be one of the following, or any other name that corresponds to a valid .pif extension.

####

"WINDOWS 286 3.0"

"WINDOWS 386 3.0"

"WINDOWS VMM 4.0"

"WINDOWS NT 3.1"

"WINDOWS NT 4.0"

### `lpProps` [out, optional]

Type: **void***

When this function returns, contains a pointer to a [PROPPRG](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-propprg) structure.

### `cbProps`

Type: **int**

The size of the buffer, in bytes, pointed to by *lpProps*.

### `flOpt`

Type: **UINT**

Set this parameter to GETPROPS_NONE.

## Return value

Type: **int**

Returns **NULL** if successful. If unsuccessful, the function returns the handle to the application properties that were passed as *hProps*.

## Remarks

If the block is a "named" block, it must be the name of a linked extension inside the .pif file. This can be any predefined name (such as, "WINDOWS 386 3.0") or the name of your own block. You can create your own named data blocks using [PifMgr_SetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_setproperties). Named data can also be thought of as raw data, because it is returned to the calling application as it is, without translation.

The size of a named block can be determined by calling **PifMgr_GetProperties** with *cbProps* set to 0. No data is copied, but the size of the requested block is returned.

All named blocks can be enumerated by setting *pszGroup* to **NULL**. *lpProps* must be a pointer to a 16-byte buffer to contain the requested block name, and *cbProps* must be set to the zero-based block index. The return value is the size of the block, or zero if the block is not found.

If you request an unnamed property block by setting the selector of the name parameter to **NULL**, and the offset is a property group ordinal, then the associated structure is returned. For example, PifMgr_GetProperties(GROUP_TSK) returns a predefined structure that contains all the task-related information in a format that is independent of the .pif file. This is a valuable service because it relieves calling applications from dealing with .pif files that contain a wide variety of sections (known as .pif extensions), when only one is required.

## See also

[PifMgr_CloseProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_closeproperties)

[PifMgr_OpenProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_openproperties)