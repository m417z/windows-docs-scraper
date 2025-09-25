# RtlIsNtDdiVersionAvailable function

## Description

>[!WARNING]
> The **RtlIsNtDdiVersionAvailable** routine is obsolete. Use [**RtlVerifyVersionInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo) instead.

The **RtlIsNtDdiVersionAvailable** routine determines if a specified version of the Microsoft Windows device driver interface (DDI) is available.

## Parameters

### `Version` [in]

The version of the Windows DDI that is available. The following table lists the possible values for the *Version* parameter.

| Constant | Windows version |
| --- | --- |
| NTDDI_WIN10 | Windows 11\ Windows 10 |
| NTDDI_WINBLUE | Windows 8.1 |
| NTDDI_WIN8 | Windows 8 |
| NTDDI_WIN7 | Windows 7 |
| NTDDI_WS08 | Windows Server 2008 |
| NTDDI_VISTA | Windows Vista |
| NTDDI_WS03 | Windows Server 2003 |
| NTDDI_WINXP | Windows XP |
| NTDDI_WIN2K | Windows 2000 |

The NTDDI_*XXX* constants are defined in the Sdkddkver.h header file.

Additional NTDDI_*XXX* constants that specify service packs are available for the [RtlIsServicePackVersionInstalled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlisservicepackversioninstalled) routine. Do not use these values for **RtlIsNtDdiVersionAvailable**.

## Return value

**RtlIsNtDdiVersionAvailable** returns **TRUE** if the version of the Windows operating system that is running is the same or later than the version that the *Version* parameter specifies. Otherwise, this routine returns **FALSE**.

## Remarks

The **RtlIsNtDdiVersionAvailable** routine compares the version that the *Version* parameter specifies to the version of the Windows operating system that is currently running.

Use the [RtlIsServicePackVersionInstalled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlisservicepackversioninstalled) routine if you want to determine whether a particular service pack is installed.

The Windows kernel implements **RtlIsNtDdiVersionAvailable** only in Windows Vista and later versions of Windows. However, a compatibility library, Rtlver.lib, implements a version of **RtlIsNtDdiVersionAvailable** that runs in Windows 2000 and later versions of Windows. For kernel-mode drivers that include the Wdm.h header file, calls to **RtlIsNtDdiVersionAvailable** go to the version of this routine that is implemented in Rtlver.lib.

For more information about **RtlIsNtDdiVersionAvailable** and **RtlIsServicePackVersionInstalled**, see [Writing Drivers for Different Versions of Windows](https://learn.microsoft.com/windows-hardware/drivers/gettingstarted/platforms-and-driver-versions).

## See also

[RtlIsServicePackVersionInstalled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlisservicepackversioninstalled)

[**RtlVerifyVersionInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo)