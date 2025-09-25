# NVME_CDW11_FEATURE_POWER_MANAGEMENT structure

## Description

Contains values for the Power Management Feature that allows the host to configure the power state.

The values from this structure are used in the **PowerManagement** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.PS`

The Power State (PS) field indicates the new power state into which the controller should transition.

This power state must one supported by the controller as indicated in the Number of Power States Supported (**NPSS**) field in the [Identify Controller data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data).

If the specified power state is not supported, the controller will return a status of [NVME_STATUS_INVALID_FIELD_IN_COMMAND](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes).

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)