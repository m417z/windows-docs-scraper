# _PEP_WORK_INFORMATION structure (pepfx.h)

## Description

The **PEP_WORK_INFORMATION** structure describes a work item that the PEP is submitting to the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

## Members

### `WorkType`

A [PEP_WORK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_work_type) enumeration value. This member indicates the type of work requested by the PEP, which also determines the type of structure that is contained in the unnamed union in the **PEP_WORK_INFORMATION** structure.

### `PowerControl`

A [PEP_WORK_POWER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_power_control) structure. This structure is used if `WorkType == PepWorkRequestPowerControl`.

### `CompleteIdleState`

A [PEP_WORK_COMPLETE_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_complete_idle_state) structure. This structure is used if `WorkType == PepWorkCompleteIdleState`.

### `CompletePerfState`

A [PEP_WORK_COMPLETE_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_complete_perf_state) structure. This structure is used if `WorkType == PepWorkCompletePerfState`.

### `AcpiNotify`

A [PEP_WORK_ACPI_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_acpi_notify) structure. This structure is used if `WorkType == PepWorkAcpiNotify`.

### `ControlMethodComplete`

A [PEP_WORK_ACPI_EVALUATE_CONTROL_METHOD_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_acpi_evaluate_control_method_complete) structure. This structure is used if `WorkType == PepWorkAcpiEvaluateControlMethodComplete`.

## Remarks

The *WorkInformation* member of the [PEP_WORK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work) structure is a pointer to a **PEP_WORK_INFORMATION** structure.

The unnamed union contains the data structure that is associated with the type of work specified by the *WorkType* member.

## See also

- [PEP_DPM_WORK](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-peps-for-acpi-services)
- [PEP_WORK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work)
- [PEP_WORK_ACPI_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_acpi_notify)
- [PEP_WORK_ACTIVE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_work_active_complete)
- [PEP_WORK_COMPLETE_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_complete_idle_state)
- [PEP_WORK_COMPLETE_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_complete_perf_state)
- [PEP_WORK_DEVICE_IDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_work_device_idle)
- [PEP_WORK_DEVICE_POWER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_work_device_power)
- [PEP_WORK_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pep_x/ns-pep_x-_pep_work_idle_state)
- [PEP_WORK_POWER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_power_control)
- [PEP_WORK_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_work_type)