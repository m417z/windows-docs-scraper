# SHOWUIPARAMS structure

## Description

The [SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession) function uses the SHOWUIPARAMS structure to hold information about the appearance and behavior of a message box.

## Members

### `UIType`

Specifies the type of user interface element. This member can be set to a single value: **kMessageBox**.

### `MessageBoxParams`

Specifies a [MESSAGEBOX_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-messagebox_params) structure that contains the information about the message box.

## See also

[MESSAGEBOX_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-messagebox_params)

[SplPromptUIInUsersSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-splpromptuiinuserssession)