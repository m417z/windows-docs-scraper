# KeQueryMaximumGroupCount function (wdm.h)

## Description

The **KeQueryMaximumGroupCount** routine returns the maximum number of groups in a multiprocessor system.

## Return value

**KeQueryMaximumGroupCount** returns the maximum number of groups.

## Remarks

The value that is returned by **KeQueryMaximumGroupCount** remains constant during runtime. This value depends on the hardware configuration of the multiprocessor system, but it can never exceed a fixed limit that is set by the Windows operating system.

In Windows 7, the maximum number of groups in a multiprocessor system is four, but this value might change in future versions of Windows. The safest way to determine the maximum number of groups in Windows 7 or a later versions of the Windows operating system is to call **KeQueryMaximumGroupCount**. Kernel-mode drivers that call **KeQueryMaximumGroupCount** will not require code changes if the formula that is used to calculate the maximum number of groups changes in a future version of Windows.

To obtain the number of active groups in a multiprocessor system, call the [KeQueryActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactivegroupcount) routine.

## See also

[KeQueryActiveGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequeryactivegroupcount)