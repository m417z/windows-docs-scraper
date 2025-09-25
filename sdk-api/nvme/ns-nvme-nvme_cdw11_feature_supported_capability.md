# NVME_CDW11_FEATURE_SUPPORTED_CAPABILITY structure

## Description

Contains values that are returned by the Get Features command, which describe the supported capabilities of the specified feature.

When a Get Features command is submitted with the **SEL** field of the [NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features) structure set to **NVME_FEATURE_VALUE_SUPPORTED_CAPABILITIES**, the **NVME_CDW11_FEATURE_SUPPORTED_CAPABILITY** structure is returned in the **DW0** field of the [Completion Queue Entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) structure for that command.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.SAVE`

Indicates whether the feature is saveable.

When this value is set to `1`, the feature is saveable.
When this value is set to `0`, the feature is not saveable.

### `DUMMYSTRUCTNAME.NSS`

Indicates whether the feature is namespace specific.

When this value is set to `1`, the feature is namespace specific and settings are applied to individual namespaces.
When this value is set to `0`, the feature is not namespace specific and its settings apply to the entire controller.

### `DUMMYSTRUCTNAME.MOD`

Indicates whether the feature is changeable.

When this value is set to `1`, the feature is changeable.
When this value is set to `0`, the feature is not changeable.

### `DUMMYSTRUCTNAME.Reserved0`

### `AsUlong`

## Remarks

## See also

- [NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features)