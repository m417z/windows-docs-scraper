# IoSetTopLevelIrp function (wdm.h)

## Description

The **IoSetTopLevelIrp** routine sets the value of the **TopLevelIrp** field of the current thread.

## Parameters

### `Irp` [in, optional]

I/O request packet (IRP) pointer to be stored in the **TopLevelIrp** field of the current thread.

## Remarks

**IoSetTopLevelIrp** sets the value of the **TopLevelIrp** field in the thread object for the current thread. This value can be **NULL**, a pointer to the current IRP, or an FSRTL flag. For more information about these values and what they mean, see the reference entry for [IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp).

Only file systems can call **IoSetTopLevelIrp**. File system filters and minifilters cannot safely call this routine, because doing so can cause deadlocks.

## See also

[IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp)