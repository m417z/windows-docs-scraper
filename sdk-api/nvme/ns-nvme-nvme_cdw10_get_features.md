# NVME_CDW10_GET_FEATURES structure

## Description

Contains parameters for the Get Features command that retrieves the attributes of the specified feature.

The Get Features command uses the **NVME_CDW10_GET_FEATURES** structure in the **CDW10** parameter of the **GETFEATURES** field of the [Command](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.FID`

Specifies an [NVME_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_features) value that identifies the feature for which to provide data.

### `DUMMYSTRUCTNAME.SEL`

Specifies an [NVME_FEATURE_VALUE_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_feature_value_codes) value that indicates which value of the attributes to return in the provided data.

The controller indicates in bit 4 of the Optional NVM Command Support **ONCS** field of the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure whether the **SEL** field is supported.

If a Get Features command is received with the **SEL** field set to `010b` (**NVME_FEATURE_VALUE_SAVED**), for example, and the controller does not support the Feature Identifier being saved or does not currently have any saved values, then the controller treats the **SEL** field as though it were set to `001b` (**NVME_FEATURE_VALUE_DEFAULT**).

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)