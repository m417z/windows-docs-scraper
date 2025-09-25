# PsSetLoadImageNotifyRoutine function

## Description

The **PsSetLoadImageNotifyRoutine** routine registers a driver-supplied callback that is subsequently notified whenever an image (for example, a DLL or EXE) is loaded (or mapped into memory).

## Parameters

### `NotifyRoutine` [in]

A pointer to the caller-implemented [PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine) callback routine for load-image notifications.

## Return value

**PsSetLoadImageNotifyRoutine** either returns STATUS_SUCCESS or it returns STATUS_INSUFFICIENT_RESOURCES if it failed the callback registration.

## Remarks

Highest-level system-profiling drivers can call **PsSetLoadImageNotifyRoutine** to set up their load-image notify routines (see [PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)).

The maximum number of drivers that can be simultaneously registered to receive load-image notifications is eight. If the maximum number of load-image notify routines is already registered when a driver calls **PsSetLoadImageNotifyRoutine** to try to register an additional notify routine, **PsSetLoadImageNotifyRoutine** fails and returns STATUS_INSUFFICIENT_RESOURCES.

**Notes**

* An update for Windows 8.1 increases the maximum number of drivers registered to receive load-image notifications from eight to 64. This update is installed as part of a cumulative update that is available through Windows Update starting on April 8, 2014. In addition, this cumulative update is available at [https://support.microsoft.com/kb/2919355](https://support.microsoft.com/help/2919355/windows-rt-8-1-windows-8-1-and-windows-server-2012-r2-update-april-201).
* Users of Windows 7 with Service Pack 1 (SP1) can install a hotfix to increase the maximum number of drivers registered to receive load-image notifications from 8 to 64. This hotfix is available at [https://support.microsoft.com/kb/2922790](https://support.microsoft.com/help/2922790/some-software-products-function-incorrectly-in-windows).

A driver must remove any callbacks it registers before it unloads. You can remove the callback by calling the [PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine) routine.

## See also

[PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)

[PsGetCurrentProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentprocessid)

[PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine)

[PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine)

[PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)