# PoFxRegisterPluginEx function (pep_x.h)

## Description

The **PoFxRegisterPluginEx** routine registers a platform extension plug-in (PEP) with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Parameters

### `PepInformation` [in]

A pointer to a [PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information) structure that contains pointers to one or more callback routines that are implemented by the PEP. These routines handle notifications that are sent to the PEP by PoFx.

### `Flags` [in]

A set of flag bits for configuring the PEP interface. Set this member to zero or to the following value.

| Flag bit | Description |
| --- | --- |
| PEP_FLAG_WORKER_CONCURRENCY |  |

### `KernelInformation` [in, out]

A pointer to a [PEP_KERNEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_kernel_information_struct_v1) structure.

## Return value

**PoFxRegisterPluginEx** returns STATUS_SUCCESS if the call successfully registers the PEP. Possible error return values include the following status codes.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | The **Version** or **Size** member of the **PEP_KERNEL_INFORMATION** structure is set to an invalid value; or the **AcceptDeviceNotification** member of this structure is set to NULL. |
| STATUS_INVALID_PEP_INFO_VERSION | The **Version** member of the **PEP_INFORMATION** structure is set to an invalid value. |
| STATUS_INSUFFICIENT_RESOURCES | Unable to allocate the resources required to complete the requested registration. |

## Remarks

A PEP calls this routine to register itself with PoFx.

A PEP cannot unregister, and cannot register twice. If the PEP must be serviced, the operating system must restart.

The [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) routine is similar to **PoFxRegisterPluginEx**, except that it does not take a *Flags* parameter.

The PEP must call **PoFxRegisterPluginEx** at IRQL = PASSIVE_LEVEL.

## See also

[PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information)

[PEP_KERNEL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_kernel_information_struct_v1)

[PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)