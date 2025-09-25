## Description

The **DbgPrint** routine sends a message to the kernel debugger when the conditions that you specify apply (see the **Remarks** section below).

## Parameters

### `Format`

Specifies a pointer to the format string to print. The *Format* string supports most of the **printf**-style [format specification fields](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions). However, the Unicode format codes (**%C**, **%S**, **%lc**, **%ls**, **%wc**, **%ws**, and **%wZ**) can only be used with IRQL = PASSIVE_LEVEL. The **DbgPrint** routine does not support any of the floating point types (**%f**, **%e**, **%E**, **%g**, **%G**, **%a**, or **%A**).

### `...`

Specifies arguments for the format string, as in **printf**.

## Return value

If successful, **DbgPrint** returns the NTSTATUS code STATUS_SUCCESS; otherwise it returns the appropriate error code.

## Remarks

**DbgPrint** and **DbgPrintEx** can be called at IRQL<=DIRQL. However, Unicode format codes (**%C**, **%S**, **%lc**, **%ls**, **%wc**, **%ws**, and **%wZ**) can be used only at IRQL=PASSIVE_LEVEL. Also, because the debugger uses interprocess interrupts (IPIs) to communicate with other processors, calling **DbgPrint** at IRQL>DIRQL can cause deadlocks.

Only kernel-mode drivers can call the **DbgPrint** routine.

**DbgPrint** sends a message only if certain conditions apply. Specifically, it behaves like the [DbgPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex) routine with the DEFAULT component and a message importance level of DPFLTR_INFO_LEVEL. In other words, the following two function calls are identical:

```cpp
DbgPrint ( Format, arguments )

DbgPrintEx ( DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, Format, arguments )
```

For more information about message filtering, components, and message importance level, see [Reading and Filtering Debugging Messages](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages).

It is recommended that you use **DbgPrintEx** instead of **DbgPrint**, since this allows you to control the conditions under which the message is sent.

Unless it is absolutely necessary, you should not obtain a string from user input or another process and pass it to **DbgPrint**. If you do use a string that you did not create, you must verify that this is a valid format string, and that the format codes match the argument list in type and quantity. The best coding practice is for all *Format* strings to be static and defined at compile time.

There is no upper limit to the size of the *Format* string or the number of arguments. However, any single call to **DbgPrint** will only transmit 512 bytes of information. There is also a limit to the size of the DbgPrint buffer. See [DbgPrint Buffer and the Debugger](https://learn.microsoft.com/windows-hardware/drivers/devtest/reading-and-filtering-debugging-messages) for details.

## See also

[DbgPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprintex)

[KdPrint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprint)

[KdPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kdprintex)