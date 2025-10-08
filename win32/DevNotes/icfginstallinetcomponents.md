# IcfgInstallInetComponents function

Installs the system components specified.

## Parameters

*hwndParent*

A handle to the parent window.

*dwfOptions*

A combination of the following flags that control the installation and configuration.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|
| **ICFG\_INSTALLMAIL**<br>0x00000004 | Install Exchange and Internet mail.<br> |
| **ICFG\_INSTALLRAS**<br>0x00000002 | Install RAS (if needed).<br> |
| **ICFG\_INSTALLTCP**<br>0x00000001 | Install TCP/IP (if needed).<br> |

*lpfNeedsRestart*

If this value is non-**NULL**, on return it will be **TRUE** only if Windows must be restarted to complete the installation.

## Return value

Returns an **HRESULT** value. If no errors occur, it returns the **ERROR\_SUCCESS** code.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Icfgnt5.dll |

