# NVME_CDW10_SET_FEATURES structure

## Description

Contains parameters for the Set Features command that sets the attributes of the specified feature.

The Set Features command uses the **NVME_CDW10_SET_FEATURES** structure in the **CDW10** parameter of the **SETFEATURES** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.FID`

Specifies an [NVME_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features) value that identifies the feature for which attributes are being provided.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.SV`

Specifies that the controller will save the attribute so that the attribute persists through all power states and resets.

The controller indicates in bit 4 of the Optional NVM Command Support **ONCS** field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure whether this field is supported.

If the **FID** specified in the Set Features command is not saveable by the controller and the controller receives a Set Features command with the Save **SV** bit set to one, then the command is aborted with a status of [Feature Identifer Not Saveable **NVME_STATUS_FEATURE_ID_NOT_SAVEABLE**](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_command_specific_codes).

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)
- [NVME_CDW12_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw12_features)
- [NVME_CDW13_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw13_features)
- [NVME_CDW14_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw14_features)
- [NVME_CDW15_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw15_features)