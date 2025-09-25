# _FAULT_INFORMATION structure

## Description

Contains information to set the fault report on a device. This structure is used by the [**IOMMU_DEVICE_FAULT_HANDLER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_fault_handler) callback function.

## Members

### `Type`

A [**FAULT_INFORMATION_ARCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fault_information_arch)-type value that indicates the system architecture.

### `IsStage1`

### `Arm64`

A [**FAULT_INFORMATION_ARM64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fault_information_arm64) structure that contains fault information on an ARM64 system.

### `X64`

## Remarks

## See also