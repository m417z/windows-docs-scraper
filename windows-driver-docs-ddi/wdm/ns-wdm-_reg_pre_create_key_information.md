# _REG_PRE_CREATE_KEY_INFORMATION structure

## Description

The **REG_PRE_OPEN_KEY_INFORMATION** structure contains the name of a registry key that is about to be opened.

## Members

### `CompleteName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the complete path of the registry key.

## Remarks

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)