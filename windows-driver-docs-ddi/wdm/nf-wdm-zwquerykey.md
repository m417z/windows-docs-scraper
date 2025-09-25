## Description

The **ZwQueryKey** routine provides information about the class of a registry key, and the number and sizes of its subkeys.

## Parameters

### `KeyHandle` [in]

Handle to the registry key to obtain information about. This handle is created by a successful call to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

### `KeyInformationClass` [in]

Specifies a [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class) value that determines the type of information returned in the *KeyInformation* buffer.

### `KeyInformation` [out, optional]

Pointer to a caller-allocated buffer that receives the requested information.

### `Length` [in]

Specifies the size, in bytes, of the *KeyInformation* buffer.

### `ResultLength` [out]

Pointer to a variable that receives the size, in bytes, of the requested key information. If **ZwQueryKey** returns STATUS_SUCCESS, the variable contains the amount of data returned. If **ZwQueryKey** returns STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL, you can use the value of the variable to determine the required buffer size.

## Return value

**ZwQueryKey** returns STATUS_SUCCESS on success, or the appropriate error code on failure. Possible error code values include:

| Return code | Description |
|---|---|
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied is too small, and only partial data has been written to the buffer. \**ResultLength* is set to the minimum size required to hold the requested information. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer supplied is too small, and no data has been written to the buffer. \**ResultLength* is set to the minimum size required to hold the requested information. |
| **STATUS_INVALID_PARAMETER** | The *KeyInformationClass* parameter is not a valid [KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class) value. |

## Remarks

The *KeyHandle* passed to **ZwQueryKey** must have been opened with KEY_QUERY_VALUE access. This is accomplished by passing KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS as the *DesiredAccess* parameter to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).
> If *KeyInformationClass* is KeyNameInformation or KeyHandleTagsInformation, the KEY_QUERY_VALUE requirement does not apply.

**ZwQueryKey** can be used to obtain information that you can use to allocate buffers to hold registry data, such as the maximum size of a key's value entries or subkey names, or the number of subkeys. For example, you can call **ZwQueryKey**, use the returned information to allocate a buffer for a subkey, call [ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey) to get the name of the subkey, and pass that name to an **Rtl*****Xxx*****Registry** routine.

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "**NtQueryKey**" instead of "**ZwQueryKey**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**KEY_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_basic_information)

[**KEY_CACHED_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_cached_information)

[**KEY_FULL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_full_information)

[KEY_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_information_class)

[**KEY_NAME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_name_information)

[**KEY_NODE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_node_information)

[**KEY_VIRTUALIZATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_key_virtualization_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)