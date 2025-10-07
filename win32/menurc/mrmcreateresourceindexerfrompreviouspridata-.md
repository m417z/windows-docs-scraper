# MrmCreateResourceIndexerFromPreviousPriData function

Creates a resource indexer used to create PRI files for use in resource packages.

This function is not needed if you created the original PRI file(s) with the **MrmPackagingModeStandaloneFile** or
**MrmPackagingModeAutoSplit** packaging mode. If you are building resources for an unpackaged desktop app, you *cannot*
use this function since only stand-alone PRI files are supported for unpackaged apps.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**) before using this function.

## Parameters

*projectRoot* \[in\]

Type: **PCWSTR**

The root directory from which some file paths will be computed. Typically this will be the root directory of your
source project, but may differ. See [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) for more information.

*platformVersion* \[in\]

Type: **[**MrmPlatformVersion**](https://learn.microsoft.com/windows/win32/menurc/mrmplatformversion)**

The platform version (*targetOsVersion*) to use for the generated configuration file. Most callers should just use **MrmPlatformVersion_Windows10_0_0_5**

*defaultQualifiers* \[in, optional\]

Type: **PCWSTR**

A list of default resource qualifiers. For example, "language-en-US_scale-100". For more information about qualifiers, see [Qualifiers in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmqualifiers).

*priData* \[in\]

Type: **BYTE\***

A pointer to an in-memory PRI file. You can obtain an in-memory PRI file either by manually loading an existing PRI
file from disk, or by creating it in-memory with [**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateconfig).

*priSize* \[in\]

Type: **ULONG**

The size of the data pointed to by *priData*.

*indexer* \[in, out\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)\***

A pointer to a resource indexer handle. On successful return, this will contain a handle to a resource indexer.
You must free the indexer via [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) after using it.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h) to determine success or failure.

## Remarks

See the **Remarks** section
of [**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile) for more info,
as this function is essentially the same (except it uses in-memory PRI rather than an on-disk file).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer)

[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile)

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)