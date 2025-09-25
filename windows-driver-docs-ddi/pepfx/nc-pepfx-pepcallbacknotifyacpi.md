# PEPCALLBACKNOTIFYACPI callback function (pepfx.h)

## Description

An *AcceptAcpiNotification* event callback routine handles ACPI notifications from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Parameters

### `Notification` [in]

The ACPI notification ID. This parameter specifies the type of ACPI notification that PoFx is sending. For a list of ACPI notification IDs, see [ACPI notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/acpi-notifications).

### `Data` [in, out, optional]

A pointer to a PoFx-allocated structure that contains the input and/or output data for this notification. The type of this structure depends on the notification ID specified by *Notification*. For a list of the structure types that are defined for the various ACPI notification IDs, see [ACPI notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Return value

The *AcceptAcpiNotification* routine must return TRUE if it handles the notification, or FALSE if it does not.

## Remarks

This routine is implemented by the platform extension plug-in (PEP) for a device. The **AcceptAcpiNotification** member of the [PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information) structure is a pointer to an *AcceptAcpiNotification* routine. The PEP calls the [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) or [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routine to register the PEP's *AcceptAcpiNotification* routine with PoFx.

The IRQL at which the PEP's *AcceptAcpiNotification* routine is called varies according to the type of notification that is being sent. The notification type is specified by the *Notification* parameter. For more information about the IRQL at which each notification type is sent, see the individual reference pages under [ACPI notifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information)

[PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)

[PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)