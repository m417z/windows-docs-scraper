# CmCallbackReleaseKeyObjectIDEx function

## Description

The **CmCallbackReleaseKeyObjectIDEx** routine frees an object name string obtained from the [CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex) routine.

## Parameters

### `ObjectName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the object name string. The driver previously obtained this pointer by calling [CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex).

## See also

[CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)