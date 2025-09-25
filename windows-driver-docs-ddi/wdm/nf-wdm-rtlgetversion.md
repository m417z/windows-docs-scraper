# RtlGetVersion function

## Description

The **RtlGetVersion** routine returns version information about the currently running operating system.

## Parameters

### `lpVersionInformation` [out]

Pointer to either a [RTL_OSVERSIONINFOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfow) structure or a [RTL_OSVERSIONINFOEXW](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_osversioninfoexw) structure that contains the version information about the currently running operating system. A caller specifies which input structure is used by setting the **dwOSVersionInfoSize** member of the structure to the size in bytes of the structure that is used.

## Return value

**RtlGetVersion** returns STATUS_SUCCESS.

## Remarks

**RtlGetVersion** is the kernel-mode equivalent of the user-mode **GetVersionEx** function in the Windows SDK. See the example in the Windows SDK that shows how to get the system version.

When using **RtlGetVersion** to determine whether a particular version of the operating system is running, a caller should check for version numbers that are greater than or equal to the required version number. This ensures that a version test succeeds for later versions of Windows.

Because operating system features can be added in a redistributable DLL, checking only the major and minor version numbers is not the most reliable way to verify the presence of a specific system feature. A driver should use [RtlVerifyVersionInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlverifyversioninfo) to test for the presence of a specific system feature.

## See also

[PsGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psgetversion)