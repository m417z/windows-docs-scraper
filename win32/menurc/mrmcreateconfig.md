# MrmCreateConfig function

Creates a new, initialized PRI config file for use with the Windows SDK **MakePri** tool. None of the other MRM functions work with config files.

This function performs the equivalent of the `makepri createconfig` command.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**) before using this function.

## Parameters

*platformVersion* \[in\]

Type: **[**MrmPlatformVersion**](https://learn.microsoft.com/windows/win32/menurc/mrmplatformversion)**

The platform version (*targetOsVersion*) to use for the generated configuration file. Most callers should just use **MrmPlatformVersion_Windows10_0_0_5**

*defaultQualifiers* \[in, optional\]

Type: **PCWSTR**

A list of default resource qualifiers. For example, "language-en-US_scale-100". For more information about qualifiers, see [Qualifiers in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmqualifiers).

*outputXmlFile* \[in\]

Type: **PCWSTR**

The path of the configuration file to create. The file will be overwritten if it already exists.
The directory must already exist.

## Return value

Type: **HRESULT**

**S\_OK** if the function succeeded, otherwise an error value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h) to determine success or failure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)

