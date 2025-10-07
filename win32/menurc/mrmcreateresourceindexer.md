# MrmCreateResourceIndexer function

Creates a resource indexer, used to generate package resource index (PRI) files for both packaged and unpackaged
desktop apps.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**)
before using this function.

## Parameters

*packageFamilyName* \[in\]

Type: **PCWSTR**

The package family name (PFN) of the app for which you will be generating PRI files. If you are building a PRI file
for a packaged app, this *must* match the PFN of the app (as listed in the AppxManifest). If you are building
a PRI file for an unpackaged app, this *must* be the string **"Application"**.

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

*indexer* \[in, out\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)\***

A pointer to a resource indexer handle. On successful return, this will contain a handle to a resource indexer.
You must free the indexer via [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) after using it.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Remarks

Most of the MRM APIs require an indexer handle to operate. The handle is created by this function or one of the related
functions listed below under **See Also**.

Use [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) to
release the resources associated with the indexer after using it.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-)

[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile)

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)