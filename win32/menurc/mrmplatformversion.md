# MrmPlatformVersion enumeration

Defines constants that specify the target platform version for a PRI file. The target platform version is the minimum
version of Windows that the file can be used with. In most cases, you should just use the value
**MrmPlatformVersion_Windows10_0_0_5** unless you need to run on older releases of Windows.

## Constants

**MrmPlatformVersion\_Default**

The PRI file is supported on the default platform version, which is currently the same as 10.0.0.0.

**MrmPlatformVersion\_Windows10\_0\_0\_0**

The PRI file is supported on the initial release of Windows 10 (build 10240) and above.

**MrmPlatformVersion\_Windows10\_0\_0\_5**

The PRI file is supported on the 1809 release of Windows 10 (build 17763) and above. Most callers should specify this value.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |

## See also

[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer)

[**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-)

[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile)

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)