# NVME_LBA_RANGE structure

## Description

Contains parameters that define a collection of contiguous logical blocks specified by a starting LBA and number of logical blocks.

This structure is used by the Dataset Management command, which provides a list of LBA ranges with optional context attributes. Each LBA range consists of a starting LBA (**StartingLBA**), a length of logical blocks that the range consists of (**LogicalBlockCount**), and the optional context attributes (**Attributes**) to be applied to that range.

## Members

### `Attributes`

A [NVME_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_context_attributes) structure that specifies context attributes for the logical block range.

The use of this information is optional and the controller is not required to perform any specific action.

### `LogicalBlockCount`

Specifies the length of the LBA range in logical blocks.

### `StartingLBA`

Specifies the starting logical block in the range.

## Remarks

## See also

- [NVME_CDW10_DATASET_MANAGEMENT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_dataset_management)
- [NVME_CDW11_DATASET_MANAGEMENT](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_dataset_management)