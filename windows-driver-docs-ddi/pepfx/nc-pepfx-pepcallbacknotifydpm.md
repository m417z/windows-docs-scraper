# PEPCALLBACKNOTIFYDPM callback function (pepfx.h)

## Description

An *AcceptDeviceNotification* event callback routine handles device power management (DPM) notifications from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Parameters

### `Notification` [in]

The DPM notification ID. This parameter specifies the type of DPM notification that PoFx is sending. For a list of DPM notification IDs, see [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications).

### `Data` [in, out, optional]

A pointer to a PoFx-allocated structure that contains the input and/or output data for this notification. The type of this structure depends on the notification ID specified by *Notification*. For a list of the structure types that are defined for the various DPM notification IDs, see [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications).

## Return value

The *AcceptDeviceNotification* routine must return TRUE if it handles the notification, or FALSE if it does not.

## Remarks

This routine is implemented by the platform extension plug-in (PEP) for a device. The **AcceptDeviceNotification** member of the [PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information) structure is a pointer to an *AcceptDeviceNotification* routine. The PEP calls the [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) or [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routine to register the PEP's *AcceptDeviceNotification* routine with PoFx.

PoFx calls this routine to send a DPM notification to the PEP. In this call, the *Notification* parameter specifies the type of notification, and the *Data* parameter points to a data structure of the type that is associated with this notification. For a list of DPM notification IDs and their associated structure types, see [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications).

DPM notifications inform the PEP about various system, device, or componentÂ–-level events, or pass requests from the device driver to the PEP.

The *AcceptDeviceNotification* routine does not have to accept every request from the device driver—for example, it can ignore idle residency hints. However, the PEP must understand and accept most device power management notifications even if the PEP chooses not to act on them. The PEP must refuse to handle (by returning FALSE) every notification that it does not recognize.

The *AcceptDeviceNotification* routine can be called at IRQL <= DISPATCH_LEVEL. The IRQL at which the PEP's *AcceptAcpiNotification* routine is called varies according to the type of notification that is being sent. The notification type is specified by the *Notification* parameter. For more information, see the individual reference pages under [Device power management (DPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/dpm-notifications).

## See also

[PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information)

[PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)

[PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)