# WlxNegotiate function

## Description

[The WlxNegotiate function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxNegotiate** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. This is the first call made by [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) to the GINA DLL. **WlxNegotiate** allows the GINA to verify that it supports the installed version of Winlogon.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `dwWinlogonVersion` [in]

Specifies which version of Winlogon will be communicating with the GINA.

### `pdwDllVersion` [out]

Indicates which version of Winlogon the GINA supports. This version information is also used by Winlogon to determine which dispatch table is passed to the GINA in subsequent calls to
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize). This version cannot be greater than the version specified by *dwWinLogonVersion*.

## Return value

If the Winlogon version specified by *dwWinLogonVersion* is greater than or equal to the version returned in *pdwDllVersion*, the function returns **TRUE**. When **TRUE** is returned, Winlogon will continue to initialize.

If *dwWinLogonVersion* is less than *pdwDllVersion*, the function returns **FALSE**. When **FALSE** is returned, Winlogon will terminate and the system will not boot.

## Remarks

Before calling **WlxNegotiate**, [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)