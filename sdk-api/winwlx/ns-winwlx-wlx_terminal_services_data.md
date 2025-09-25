# WLX_TERMINAL_SERVICES_DATA structure

## Description

[The WLX_TERMINAL_SERVICES_DATA structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_TERMINAL_SERVICES_DATA** structure is used to provide [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) with Terminal Services user configuration information.

The structure is populated by the
[WlxQueryTerminalServicesData](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_terminal_services_data) function.

## Members

### `ProfilePath`

Terminal Services profile path, overrides the standard profile path.

### `HomeDir`

Terminal Services home directory, overrides standard home directory.

### `HomeDirDrive`

Terminal Services home directory drive, overrides the standard drive.

## Remarks

The Terminal Services user configuration information is received from the Domain Controller and SAM database.

## See also

[WlxQueryTerminalServicesData](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_query_terminal_services_data)