# _REG_POST_CREATE_KEY_INFORMATION structure

## Description

The **REG_POST_CREATE_KEY_INFORMATION** structure contains the result of an attempt to create a registry key.

## Members

### `CompleteName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that specifies the complete path of the registry key.

### `Object`

A pointer to the registry key object that was created.

### `Status`

The NTSTATUS value that the system will return for the registry operation.

## Remarks

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)