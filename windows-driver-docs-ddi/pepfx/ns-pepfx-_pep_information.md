# _PEP_INFORMATION structure (pepfx.h)

## Description

The **PEP_INFORMATION** structure specifies the interface that the platform extension plug-in (PEP) uses to receive notifications from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Members

### `Version`

The current version number for this structure. Set this member to PEP_INFORMATION_VERSION.

### `Size`

The size, in bytes, of this structure. Set this member to **sizeof**(**PEP_INFORMATION**).

### `AcceptDeviceNotification`

A pointer to an [AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm) callback routine. This member is required to point to a valid callback routine.

### `AcceptProcessorNotification`

A pointer to an [AcceptProcessorNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyppm) callback routine. This member is optional and can be NULL if the PEP is not prepared to handle PPM notifications from PoFx.

### `AcceptAcpiNotification`

A pointer to an [AcceptAcpiNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyacpi) callback routine. This member is optional and can be NULL if the PEP is not prepared to handle ACPI notifications from PoFx.

## Remarks

This structure contains pointers to several callback routines that are implemented by the PEP. PoFx calls these routines to send notifications to the PEP.

The *PepInformation* parameter to the [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) and [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routines is a pointer to a **PEP_INFORMATION** structure.

## See also

[AcceptAcpiNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyacpi)

[AcceptDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifydpm)

[AcceptProcessorNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pepcallbacknotifyppm)

[PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)

[PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)