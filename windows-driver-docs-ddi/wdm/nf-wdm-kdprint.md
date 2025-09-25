## Description

The **KdPrint** macro sends a message to the kernel debugger.

**KdPrint** sends a message only if the conditions you specify apply. More info in the section below.

A call to **KdPrint** requires double parentheses.

## Parameters

### `_x_` [in]

Specifies a pointer to the format string to print. The _Format_ string supports most of the **printf**-style [format specification syntax](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions). However, the Unicode format codes (**%C**, **%S**, **%lc**, **%ls**, **%wc**, **%ws**, and **%wZ**) can only be used with IRQL = PASSIVE_LEVEL. The **KdPrint** routine does not support any of the floating point types (**%f**, **%e**, **%E**, **%g**, **%G**, **%a**, or **%A**).

## Remarks

**KdPrint** is identical to the **DbgPrint** routine in code that is compiled for a debug configuration. This routine has no effect if compiled for a release configuration. Only kernel-mode drivers can call the **KdPrint** routine.

**KdPrint** sends a message only if certain conditions apply. Specifically, it behaves like [KdPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprintex) with the DEFAULT component and a message importance level of DPFLTR_INFO_LEVEL. In other words, the following two function calls are identical:

`KdPrint (( Format, arguments ))`

`KdPrintEx (( DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, Format, arguments ))`

For more information about message filtering, components, and message importance level, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

Regardless of which version of Windows you are using, it is recommended that you use **KdPrintEx** instead of **KdPrint**, since **KdPrintEx** allows you to control the conditions under which the message is sent.

Unless it is absolutely necessary, you should not obtain a string from user input or another process and pass it to **KdPrint**. If you do use a string that you did not create, you must verify that this is a valid format string, and that the format codes match the argument list in type and quantity. The best coding practice is for all _Format_ strings to be static and defined at compile time.

There is no upper limit to the size of the _Format_ string or the number of arguments. However, any single call to **KdPrint** will only transmit 512 bytes of information. There is also a limit to the size of the [DbgPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint) buffer. See [The DbgPrint Buffer and the Debugger](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages) for details.

## See also

[DbgPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint)

[DbgPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)

[KdPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprintex)