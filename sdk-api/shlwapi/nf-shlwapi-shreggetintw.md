# SHRegGetIntW function

## Description

Reads a numeric string value from the registry and converts it to an integer.

## Parameters

### `hk` [in]

Type: **HKEY**

A handle to the registry key that specifies the value to be read.

### `pwzKey` [in]

Type: **LPCWSTR**

A pointer to a string value that specifies the name of the value to be read. The string must be null-terminated.

### `iDefault` [in]

Type: **int**

An **int** that specifies the value returned if the registry value cannot be retrieved successfully.

## Return value

Type: **int**

Returns the converted string as an **int**, or the default value specified by *nDefault*.

## Remarks

Prior to Windows 2000 Service Pack 3 (SP3), Windows Server 2003 Service Pack 1 (SP1), and Windows XP, **SHRegGetIntW** was not exported by name. On those systems you must load it directly from Shlwapi.dll as ordinal 280.

This function is only available in a Unicode version. ANSI is not supported.