# vDbgPrintEx function

## Description

The **vDbgPrintEx** routine sends a string to the kernel debugger if certain conditions are met.

## Parameters

### `ComponentId` [in]

The component that is calling this routine. This parameter must be one of the component name filter IDs that are defined in Dpfilter.h. To avoid mixing your driver's output with the output of Windows components, you should use only the following values for *ComponentId*:

* DPFLTR_IHVVIDEO_ID
* DPFLTR_IHVAUDIO_ID
* DPFLTR_IHVNETWORK_ID
* DPFLTR_IHVSTREAMING_ID
* DPFLTR_IHVBUS_ID
* DPFLTR_IHVDRIVER_ID

### `Level` [in]

The severity of the message that is being sent. This parameter can be any 32-bit integer. Values between 0 and 31 (inclusive) are treated differently than values between 32 and 0xFFFFFFFF. For more information about how the values are treated, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

### `Format` [in]

A pointer to the format string to print. The *Format* string supports most of the **printf**-style formatting codes. However, you can use the Unicode format codes (**%C**, **%S**, **%lc**, **%ls**, **%wc**, **%ws**, and **%wZ**) only with IRQL = PASSIVE_LEVEL. The **vDbgPrintEx** routine does not support any of the floating point types (**%f**, **%e**, **%E**, **%g**, **%G**, **%a**, or **%A**).

### `arglist` [in]

An argument list for the format string. The **vDbgPrintEx** routine uses this list in the same way that **vprintf** does.

## Return value

**vDbgPrintEx** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine returns the appropriate error code.

## Remarks

Only kernel-mode drivers can call the **vDbgPrintEx** routine.

**vDbgPrintEx** can be called at IRQL <= DIRQL. However, you can use Unicode format codes (%**wc** and %**ws**) only at IRQL = PASSIVE_LEVEL. Also, because the debugger uses interprocess interrupts (IPIs) to communicate with other processors, calling **vDbgPrintEx** at IRQL > DIRQL can cause deadlocks.

**vDbgPrintEx** either passes the string that it creates to the kernel debugger or does nothing at all, depending on the values of *ComponentId*, *Level*, and the corresponding component filter masks. For more information about what **vDbgPrintEx** does, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

Unless it is absolutely necessary, you should not obtain a string from user input or another process and pass it to **vDbgPrintEx**. If you do use a string that you did not create, you must verify that this string is a valid format string and that the format codes match the argument list in type and quantity. The best coding practice is for all *Format* strings to be static and defined at compile time.

There is no upper limit to the size of the *Format* string or the number of arguments in the *arglist* list. However, any single call to **vDbgPrintEx** will transmit only 512 bytes of information.

There is also a limit to the size of the buffer that the debugger uses. For more information about this limit, see [The DbgPrint Buffer and the Debugger](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

This routine is defined in Wdm.h. Component filter IDs are defined in Dpfilter.h.

## See also

[DbgPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)