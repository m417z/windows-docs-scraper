# RtlIsServicePackVersionInstalled function

## Description

The **RtlIsServicePackVersionInstalled** routine determines if a specified service pack version of the Microsoft Windows device driver interface (DDI) is installed.

## Parameters

### `Version` [in]

The service pack version of the Windows DDI that is available. The following table lists the possible values for *Version*.

| Constant | Windows version |
| --- | --- |
| NTDDI_WIN7 | Windows 7 and Windows Server 2008 R2 |
| NTDDI_WS08SP2 | Windows Server 2008 with Service Pack 2 (SP2) |
| NTDDI_WS08 | Windows Server 2008 |
| NTDDI_VISTASP2 | Windows Vista with SP2 |
| NTDDI_VISTASP1 | Windows Vista with SP1 |
| NTDDI_VISTA | Windows Vista |
| NTDDI_WS03SP2 | Windows Server 2003 with SP2 |
| NTDDI_WS03SP1 | Windows Server 2003 with SP1 |
| NTDDI_WS03 | Windows Server 2003 |
| NTDDI_WINXPSP3 | Windows XP with SP3 |
| NTDDI_WINXPSP2 | Windows XP with SP2 |
| NTDDI_WINXPSP1 | Windows XP with SP1 |
| NTDDI_WINXP | Windows XP |
| NTDDI_WIN2KSP4 | Windows 2000 with SP4 |
| NTDDI_WIN2KSP3 | Windows 2000 with SP3 |
| NTDDI_WIN2KSP2 | Windows 2000 with SP2 |
| NTDDI_WIN2KSP1 | Windows 2000 with SP1 |
| NTDDI_WIN2K | Windows 2000 |

The NTDDI_*XXX* constants are defined in the Sdkddkver.h header file. The preceding table does not contain an entry for Windows Server 2008 with SP1. The first service pack to become available for Windows Server 2008 is SP2.

## Return value

**RtlIsServicePackVersionInstalled** returns **TRUE** if the service pack version of the Windows operating system that is running is the same or later than the version that the *Version* parameter specifies. Otherwise, this routine returns **FALSE**. **RtlIsServicePackVersionInstalled** also returns **FALSE** if the major version (for example, Windows Vista or Windows Server 2003) that *Version* specifies does not match the major version of Windows that is currently running on the computer.

## Remarks

The **RtlIsServicePackVersionInstalled** routine compares the version that the *Version* parameter specifies to the version of the currently running Windows operating system.

Use the [RtlIsNtDdiVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlisntddiversionavailable) routine to determine if a major version of Windows is running.

For more information about **RtlIsServicePackVersionInstalled** and **RtlIsNtDdiVersionAvailable**, see [Header File Changes in the Windows Driver Kit](https://learn.microsoft.com/windows-hardware/drivers/gettingstarted/header-files-in-the-windows-driver-kit).

The Windows kernel implements **RtlIsServicePackVersionInstalled** only in Windows Vista and later versions of Windows. However, a compatibility library, Rtlver.lib, implements a version of **RtlIsServicePackVersionInstalled** that runs in Windows 2000 and later versions of Windows. For kernel-mode drivers that include the Wdm.h header file, calls to **RtlIsServicePackVersionInstalled** go to the version of this routine that is implemented in Rtlver.lib.

## See also

[PsGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psgetversion)

[RtlIsNtDdiVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlisntddiversionavailable)

[RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo)