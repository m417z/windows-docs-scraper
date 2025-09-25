# PsSetLoadImageNotifyRoutineEx function

## Description

The **PsSetLoadImageNotifyRoutineEx** routine registers a driver-supplied callback that is subsequently notified whenever an image (for example, a DLL or EXE) is loaded (or mapped into memory).

## Parameters

### `NotifyRoutine` [in]

A pointer to the caller-implemented [PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine) callback routine for load-image notifications.

### `Flags` [in]

Supplies a bitmask of flags that control the callback function. Here are the possible values:

* PS_IMAGE_NOTIFY_CONFLICTING_ARCHITECTURE indicates that the callback routine should be invoked for all potentially executable images, including images that have a different architecture from the native architecture of the operating system.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback was successfully registered. |
| **STATUS_INVALID_PARAMETER_2** | Invalid flag was supplied in *Flags*. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed allocate a callback block due to lack of resources. |

## Remarks

Highest-level system-profiling drivers can call **PsSetLoadImageNotifyRoutineEx** to set up their load-image notify routines (see [PLOAD_IMAGE_NOTIFY_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pload_image_notify_routine)).

The maximum number of drivers that can be simultaneously registered to receive load-image notifications is 64. If the maximum number of load-image notify routines is already registered when a driver calls **PsSetLoadImageNotifyRoutineEx** to try to register an additional notify routine, **PsSetLoadImageNotifyRoutineEx** fails and returns STATUS_INSUFFICIENT_RESOURCES.

A driver must remove any callbacks it registers before it unloads. You can remove the callback by calling the [PsRemoveLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psremoveloadimagenotifyroutine) routine.