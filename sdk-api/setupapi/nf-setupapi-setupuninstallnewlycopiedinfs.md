# SetupUninstallNewlyCopiedInfs function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupUninstallNewlyCopiedInfs** function uninstalls INF files (.inf), precompiled INF files (.pnf), and catalog files (.cat) that are previously installed during the committal of the specified file queue.

A caller of this function must have administrative privileges; otherwise, the function fails.

## Parameters

### `FileQueue` [in]

Handle to an open and committed file queue. This queue contains the newly installed INF, PNF, or CAT files that
**SetupUninstallNewlyCopiedInfs** uninstalls.

### `Flags` [in]

Flags to use with
**SetupUninstallNewlyCopiedInfs**. No flags are defined currently. This parameter must be 0 (zero).

### `Reserved` [in]

Reserved. This parameter must be **NULL**.

## Return value

If the parameters passed in are valid, the return value is **TRUE** (nonzero), which does not necessarily mean that any INFs are uninstalled.

If some of the parameters passed in are invalid, the return value is **FALSE** (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea)

[SetupUninstallOEMInf](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupuninstalloeminfa)