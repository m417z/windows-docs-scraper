# _PEP_WORK_TYPE enumeration (pep_x.h)

## Description

The **PEP_WORK_TYPE** enumeration describes the type of work that the platform extension plug-in (PEP) is requesting.

## Constants

### `PepWorkRequestPowerControl`

A request for the device driver to perform a custom power-control operation that uses a device-specific context that the PEP provides for the operation. The driver handles this request in its [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback) routine.

### `PepWorkCompleteIdleState`

A notification to PoFx that the PEP has asynchronously completed the transition of a component to an idle state. PoFx previously initiated this transition by sending a [PEP_DPM_NOTIFY_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_notify_component_idle_state) notification to the PEP.

### `PepWorkCompletePerfState`

A notification to PoFx that the PEP has asynchronously completed the transition of a component to a P-state. PoFx previously initiated this transition by sending a [PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state) notification to the PEP.

### `PepWorkAcpiNotify`

An ACPI Notify code to describe to PoFx a hardware event that the specified device has generated.

### `PepWorkAcpiEvaluateControlMethodComplete`

A notification to PoFx that the PEP has asynchronously finished evaluating an ACPI control method. PoFx previously initiated the evaluation of this method by sending a [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method) notification to the PEP.

### `PepWorkMax`

Reserved for use by operating system.

## Remarks

This enumeration is used by the [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information) structure to describe the type of work item that the PEP is requesting.

## See also

- [PEP_DPM_NOTIFY_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_notify_component_idle_state)
- [PEP_DPM_REQUEST_COMPONENT_PERF_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_request_component_perf_state)
- [PEP_NOTIFY_ACPI_EVALUATE_CONTROL_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_evaluate_control_method)
- [PEP_WORK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_work_information)
- [PowerControlCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_power_control_callback)