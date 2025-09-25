# PEP_PROCESSOR_IDLE_CANCEL_CODE enumeration

## Description

The **PEP_PROCESSOR_IDLE_CANCEL_CODE** enumeration values indicate reasons why a processor cannot enter an idle state that was previously selected by the platform extension plug-in (PEP).

## Constants

### `PepIdleCancelWorkPending`

The processor has pending work that prevents it from entering the selected idle state.

### `PepIdleCancelDependencyCheckFailed`

The processor can enter the selected idle state only after one or more secondary processors have entered their corresponding idle states, but not all of these secondary processors have entered the correct idle states.

### `PepIdleCancelNoCState`

The selected idle state corresponds to a C-state that is not supported. The PEP previously received a [PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states) notification that supplied a list of the supported C-states for this processor.

### `PepIdleCancelMax`

Reserved for use by the operating system.

## Remarks

The **CancelCode** member of the [PEP_PPM_IDLE_CANCEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_cancel) structure contains a **PEP_PROCESSOR_IDLE_CANCEL_CODE** enumeration value.

## See also

[PEP_NOTIFY_PPM_CST_STATES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_cst_states)

[PEP_PPM_IDLE_CANCEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_cancel)