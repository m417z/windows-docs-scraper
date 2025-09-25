# SplPromptUIInUsersSession function

## Description

The `SplPromptUIInUsersSession` function displays a standard message box in the session indicated by the printer handle and job ID.

## Parameters

### `hPrinter` [in]

Handle to the printer.

### `JobId` [in]

Specifies the print job.

### `pUIParams` [in]

Pointer to a [SHOWUIPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-showuiparams) structure that contains values that determine the appearance and behavior of the message box.

### `pResponse` [out]

Pointer to a memory location that contains either the user's response or the IDASYNC constant. For more information, see the Remarks section.

## Return value

On success, the `SplPromptUIInUsersSession` function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

If *pUIParams* ->**bWait** is **FALSE**, this function returns immediately without waiting for the user's response. In that case, **pResponse* is set to IDASYNC.

If you plan to use this function in a driver intended to run under Windows 2000, you must load spoolss.dll by a call to the **LoadLibrary** function, and then find the address of this function within that DLL by a call to the **GetProcAddress** function. (**LoadLibrary** and **GetProcAddress** are described in the Microsoft Windows SDK documentation.) If the call to **GetProcAddress** fails, you must use an alternative mechanism to display user interface elements.

## See also

[SHOWUIPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-showuiparams)

[SplIsSessionZero](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splissessionzero)