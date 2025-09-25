# SetProcessRestrictionExemption function

## Description

 Exempts the calling process from restrictions preventing desktop processes from interacting with the Windows Store app environment. This function is used by development and debugging tools.

This function only succeeds if a developer license is present on the system. Once successful the calling process will be able to perform the following actions, subject to User Interface Privilege Isolation (UIPI) restrictions:

* Attach global hooks (and event hooks) to Windows Store app processes.
* Attach input queues between Windows Store app processes, Windows Store app browsers, system processes, and desktop application processes.
* Change foreground arbitrarily between the Windows Store app and desktop environments.

## Parameters

### `fEnableExemption`

When set to TRUE, indicates a request to disable exemption for the calling process.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Any process can call this function, including desktop and Windows Store app processes and processes that use IL code.