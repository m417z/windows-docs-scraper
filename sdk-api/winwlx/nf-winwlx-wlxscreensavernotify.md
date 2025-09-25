# WlxScreenSaverNotify function

## Description

[The WlxScreenSaverNotify function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxScreenSaverNotify** function may be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function immediately before a screen saver is activated, allowing the GINA to interact with the screen saver program.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `pSecure` [in, out]

 A pointer to a Boolean value that, on input, specifies whether the current screen saver is secure and,

on output, indicates whether the workstation should be locked.

## Return value

If the screen saver should be activated, the function returns **TRUE**.

If the screen saver should not be activated, the function returns **FALSE**.

## Remarks

If your GINA DLL does not export this function, Winlogon uses the following default behavior.

```cpp
#include <windows.h>
#include <Winwlx.h>

BOOL DefaultScreenSaverNotify(
   PVOID   pWlxContext,
   BOOL    *pSecure)
{
  if (*pSecure)
  {
    *pSecure = WlxIsLockOk(pWlxContext);
  }
  return(TRUE);
}

```

Before calling **WlxScreenSaverNotify**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

## See also

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)