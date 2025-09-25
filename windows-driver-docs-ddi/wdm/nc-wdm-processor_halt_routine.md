# PROCESSOR_HALT_ROUTINE callback function

## Description

A *Halt* callback routine transitions the processor to an idle state.

## Parameters

### `Context` [in, out, optional]

A pointer to a PEP-defined processor-halt context. This pointer is the *Context* parameter value that the PEP previously passed to the [ProcessorHalt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessorhalt) routine.

## Return value

A *Halt* callback routine may or may not return. If this routine does return, it returns STATUS_SUCCESS to indicates that the processor successfully entered the idle state. Otherwise, it returns an appropriate error status code.

## Remarks

This routine is implemented by the platform extension plug-in (PEP) and is called by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). The [ProcessorHalt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessorhalt) routine accepts a pointer to a *Halt* callback routine as a parameter.

The PEP's *Halt* routine is called at the same IRQL at which the PEP called **ProcessorHalt**.

## See also

[PEP_CRASHDUMP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_crashdump_information)

[ProcessorHalt](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessorhalt)