# MESSAGEBOX_PARAMS structure

## Description

The MESSAGEBOX_PARAMS structure is used by the [SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession) function to hold information about the appearance and behavior of a message box.

## Members

### `cbSize`

Specifies the size, in bytes, of this structure.

### `pTitle`

Pointer to a null-terminated string that is used in the title bar of the message box.

### `pMessage`

Pointer to a null-terminated string that contains the message to display.

### `Style`

Specifies the contents and behavior of the message box. For a complete list of the values to which this member can be set, see the description of the **MessageBox** function in the Microsoft Windows SDK documentation.

### `dwTimeout`

Specifies the time, in seconds, to wait for the user's response, provided that the **bWait** member is **TRUE**.

### `bWait`

Specifies whether the **SplPromptUIInUsersSession** function should wait for a user's response. If **bWait** is **TRUE**, **SplPromptUIInUsersSession** does not return until either the user responds or the time-out interval elapses. If **dwTimeout** is zero, **SplPromptUIInUsersSession** does not return until the user responds. If **bWait** is **FALSE**, the function returns immediately with **pResponse* set to IDASYNC.

## Remarks

One member of the [SHOWUIPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-showuiparams) structure is a MESSAGEBOX_PARAMS structure.

## See also

[SHOWUIPARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-showuiparams)

[SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession)