# NVME_FEATURE_VALUE_CODES enumeration

## Description

Contains values that indicate which value of a feature should be retrieved or configured by the **NVME_ADMIN_COMMAND_GET_FEATURES** and **NVME_ADMIN_COMMAND_SET_FEATURES** Admin commands.

## Constants

### `NVME_FEATURE_VALUE_CURRENT`

The current operating attribute value for the specified feature.

### `NVME_FEATURE_VALUE_DEFAULT`

The default attribute value for the specified feature.

### `NVME_FEATURE_VALUE_SAVED`

The last saved attribute value for the specified feature. For example, the last Set Features command completed without error, with the Save bit set to `1` for the specified feature.

### `NVME_FEATURE_VALUE_SUPPORTED_CAPABILITIES`

The supported capabilities for the specified feature.

The supported capabilities are returned in Dword 0 of the completion entry of the Get Features command, in the following way:

- If Dword 0 bit 0 of the completion entry of the Get Features command is set to `1`, then the Feature Identifier is saveable. If Dword 0 bit 0 of the completion entry of the Get Features command is cleared to `0`, then the Feature Identifier is not saveable.
- If Dword 0 bit 1 of the completion entry of the Get Features command is set to `1`, then the Feature Identifier is namespace specific and settings are applied to individual namespaces. If Dword 0 bit 1 of the completion entry of the Get Features command is cleared to `0`, then the Feature Identifier is not namespace specific and its settings apply to the entire controller.
- If Dword 0 bit 2 of the completion entry of the Get Features command is set to `1`, then the Feature Identifier is changeable. If Dword 0 bit 2 of the completion entry of the Get Features command is cleared to `0`, then the Feature Identifier is not changeable.

## Remarks

In the **NVME_ADMIN_COMMAND_GET_FEATURES** and **NVME_ADMIN_COMMAND_SET_FEATURES** Admin commands, the feature is specified in the Feature Identifier (**FID**) member of the [NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features) and [NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features) structures.

If a Get Features command is received with the Select field **SEL** set to saved and the controller does not support the feature specified by the Feature Identifier being saved or does not currently have any saved values, then the controller treats the Select field as though it was set to default.

## See also

[NVME_ADMIN_COMMANDS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_admin_commands)
[NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features)
[NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features)