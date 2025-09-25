# _DEVICE_FAULT_CONFIGURATION structure

## Description

This structure is used in setting the device fault reporting state through the [IOMMU_SET_DEVICE_FAULT_REPORTING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting) callback function.

## Members

### `FaultHandler`

A pointer to the driver-supplied fault handler routine, executed at PASSIVE_LEVEL. See [**IOMMU_DEVICE_FAULT_HANDLER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_fault_handler).

### `FaultContext`

A pointer to the opaque driver-supplied fault context.

## Remarks

## See also