# DbgPrintEx function

## Description

The **DbgPrintEx** routine sends a string to the kernel debugger if the conditions you specify are met.

## Parameters

### `ComponentId` [in]

Specifies the component calling this routine. This must be one of the component name filter IDs defined in the Dpfilter.h header file. To avoid mixing your driver's output with the output of Windows components, you should use only the following values for *ComponentId*:

* DPFLTR_IHVVIDEO_ID
* DPFLTR_IHVAUDIO_ID
* DPFLTR_IHVNETWORK_ID
* DPFLTR_IHVSTREAMING_ID
* DPFLTR_IHVBUS_ID
* DPFLTR_IHVDRIVER_ID

### `Level` [in]

Specifies the severity of the message being sent. This can be any 32-bit integer. Values between 0 and 31 (inclusive) are treated differently than values between 32 and 0xFFFFFFFF. For details, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

### `Format` [in]

Specifies a pointer to the format string to print. The *Format* string supports most of the **printf**-style [format specification fields](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions). However, the Unicode format codes (**%C**, **%S**, **%lc**, **%ls**, **%wc**, **%ws**, and **%wZ**) can only be used with IRQL = PASSIVE_LEVEL. The **DbgPrintEx** routine does not support any of the floating point types (**%f**, **%e**, **%E**, **%g**, **%G**, **%a**, or **%A**).

### `...`

Specifies arguments for the format string, as in **printf**.

## Return value

If successful, **DbgPrintEx** returns the NTSTATUS code STATUS_SUCCESS; otherwise, it returns the appropriate error code.

## Remarks

Only kernel-mode drivers can call the **DbgPrintEx** routine.

**DbgPrint** and **DbgPrintEx** can be called at IRQL<=DIRQL. However, Unicode format codes (**%wc** and **%ws**) can be used only at IRQL = PASSIVE_LEVEL. Also, because the debugger uses interprocess interrupts (IPIs) to communicate with other processors, calling **DbgPrint** at IRQL>DIRQL can cause deadlocks.

**DbgPrintEx** either passes the specified string to the kernel debugger or does nothing at all, depending on the values of *ComponentId*, *Level*, and the corresponding component filter masks. For details, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

Unless it is absolutely necessary, you should not obtain a string from user input or another process and pass it to **DbgPrintEx**. If you do use a string that you did not create, you must verify that this is a valid format string, and that the format codes match the argument list in type and quantity. The best coding practice is for all *Format* strings to be static and defined at compile time.

There is no upper limit to the size of the *Format* string or the number of arguments. However, any single call to **DbgPrintEx** will only transmit 512 bytes of information. There is also a limit to the size of the DbgPrint buffer. See [The DbgPrint Buffer and the Debugger](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages) for details.

## See also

[DbgPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint)

[KdPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprint)

[KdPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprintex)

[vDbgPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-vdbgprintex)