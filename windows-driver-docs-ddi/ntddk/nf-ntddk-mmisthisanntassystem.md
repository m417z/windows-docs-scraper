# MmIsThisAnNtAsSystem function

## Description

The **MmIsThisAnNtAsSystem** routine is obsolete for Windows XP and later versions of Windows. Use [RtlGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetversion) or [RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo) instead.

The **MmIsThisAnNtAsSystem** routine checks whether the current platform is running a server version of the NT-based operating system.

## Return value

If the current platform is a server, **MmIsThisAnNtAsSystem** returns **TRUE**.

## Remarks

Drivers can use this routine during initialization, along with **MmQuerySystemSize**, for sizing estimates of how many resources to allocate. For example, if **MmIsThisAnNtAsSystem** returns **TRUE**, the caller can increase the number of threads or the number of initially allocated entries for a lookaside list that it creates in medium and large systems.

## See also

[MmQuerySystemSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmquerysystemsize)