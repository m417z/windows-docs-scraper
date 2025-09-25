# POFXCALLBACKPROCESSORHALT callback function (pepfx.h)

## Description

The **ProcessorHalt** routine prepares the processor to be halted.

## Parameters

### `Flags` [in]

Flags that indicate the properties of the idle state that the processor will enter. The *Flags* parameter is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Flag name | Value | Description |
| --- | --- | --- |
| PROCESSOR_HALT_CACHE_FLUSH_OVERRIDE | 0x01 | The PEP's *Halt* callback routine is responsible for flushing the processor's caches. If this flag is not set, **ProcessorHalt** will flush the caches on entry to the processor idle state, and will invalidate the caches on exit from this state. |
| PROCESSOR_HALT_CACHE_COHERENT | 0x02 | Prepare the processor to enter an idle state in which the processor's caches will remain coherent. |
| PROCESSOR_HALT_CONTEXT_RETAINED | 0x04 | Prepare the processor to enter an idle state in which the processor's thread context will be preserved. |
| PROCESSOR_HALT_RETURN_NOT_SAFE | 0x08 | The PEP's *Halt* callback routine is guaranteed to not return. Set this flag if the *Halt* callback transitions the processor to a context-losing, power-gated state that cannot be canceled by hardware. When this flag is set, the operating system will treat a return from the *Halt* callback as a fatal error. |
| PROCESSOR_HALT_VIA_PSCI_CPU_SUSPEND | 0x16 |  |

### `Context` [in, out, optional]

A pointer to a PEP-defined processor-halt context. This pointer is passed as a parameter to the *Halt* callback routine. This context is opaque to the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

### `Halt` [in]

A pointer to a PEP-implemented *Halt* callback routine. PoFx calls this routine after preparations to halt the processor have been completed. During this callback, the PEP is expected to transition the processor to the *halted* state.

## Return value

**ProcessorHalt** returns STATUS_SUCCESS if the processor is successfully prepared to be halted. Possible error return values include the following status code.

| Return value | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER | The *Halt* parameter is NULL; or an invalid flag value was specified in *Flags*; or *Flags* contains an illegal combination of flag bits. For more information, see Remarks. |
| STATUS_UNSUCCESSFUL | The PEP's *Halt* callback routine unexpectedly returned from an idle state in which the processor's hardware context was not preserved. |

## Remarks

This routine is implemented by the power management framework (PoFx) and is called by the platform extension plug-in (PEP). The **ProcessorHalt** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to a **ProcessorHalt** routine.

Before halting the processor, the PEP calls the **ProcessorHalt** routine to give PoFx an opportunity to save the processor's hardware context. If necessary, **ProcessorHalt** saves this state internally in PoFx so that the state can later be restored when the processor exits the idle state. After preparing the processor to enter the idle state, **ProcessorHalt** calls the PEP's *Halt* callback routine to halt the processor.

As part of the PEP's handling of a [PEP_NOTIFY_PPM_IDLE_EXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_execute) notification, the PEP must transition the processor to the idle state that the PEP has selected. The following are the two ways to enter the processor idle state:

* For a processor idle state in which the processor's caches remain coherent so that all system and processor state is maintained, the PEP can enter the idle state directly without first calling **ProcessorHalt**.
* For a processor idle state in which the processor's caches might not remain coherent, or an idle state in which the processor hardware context is not preserved, the PEP must call **ProcessorHalt** before transitioning the processor to the idle state.

The following combinations of flag bits are illegal:

* PROCESSOR_HALT_CONTEXT_RETAINED = 1 and PROCESSOR_HALT_RETURN_NOT_SAFE = 1

  The PEP's *Halt* callback routine must return from any state in which context is retained.
* PROCESSOR_HALT_CACHE_FLUSH_OVERRIDE = 1 and PROCESSOR_HALT_CACHE_COHERENT = 1

  The cache-flush-override flag should be set only if entering an idle state that is not cache coherent.
* PROCESSOR_HALT_CACHE_FLUSH_OVERRIDE = 0 and PROCESSOR_HALT_CACHE_COHERENT = 0

  The cache-flush-override flag must be set for any non-cache coherent halt.
* PROCESSOR_HALT_CONTEXT_RETAINED = 0 and PROCESSOR_HALT_CACHE_COHERENT = 1

  Any idle states that lose processor hardware context (and therefore use the [multiprocessor parking protocol](https://acpica.org/sites/acpica/files/MP Startup for ARM platforms.doc) to exit the idle state and return control to the operating system) are not cache-coherent states.

If the *Flags* parameter contains an illegal combination of flag bits, **ProcessorHalt** fails and returns STATUS_INVALID_PARAMETER.

The PEP can call this routine at IRQL <= HIGH_LEVEL.

## See also

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)

[PEP_NOTIFY_PPM_IDLE_EXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_execute)