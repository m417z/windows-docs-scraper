## Description

Reports fault from a specific device and domain.

## Parameters

### `Context`

A pointer to the opaque driver-supplied fault context.

### `FaultInformation`

A pointer to a [**FAULT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fault_information) structure that contains fault information.

## Remarks

Register your implementation of this callback function by setting the **FaultHandler** member of [**DEVICE_FAULT_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_fault_configuration).

## See also