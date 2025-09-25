# POFXCALLBACKREQUESTWORKER callback function (pep_x.h)

## Description

The **RequestWorker** routine is called by a platform extension plug-in (PEP) to inform the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) that the platform extension plug-in (PEP) has a work request to submit on behalf of the specified device.

## Parameters

### `PluginHandle` [in]

A POHANDLE value that represents the registration of the device with PoFx. The PEP previously received this handle from PoFx during the [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification that informed the PEP that the device's driver stack registered the device with PoFx.

## Remarks

This routine is implemented by PoFx and is called by the PEP. The **RequestWorker** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to a **RequestWorker** routine.

Each time the PEP calls this routine, PoFx responds by sending a [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services) notification to the PEP. This notification might be delayed if a worker thread is not immediately available to process the work request.

A PEP can call this routine at IRQL <= DISPATCH_LEVEL.

## See also

[PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)