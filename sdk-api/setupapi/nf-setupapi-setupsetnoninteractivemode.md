# SetupSetNonInteractiveMode function

## Description

The **SetupSetNonInteractiveMode** function sets a non-interactive SetupAPI flag that determines whether SetupAPI can interact with a user in the caller's context.

## Parameters

### `NonInteractiveFlag` [in]

The Boolean value of the non-interactive flag. If *NonInteractive* is set to **TRUE**, SetupAPI runs in a non-interactive user mode and if *NonInteractive* is set to **FALSE**, SetupAPI runs in an interactive user mode.

## Return value

**SetupSetNonInteractiveMode** returns the previous setting of the non-interactive flag.

## Remarks

Installation applications and [co-installers](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-co-installer) can use this function to control whether SetupAPI can display interactive user interface elements, such as dialog boxes, in the caller's context.

An installation application or an installer can call [SetupGetNonInteractiveMode](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetnoninteractivemode) to retrieve the current value of the non-interactive flag.

## See also

[SetupGetNonInteractiveMode](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetnoninteractivemode)