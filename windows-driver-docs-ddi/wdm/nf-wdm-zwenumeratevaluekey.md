## Description

The **ZwEnumerateValueKey** routine gets information about the value entries of an open key.

## Parameters

### `KeyHandle` [in]

Handle to the registry key that you want to enumerate value entries for. A successful call to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey) creates this handle.

### `Index` [in]

The zero-based index of the subkey that you want value information for.

### `KeyValueInformationClass` [in]

Specifies a [KEY_VALUE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_key_value_information_class) value that determines the type of information returned in the *KeyValueInformation* buffer.

### `KeyValueInformation` [out, optional]

Pointer to a caller-allocated buffer that receives the requested information.

### `Length` [in]

Specifies the size, in bytes, of the *KeyValueInformation* buffer.

### `ResultLength` [out]

Pointer to a variable that receives the size, in bytes, of the value information. If this routine returns STATUS_SUCCESS, the variable indicates the amount of data returned. If this routine returns STATUS_BUFFER_OVERFLOW or STATUS_BUFFER_TOO_SMALL, the variable indicates the buffer size that is required to hold the value information.

## Return value

**ZwEnumerateValueKey** returns STATUS_SUCCESS on success, or the appropriate error code on failure. Possible error code values include:

| Return code | Description |
|---|---|
| **STATUS_BUFFER_OVERFLOW** | The buffer supplied is too small, and only partial data has been written to the buffer. \**ResultLength* is set to the minimum size required to hold the requested information. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer supplied is too small, and no data has been written to the buffer. \**ResultLength* is set to the minimum size required to hold the requested information. |
| **STATUS_INVALID_PARAMETER** | The *KeyInformationClass* parameter is not a valid KEY_VALUE_INFORMATION_CLASS value. |
| **STATUS_NO_MORE_ENTRIES** | The *Index* value is out of range for the registry key specified by *KeyHandle*. For example, if a key has *n* subkeys, then for any value greater than *n*-1 the routine returns STATUS_NO_MORE_ENTRIES. |

## Remarks

The *KeyHandle* passed to **ZwEnumerateValueKey** must have been opened with KEY_QUERY_VALUE access. This is accomplished by passing KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS as the *DesiredAccess* parameter to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

The *Index* is simply a way to select among subkeys with value entries. Two calls to **ZwEnumerateValueKey** with the same *Index* are not guaranteed to return the same results.

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "**NtEnumerateValueKey**" instead of "**ZwEnumerateValueKey**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**KEY_VALUE_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_basic_information)

[**KEY_VALUE_FULL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_full_information)

[**KEY_VALUE_PARTIAL_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_key_value_partial_information)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwQueryValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryvaluekey)