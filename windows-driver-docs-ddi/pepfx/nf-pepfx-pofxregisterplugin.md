# PoFxRegisterPlugin function (pepfx.h)

## Description

The **PoFxRegisterPlugin** routine registers a platform extension plug-in (PEP) with the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework) (PoFx).

## Parameters

### `PepInformation` [in]

A pointer to a [PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information) structure.

### `KernelInformation` [in, out]

A pointer to a [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure.

## Return value

**PoFxRegisterPlugin** returns STATUS_SUCCESS if the call successfully registers the PEP. Possible error return values include the following status codes.

|Return value|Description|
|----|----|
|STATUS_INVALID_PARAMETER|The **Version** or **Size** member of the **PEP_KERNEL_INFORMATION** structure is set to an invalid value; or the **AcceptDeviceNotification** member of this structure is set to NULL.|
|STATUS_INVALID_PEP_INFO_VERSION|The **Version** member of the **PEP_INFORMATION** structure is set to an invalid value.|
|STATUS_INSUFFICIENT_RESOURCES|Unable to allocate the resources required to complete the requested registration.|

## Remarks

A PEP calls this routine to register itself with PoFx.

A PEP cannot unregister, and cannot register twice. If the PEP must be serviced, the operating system must restart.

The [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routine is similar to **PoFxRegisterPlugin**, except that it takes an additional parameter, *Flags*.

The PEP must call **PoFxRegisterPlugin** at IRQL = PASSIVE_LEVEL.

## See also

[PEP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_information)

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)