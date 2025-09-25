# _KEY_VIRTUALIZATION_INFORMATION structure

## Description

The **KEY_VIRTUALIZATION_INFORMATION** structure defines the basic information that is available for a registry key or subkey.

## Members

### `VirtualizationCandidate`

Specifies whether the key is part of the virtualization namespace scope.

### `VirtualizationEnabled`

Specifies whether virtualization is enabled on this key. This value can be set to 1 only if **VirtualizationCandidate** is 1.

### `VirtualTarget`

Specifies whether the key is a virtual key. This value can be set to 1 only if **VirtualizationCandidate** and **VirtualizationEnabled** are both 0. This value is valid only on the virtual store key handles.

### `VirtualStore`

Specified whether the key is a part of the virtual store path.

### `VirtualSource`

Specifies whether the key has ever been virtualized. This value can be set to 1 only if **VirtualizationCandidate** is 1.

### `Reserved`

This value is reserved for system use.

## See also

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)