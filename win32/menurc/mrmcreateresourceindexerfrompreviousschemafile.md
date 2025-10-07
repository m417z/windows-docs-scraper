# MrmCreateResourceIndexerFromPreviousSchemaFile function

Creates a resource indexer that can create PRI files that are compatible with existing PRI files. This function
is only needed in fairly limited scenarios; see **Remarks** for more info.

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

*schemaFile* \[in\]

Type: **PCWSTR**

The path to an existing PRI file whose schema you need to match, or the path to an XML dump containing the
schema of the PRI file to match. See [**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile) for info on creating an XML dump.

*indexer* \[in, out\]

Type: **[**MrmResourceIndexerHandle**](https://learn.microsoft.com/windows/win32/menurc/mrmresourceindexerhandle)\***

A pointer to a resource indexer handle. On successful return, this will contain a handle to a resource indexer.
You must free the indexer via [**MrmDestroyIndexerAndMessages**](https://learn.microsoft.com/windows/win32/menurc/mrmdestroyindexerandmessages) after using it.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Remarks

This function is equivalent to [**MrmCreateResourceIndexer**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexer) except that the indexer
will create PRI files that are guaranteed to include all the resource names and indices of the provided *schemaFile*
in addition to any new resources added to the indexer. This ensures that the new PRI file is "schema-compatible" with
the original *schemaFile*, even if some resources have been omitted.

For most common scenarios, this function is not needed. If either of the following apply, you do not need to worry
about building schema-compatible PRI files:

* You use a single, stand-alone PRI file (which is the only supported option for unpackaged apps); **or**
* You always rebuild your resource pack PRIs when rebuilding your main PRI.

This function is only needed in a fairly limited scenario, namely:

1. You have a main PRI file and one or more resource-pack PRI files; **and**
1. You are rebuilding the main PRI file (but not the resource-pack PRI files); **and**
1. You are (or might be) removing one or more resources from the main PRI file.

In this situation, setting the *schemaFile* reference to the original main PRI file will ensure that the
new main PRI file is compatible with the existing resource packs, by ensuring there are placeholder index values
for the removed resources.

Note: The new PRI file will contain all the resource names (and indices) from the original file but will only contain
values for the resources explicitly added to the indexer. The new file *does not* inherit (copy) the values from
the original PRI file.

## Example

Assume the PRI file "original.pri" contains three resources for English:

| Name | Index | Value |
|-|-|-|
| ms-resource:///strings/test | 0 | "TestValue" |
| ms-resource:///strings/save | 1 | "Save" |
| ms-resource:///strings/delete | 2 | "Delete" |

Now consider the following code snippet (error checking omitted):

```C++
// Create an indexer with the existing schema
MrmResourceIndexerHandle indexer{};
MrmCreateResourceIndexerFromPreviousSchemaFile(L"C:\\MyProject", MrmPlatformVersion_Windows10_0_0_5, L"language-en", L"original.pri", &indexer);

// Add values for "save" and "delete".
// Note that there is no "test" resource added, since we don't need it anymore.
MrmIndexString(indexer, L"ms-resource:///strings/save", L"Save", L"language-en");
MrmIndexString(indexer, L"ms-resource:///strings/delete", L"Delete", L"language-en");

// Save the file
MrmCreateResourceFile(indexer, MrmPackagingModeStandaloneFile, MrmPackagingOptionsNone, L"C:\\");
```
The new resource file will contain the following for English:

| Name | Index | Value |
|-|-|-|
| ms-resource:///strings/test | 0 | \<none> |
| ms-resource:///strings/save | 1 | "Save" |
| ms-resource:///strings/delete | 2 | "Delete" |

This ensures that the resource indices for `save` and `delete` remain the same (1 and 2, respectively), so
that resource packs with localized versions of "Save" and "Delete" will match. Note that if the application
code still tried to load the `test` resource, it would fail at runtime (at least in English) since there are
no candidates defined.

To illustrate why this is important, let's see what happens if the new PRI file had not been created with
the base schema. In that case the new PRI file would contain the following:

| Name | Index | Value |
|-|-|-|
| ms-resource:///strings/save | 0 | "Save" |
| ms-resource:///strings/delete | 1 | "Delete" |

Now resoure lookups for `delete` (index 1) would retrieve the correct string "Delete" in English, but
in other languages it would retrieve the localized version of "Save" (since index 1 used to be the
index for the `save` resource). This would lead to users seeing UX labelled "Save" (in their local language)
that actually performed a delete operation - a serious bug.

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

[**MrmCreateResourceIndexerFromPreviousSchemaData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemadata)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)