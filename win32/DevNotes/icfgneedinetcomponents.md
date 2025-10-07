# IcfgNeedInetComponents function

Determines whether components marked in the options are installed on the system.

## Parameters

*dwfOptions*

A combination of the following flags that specify which components to detect from the following list.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------|
| **ICFG\_INSTALLMAIL**

0x00000004 | Is Exchange or Internet mail needed?\ | | **ICFG\_INSTALLRAS**

0x00000002 | Is RAS needed?\ | | **ICFG\_INSTALLTCP**

0x00000001 | Is TCP/IP needed?\ |

*lpfNeedComponents*

If this value is non-**NULL**, it is **TRUE** on return if one or more components are not installed on the system.

## Return value

Returns an **HRESULT** value. If no errors occur, it returns the **ERROR\_SUCCESS** code.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Icfgnt5.dll |

