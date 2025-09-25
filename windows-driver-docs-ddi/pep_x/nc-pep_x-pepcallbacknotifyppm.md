# PEPCALLBACKNOTIFYPPM callback function (pep_x.h)

## Description

An *AcceptProcessorNotification* event callback routine handles processor power management (PPM) notifications from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Parameters

### `Handle` [in]

The device handle for the PEP for the target processor. If **NULL**, the notification does not target a specific processor.

### `Notification` [in]

The PPM notification ID. This parameter specifies the type of PPM notification that PoFx is sending. For a list of PPM notification IDs, see [Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `Data` [in, out, optional]

A pointer to a PoFx-allocated structure that contains the input and/or output data for this notification. The type of this structure depends on the notification ID specified by *Notification*. For a list of the structure types that are defined for the various PPM notification IDs, see [Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Return value

The *AcceptProcessorNotification* routine must return TRUE if it handles the notification, or FALSE if it does not.

## Remarks

This routine is implemented by the platform extension plug-in (PEP) for a processor. The **AcceptProcessorNotification** member of the [PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information) structure is a pointer to an *AcceptProcessorNotification* routine. The PEP calls the [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) or [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routine to register the PEP's *AcceptProcessorNotification* routine with PoFx.

The IRQL at which the PEP's *AcceptProcessorNotification* routine is called varies according to the type of notification that is being sent. The context in which this interface is called ranges from PASSIVE_LEVEL to HIGH_LEVEL with interrupts disabled. For more information about the IRQL at which each notification type is sent, see the individual reference pages under [Processor power management (PPM) notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information)

[PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)

[PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)