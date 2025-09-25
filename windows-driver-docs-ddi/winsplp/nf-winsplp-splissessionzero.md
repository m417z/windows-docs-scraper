## Description

The **SplIsSessionZero** function determines whether a certain print job (print handle plus job ID) was issued in [session zero](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `hPrinter` [in]

A handle to the printer.

### `JobId`

Specifies the print job.

### `pIsSessionZero` [out]

Pointer to a memory location that is set to **TRUE** if the SessionID for the session is zero; otherwise, this value is set to **FALSE**.

## Return value

On success, the **SplIsSessionZero** function returns ERROR_SUCCESS; otherwise this function returns a Win32 error code.

## Remarks

A driver that displays custom user interface elements can use the **SplIsSessionZero** function to determine whether the current job was issued in session 0. Such a driver can use this information to enable it to present user interface elements in the user's session, rather than in session zero. A related function, [SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession), displays a standard Windows message box in the user's session.

If you plan to use this function in a driver intended to run under Windows 2000, you must load spoolss.dll by a call to the **LoadLibrary** function, and then find the address of this function within that DLL by a call to the **GetProcAddress** function. If the call to **GetProcAddress** fails, you must use an alternative mechanism to display user interface elements.

## See also

[SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession)