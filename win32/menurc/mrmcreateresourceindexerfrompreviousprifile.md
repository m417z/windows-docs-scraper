# MrmCreateResourceIndexerFromPreviousPriFile function

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

*priFile* \[in\]

Type: **PCWSTR**

A fully-qualified path to an existing PRI file.

*indexer* \[in, out\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)\***

A pointer to a resource indexer handle. On successful return, this will contain a handle to a resource indexer.
You must free the indexer via [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) after using it.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h) to determine success or failure.

## Remarks

See general remarks about creating a resource indexer in the **Remarks** section of
[**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer).

This function is used to create language- or scale-specific PRI files that are used in addition to a primary PRI file
(the one passed as *priFile*). This is only useful if you are building a packaged MSIX app and intend to build separate
resource packages for the target language(s) / scale(s). In all other cases, this function is not needed.

For example, assume your default resources are in English and you created a PRI file for them. Now you have
localized those resources into German and wish to create a German-language resource pack for your app.

1. First you would create your English-language PRI file, saving it to disk.
1. Then you would call this function, passing in the path to the English-language PRI file as
the *priFile* parameter and making sure "language-de" was one of the *defaultQualifiers*.
1. Next you would add all the German-language resource candidates to the indexer. Note that you do not need to have a
German candidate for every resource; for those where the English resource is applicable (e.g. non-localized text or
images) the German candidate can be omitted.
1. Finally, you would save the German-languaeg PRI file using the **MrmPackagingModeResourcePack** packaging mode, placing it in a different directory than your English-language PRI file.

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

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)