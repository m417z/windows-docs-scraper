# IoGetTopLevelIrp function (ntifs.h)

## Description

The **IoGetTopLevelIrp** routine returns the value of the **TopLevelIrp** field of the current thread.

## Return value

**IoGetTopLevelIrp** returns the value of the **TopLevelIrp** field of the current thread.

## Remarks

**IoGetTopLevelIrp** can return **NULL**, an arbitrary file-system-specific value (such as a pointer to the current IRP), or one of the flags listed in the following table.

If the current thread holds no resources above the file system, **IoGetTopLevelIrp** returns **NULL**.

If the file system is the top-level component for the current thread, **IoGetTopLevelIrp** returns a pointer to the current IRP.

If a component other than the file system is the top-level component for the current thread, **IoGetTopLevelIrp** returns one of the following flags:

| Flag | Meaning |
| --- | --- |
| FSRTL_FSP_TOP_LEVEL_IRP | This is a recursive call. |
| FSRTL_CACHE_TOP_LEVEL_IRP | The cache manager is the top-level component for the current thread. |
| FSRTL_MOD_WRITE_TOP_LEVEL_IRP | The modified page writer is the top-level component for the current thread. |
| FSRTL_FAST_IO_TOP_LEVEL_IRP | The cache manager is the top-level component for the current thread, and the current thread is in a fast I/O path. |

## See also

[IoSetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosettoplevelirp)