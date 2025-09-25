# _PEP_PROCESSOR_IDLE_STATE_V2 structure (pep_x.h)

## Description

The **PEP_PROCESSOR_IDLE_STATE_V2** structure describes a processor idle state that the platform extension plug-in (PEP) supports.

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

### `WakesSpuriously`

Whether the processor can wake spuriously in this idle state. Set this flag bit to 0 if the processor is guaranteed to stay in this idle state until it receives a device interrupt, inter-processor interrupt (IPI), or wake request. Set to 1 if the processor might wake autonomously for some other reason.

### `PlatformOnly`

Whether the transition to this processor idle state can be performed only as part of a coordinated transition to a platform-wide idle state. Set this flag bit to 1 if the processor idle state transition can be performed only as part of a transition to a platform idle state. Otherwise, set to 0.

### `Autonomous`

Whether a coordinated transition to this processor idle state is performed autonomously by the processor hardware. Set this flag bit to 1 if these transitions are autonomous, and to 0 if they are not. A flag value of 1 indicates that the idle state can be entered without sending a [PEP_NOTIFY_PPM_TEST_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_test_idle_state), [PEP_NOTIFY_PPM_IDLE_PRE_EXECUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_idle_state_v2), or [PEP_NOTIFY_PPM_IDLE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_idle_complete) notification. This flag can be set to 1 only if **CStateType** is nonzero.

### `Reserved`

Reserved for future use. Set to zero.

### `Latency`

The worst-case latency, in 100-nanosecond units, that the processor requires to wake from this idle state in response to a wake event.

### `BreakEvenDuration`

The minimum amount of time, specified in 100-nanosecond units, that the processor must spend in this idle state to make a transition to this state worthwhile. The Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) uses this member value as a hint to avoid switching a processor to an idle state unless the processor is likely to remain in this state for at least the amount of time specified by **BreakEvenDuration**.

## Remarks

The unnamed union contains a collection of flag bits and status fields that can be accessed either individually as bit fields, or together as a 32-bit unsigned integer value.

The unnamed struct contains flag bits and status fields accessed as individual bit fields.

This structure is used in conjunction with the [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) notification. The **IdleStates** member of the [PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2) structure is the first element in an array of **PEP_PROCESSOR_IDLE_STATE_V2** structures.

## See also

- [PEP_NOTIFY_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)
- [PEP_PPM_QUERY_IDLE_STATES_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_idle_states_v2)