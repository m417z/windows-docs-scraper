# RtlQueryRegistryValueWithFallback function

## Description

Retrieves a value entry for a registry key by using, a primary handle; if not found, uses the fallback handle.

## Parameters

### `PrimaryHandle` [in]

The handle to the key that is first used to query the value entries. This handle is created by a successful call to [**ZwCreateKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [**ZwOpenKey**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

### `FallbackHandle` [in]

The handle to use for querying the key if value is not found using the handle specified by _PrimaryHandle_.

### `ValueName` [in]

A pointer to string that contains the name of the value for which to retrieve data.

### `ValueLength` [in]

Specifies the size, in bytes, of the _ValueName_ string.

### `ValueType` [Out]

A pointer to a ULONG variable that receives the type of the value being queried.

### `ValueData` [out]

A pointer to a buffer that receives the value data.

### `ResultLength` [out]

A pointer to a variable that receives the value data size, in bytes. If the return value is STATUS_SUCCESS, indicates the number of bytes written to the _ValueData_ buffer. If the call returns STATUS_BUFFER_OVERFLOW, indicates the number of bytes required. Callers can use that value to determine the size of _ValueData_ buffer required to hold the data information.

## Return value

Returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## Remarks

## See also

[Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver)