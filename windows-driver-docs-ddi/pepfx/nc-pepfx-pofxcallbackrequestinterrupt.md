# POFXCALLBACKREQUESTINTERRUPT callback function (pepfx.h)

## Description

The **RequestInterrupt** routine requests that the operating system replay an edge-triggered interrupt that might have been lost while the hardware platform was in a low-power state.

## Parameters

### `Gsiv` [in]

The global system interrupt vector (GSIV) number that identifies this interrupt. The ACPI firmware assigns GSIV numbers to all primary interrupt lines. For secondary (GPIO) interrupt lines, the GSIV number is dynamically assigned by the operating system.

## Return value

**RequestInterrupt** returns STATUS_SUCCESS if the specified interrupt is successfully replayed. Possible error return values include the following status code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Not a valid GSIV number. |

## Remarks

This routine is implemented by the power management framework (PoFx) and is called by the platform extension plug-in (PEP). The **RequestInterrupt** member of the [PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3) structure is a pointer to an **RequestInterrupt** routine.

Assertion of an edge-triggered interrupt signal is transient in nature and can be lost if the power to a primary interrupt controller is gated off when the interrupt occurs. In contrast, a level-triggered interrupt signal is expected to remain asserted until it can be serviced.

A PEP can call this routine at IRQL <= HIGH_LEVEL.

## See also

[PEP_KERNEL_INFORMATION_STRUCT_V3](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_kernel_information_struct_v3)