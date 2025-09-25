# SetupGetNonInteractiveMode function

## Description

The **SetupGetNonInteractiveMode** function returns the value of a SetupAPI non-interactive flag that indicates whether the caller's process can interact with a user through user interface components, such as dialog boxes.

## Return value

**SetupGetNonInteractiveMode** returns **TRUE** if the caller's process cannot display interactive user interface elements, such as dialog boxes. Otherwise, the function returns **FALSE**, which indicates that the process can display interactive user interface elements.

## Remarks

Installation applications and [co-installers](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-co-installer) can use this function to determine whether the current process can display interactive user interface elements such as dialog boxes. [SetupAPI](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi) runs a class installer or a co-installer either in an interactive or in a non-interactive process, depending on which [DIF code](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) SetupAPI is processing.

An installation application can call [SetupSetNonInteractiveMode](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetnoninteractivemode) to set the SetupAPI non-interactive flag that controls whether SetupAPI can display interactive user interface elements in the caller's context.

## See also

[SetupSetNonInteractiveMode](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetnoninteractivemode)