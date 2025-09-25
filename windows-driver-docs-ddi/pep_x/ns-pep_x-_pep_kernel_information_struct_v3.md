# _PEP_KERNEL_INFORMATION_STRUCT_V3 structure (pep_x.h)

## Description

The **PEP_KERNEL_INFORMATION** structure specifies the interface that the power extension plug-in (PEP) uses to request services from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Members

### `Version`

The current version number for this structure. Set this member to PEP_KERNEL_INFORMATION_VERSION.

### `Size`

The size, in bytes, of this structure. Set this member to **sizeof**(**PEP_KERNEL_INFORMATION**).

### `Plugin`

The handle assigned to the PEP's registration with PoFx. PoFx sets the value of this member. The PEP uses this handle in calls to the [RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker) routine.

### `RequestWorker`

A pointer to a [RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker) routine. PoFx sets the value of this member. The **RequestWorker** routine is implemented by PoFx. The PEP calls this routine to request the use of a worker thread from the operating system.

### `EnumerateUnmaskedInterrupts`

A pointer to an [EnumerateUnmaskedInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackenumerateunmaskedinterrupts) routine. PoFx sets the value of this member. The **EnumerateUnmaskedInterrupts** routine is implemented by PoFx. The PEP calls this routine to request information about the unmasked interrupts.

### `ProcessorHalt`

A pointer to a [ProcessorHalt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessorhalt) routine. PoFx sets the value of this member. The **ProcessorHalt** routine is implemented by PoFx. The PEP calls this routine to prepare the current processor to enter the halted state.

### `RequestInterrupt`

A pointer to a [RequestInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestinterrupt) routine. PoFx sets the value of this member. The **RequestInterrupt** routine is implemented by PoFx. The PEP calls this routine to replay an edge-triggered interrupt that might have been lost after the hardware platform entered a low-power system state.

### `TransitionCriticalResource`

A pointer to a [TransitionCriticalResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackcriticalresource) routine. PoFx sets the value of this member. The **TransitionCriticalResource** routine is implemented by PoFx. The PEP calls this routine to transition critical system resources to the idle condition.

### `ProcessorIdleVeto`

A pointer to a [ProcessorIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessoridleveto) routine. PoFx sets the value of this member. The **ProcessorIdleVeto** routine is implemented by PoFx. The PEP calls this routine to increment or decrement the veto count for a pending transition to a processor idle state.

### `PlatformIdleVeto`

A pointer to a [PlatformIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackplatformidleveto) routine. PoFx sets the value of this member. The **PlatformIdleVeto** routine is implemented by PoFx. The PEP calls this routine to increment or decrement the veto count for a pending transition to a platform idle state.

### `UpdateProcessorIdleState`

A pointer to an [UpdateProcessorIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateprocessoridlestate) routine. PoFx sets the value of this member. The **UpdateProcessorIdleState** routine is implemented by PoFx. The PEP calls this routine to update the properties of the specified processor idle state.

### `UpdatePlatformIdleState`

A pointer to an [UpdatePlatformIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateplatformidlestate) routine. PoFx sets the value of this member. The **UpdatePlatformIdleState** routine is implemented by PoFx. The PEP calls this routine to update the properties of the specified platform idle state.

### `RequestCommon`

A pointer to a [RequestCommon](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestcommon) routine. PoFx sets the value of this member. The **RequestCommon** routine is implemented by PoFx. The PEP calls this routine to perform a processing operation that is specified by a request ID.

## Remarks

The **KernelInformation** parameter to the [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin) or [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex) routine is a pointer to a **PEP_KERNEL_INFORMATION** structure. The PEP allocates this structure and sets the values of the **Version** and **Size** members of this structure before calling **PoFxRegisterPlugin** or **PoFxRegisterPluginEx**. During the call to this routine, PoFx fills in the remaining members of the structure.

## See also

- [EnumerateUnmaskedInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackenumerateunmaskedinterrupts)
- [PlatformIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackplatformidleveto)
- [PoFxRegisterPlugin](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterplugin)
- [PoFxRegisterPluginEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nf-pepfx-pofxregisterpluginex)
- [ProcessorHalt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessorhalt)
- [ProcessorIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessoridleveto)
- [RequestCommon](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestcommon)
- [RequestInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestinterrupt)
- [RequestWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackrequestworker)
- [TransitionCriticalResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackcriticalresource)
- [UpdatePlatformIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateplatformidlestate)
- [UpdateProcessorIdleState](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackupdateprocessoridlestate)