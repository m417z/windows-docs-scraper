## Description

Retrieves or sets a list of registry keys to collect.

This property is read/write.

## Parameters

### `query`

TBD

## Remarks

You can collect registry data from the following registry hives:

* **HKEY_CLASSES_ROOT**
* **HKEY_CURRENT_CONFIG**
* **HKEY_CURRENT_USER**
* **HKEY_LOCAL_MACHINE**
* **HKEY_USERS**

To collect a registry value, specify the full path to the value name, for example, `\HKEY_LOCAL_MACHINE\MyKey\MyValue`.

To collect all the values under a registry key, specify the full path to the registry key, for example, `\HKEY_LOCAL_MACHINE\MyKey\`.

To collect all the values under a registry key and its subkeys, use two backslashes for the last path delimiter, for example, `\\computername\HKEY_LOCAL_MACHINE\MyKey\\`. PLA recursively collects the registry data down to the level specified in the [IConfigurationDataCollector::RegistryMaxRecursiveDepth](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_registrymaxrecursivedepth) property.

To collect registry information from a remote computer, include the computer name at the beginning of the registry path, for example, `\\computername\HKEY_LOCAL_MACHINE\MyKey\MyValue`.

## See also

[IConfigurationDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iconfigurationdatacollector)

[IConfigurationDataCollector::RegistryMaxRecursiveDepth](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iconfigurationdatacollector-get_registrymaxrecursivedepth)