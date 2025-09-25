# WlxInitialize function

## Description

[The WlxInitialize function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxInitialize** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function once for each window station present on the computer. Currently, the operating system supports one window station per workstation.

**Note** GINA DLLs are ignored in Windows Vista.

The [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) returned by this function will be passed back to the GINA in all subsequent calls.

## Parameters

### `lpWinsta` [in]

A pointer to the name of the window station being initialized.

### `hWlx` [in]

A handle to Winlogon. The GINA must supply this handle in all calls to Winlogon support functions that involve this window station.

### `pvReserved` [in]

This parameter is reserved for future use and must be set to **NULL**.

### `pWinlogonFunctions` [in]

A pointer to a Winlogon support function dispatch table. The contents of the table depend on the GINA DLL version returned by the
[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate) call. This table does not change, which allows the GINA DLL to reference the table without copying it. If the GINA DLL needs to make a copy of the table, it should call [WlxGetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_get_option) and supply WLX_OPTION_DISPATCH_TABLE_SIZE for the **Option** parameter.

| Value | Meaning |
| --- | --- |
| **[WLX_DISPATCH_VERSION_1_4](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_4)** | Winlogon dispatch table - version 1.4 |
| **[WLX_DISPATCH_VERSION_1_3](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_3)** | Winlogon dispatch table - version 1.3 |
| **[WLX_DISPATCH_VERSION_1_2](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_2)** | Winlogon dispatch table - version 1.2 |
| **[WLX_DISPATCH_VERSION_1_1](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_1)** | Winlogondispatch table - version 1.1 |
| **[WLX_DISPATCH_VERSION_1_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_dispatch_version_1_0)** | Winlogon dispatch table - version 1.0 |

### `pWlxContext` [out]

A pointer to a pointer to a **VOID** that will contain the address of the GINA context for this window station. This context is passed in all subsequent calls to the GINA from Winlogon. The GINA DLL manages any memory used by the context. The context pointer can be changed later by calling the [WlxSetOption](https://learn.microsoft.com/windows/desktop/api/winwlx/nc-winwlx-pwlx_set_option) function with WLX_OPTION_CONTEXT_POINTER.

## Return value

If the function successfully initializes the GINA DLL, the function returns **TRUE**.

If the function fails, or if the GINA DLL was not initialized, the function returns **FALSE**. Winlogon will terminate, and the system will not boot.

## Remarks

**WlxInitialize** is called once for each window station present on the computer.

Currently only a single window station called Winsta0 is supported.

Before calling **WlxInitialize**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxNegotiate](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxnegotiate)