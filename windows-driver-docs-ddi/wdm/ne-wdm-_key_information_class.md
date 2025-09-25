# _KEY_INFORMATION_CLASS enumeration

## Description

The **KEY_INFORMATION_CLASS** enumeration type represents the type of information to supply about a registry key.

## Constants

### `KeyBasicInformation`

A [KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information) structure is supplied.

### `KeyNodeInformation`

A [KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information) structure is supplied.

### `KeyFullInformation`

A [KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information) structure is supplied.

### `KeyNameInformation`

A [KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information) structure is supplied.

### `KeyCachedInformation`

A [KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information) structure is supplied.

### `KeyFlagsInformation`

Reserved for system use.

### `KeyVirtualizationInformation`

A [KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information) structure is supplied.

### `KeyHandleTagsInformation`

Reserved for system use.

### `KeyTrustInformation`

### `KeyLayerInformation`

### `MaxKeyInfoClass`

The maximum value in this enumeration type.

## Remarks

Use the **KEY_INFORMATION_CLASS** values to specify the type of data to be supplied by the [ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey) and [ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey) routines.

## See also

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[KEY_FULL_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)