# ExGetPreviousMode function

## Description

The **ExGetPreviousMode** routine returns the previous processor mode for the current thread.

## Return value

**ExGetPreviousMode** returns a **KPROCESSOR_MODE** value, one of **KernelMode** or **UserMode**. This value specifies the previous processor mode for the current thread.

## Remarks

If an I/O request can originate either in user mode or kernel mode and the caller passes pointers to data structures used for I/O, the driver must be able to determine whether the caller's pointers are valid in user mode or kernel mode.

If drivers are processing I/O requests using the normal IRP-based I/O dispatch method, they can determine the previous processor mode by checking the *RequestorMode* parameter in the IRP header. (The *RequestorMode* parameter is set by the I/O manager.)

Alternatively, **ExGetPreviousMode** can be used to determine the previous processor mode. This routine is particularly useful in situations where a previous mode parameter is not available, for example, in a file driver that uses fast I/O.

## See also

[KeGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentthread)