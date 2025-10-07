# MrmCreateResourceIndexerFromPreviousSchemaData function

Creates a resource indexer that can create PRI files that are compatible with existing PRI files. This function
is only needed in fairly limited scenarios; see the **Remarks** section of
[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile) for more info.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**)
before using this function.

## Parameters

*projectRoot* \[in\]

Type: **PCWSTR**

The root directory from which some file paths will be computed. Typically this will be the root directory of your
source project, but may differ. See [File resources in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmfiles) for more information.

*platformVersion* \[in\]

Type: **[**MrmPlatformVersion**](https://learn.microsoft.com/windows/win32/menurc/mrmplatformversion)**

The platform version (*targetOsVersion*) to use for the generated configuration file. Most callers should just
use **MrmPlatformVersion_Windows10_0_0_5**

*defaultQualifiers* \[in, optional\]

Type: **PCWSTR**

A list of default resource qualifiers. For example, "language-en-US_scale-100". For more information about qualifiers,
see [Qualifiers in MRM](https://learn.microsoft.com/windows/win32/menurc/mrmqualifiers).

*schemaXmlData* \[in\]

Type: **BYTE\***

A pointer to an in-memory PRI file or in-memory Schema XML dump. You can obtain an in-memory PRI file either by manually loading
an existing PRI file from disk, or by creating it in-memory with [**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateconfig). You
can obtain an in-memory Schema XML dump either by manually loading an existing file from disk, or by using one of the
**MrmDump...** functions.

*schemaXmlSize* \[in\]

Type: **ULONG**

The size of the data pointed to by *schemaXmlData*.

*indexer* \[in, out\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)\***

A pointer to a resource indexer handle. On successful return, this will contain a handle to a resource indexer.
You must free the indexer via [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) after using it.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Remarks

See the **Remarks** section
of [**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile) for more info,
as this function is essentially the same (except it uses in-memory reference PRI rather than an on-disk file).

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

[**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-)

[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile.md)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)