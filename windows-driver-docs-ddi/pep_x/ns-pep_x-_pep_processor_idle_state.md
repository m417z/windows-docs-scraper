# _PEP_PROCESSOR_IDLE_STATE structure

## Description

The **PEP_PROCESSOR_IDLE_STATE** structure describes the capabilities of a processor idle state.

## Members

### `Ulong`

Flag bits and status fields accessed as a single 32-bit unsigned integer value.

### `Interruptible`

Whether the processor can respond to interrupts when in this idle state. Set this flag bit to 1 if the processor can respond to interrupts, and to 0 if it cannot.

### `CacheCoherent`

Whether the processor's local cache or caches remain coherent through the duration of this processor idle state. Set this flag bit to 1 if cache coherency is maintained in this idle state, and to 0 if it is not.

### `ThreadContextRetained`

Whether thread context is retained in this processor idle state. Set this flag bit to 1 if the processor hardware retains the thread context across the idle transition. Set to 0 if the processor uses the multiprocessor parking protocol to exit the idle state and return control to the operating system. For more information about this protocol, see the document titled [Multiprocessor Startup for ARM Platforms](https://acpica.org/sites/acpica/files/MP%20Startup%20for%20ARM%20platforms.docx) at the [ACPI Component Architecture site](https://www.acpica.org/related-documents).

### `CStateType`

The C-state type of the processor idle state. Set this bit field to zero if this idle state does not correspond to an ACPI-defined C-state. Otherwise, set this bit field to the C-state number. That is, set **CStateType** = 1 for C1, set **CStateType** = 2 for C2, and so on. For more information about C-states, see section 8.1, *Processor Power States*, of the [ACPI 5.0 specification](https://uefi.org/specifications).

### `Reserved`

Reserved for future use.

## Remarks

The unnamed union contains a collection of flag bits and status fields that can be accessed either individually as bit fields, or together as a 32-bit unsigned integer value.

The unnamed struct contains flag bits and status fields accessed as individual bit fields.

The **IdleStates** member of the [PEP_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states) structure is the first element in an array of **PEP_PROCESSOR_IDLE_STATE** structures.

## See also

- [PEP_PPM_QUERY_IDLE_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_query_idle_states)