# NVME_CDW11_FEATURE_WRITE_ATOMICITY_NORMAL structure

## Description

Contains parameters for the Write Atomicity Normal Feature that controls the operation of the Atomic Write Unit Normal (**AWUN**) and Namespace Atomic Write Unit Normal (**NAWUN**) parameters that define the controller’s support for atomic operations.

The values from this structure are used in the **WriteAtomicityNormal** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.DN`

Indicates whether normal write atomicity should be disabled by specifying that **AWUN** and **NAWUN** are not required.

When this value is set to `1`, the host specifies that **AWUN** and **NAWUN** are not required and that the controller will only honor Atomic Write Unit Power Fail (**AWUPF**) and Namespace Atomic Write Unit Power Fail (**NAWUPF**).

When this value is cleared to `0`, **AWUN**, **NAWUN**, **AWUPF**, and **NAWUPF** will be honored by the controller.

The **AWUN** and **AWUPF** fields are in the [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) structure, and the **NAWUN** and **NAWUPF** fields are in the [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data) structure.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)
- [NVME_IDENTIFY_NAMESPACE_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_namespace_data)