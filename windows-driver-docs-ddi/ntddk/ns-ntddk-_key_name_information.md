# _KEY_NAME_INFORMATION structure

## Description

The **KEY_NAME_INFORMATION** structure holds the name and name length of the key.

## Members

### `NameLength`

The size, in bytes, of the key name string in the **Name** array.

### `Name`

An array of wide characters that contains the name of the key. This character string is not null-terminated. Only the first element in this array is included in the **KEY_NAME_INFORMATION** structure definition. The storage for the remaining elements in the array immediately follows this element.

## Remarks

The [ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey) routine uses the **KEY_NAME_INFORMATION** structure to contain the registry key name. When the *KeyInformationClass* parameter of this routine is **KeyNameInformation**, the *KeyInformation* buffer is treated as a **KEY_NAME_INFORMATION** structure. For more information about the **KeyNameInformation** enumeration value, see [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class).

## See also

[KEY_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[KEY_CACHED_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[KEY_NODE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[KEY_VIRTUALIZATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[ZwQueryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwquerykey)