# _PEP_PPM_IDLE_CANCEL structure

## Description

The **PEP_PPM_IDLE_CANCEL** structure indicates why the processor could not enter the previously selected idle state.

## Members

### `CancelCode` [in]

A [PEP_PROCESSOR_IDLE_CANCEL_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ne-pep_x-pep_processor_idle_cancel_code) enumeration value that indicates why the processor could not enter the idle state selected by the platform extension plug-in (PEP).

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_IDLE_CANCEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_cancel) notification. The **CancelCode** member of the structure contains an input value that the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) supplies before this notification is sent.

## See also

[PEP_NOTIFY_PPM_IDLE_CANCEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_ppm_idle_cancel)

[PEP_PROCESSOR_IDLE_CANCEL_CODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ne-pep_x-pep_processor_idle_cancel_code)