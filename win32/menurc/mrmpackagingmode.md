# MrmPackagingMode enumeration

Defines constants that specify what kind of PRI file(s) should be created by [**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile) and
[**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefileinmemory).

## Constants

**MrmPackagingModeStandaloneFile**

A single PRI file should be created containing all resources. This is the most common usage, and the only supported mode
for unpackaged desktop apps.

**MrmPackagingModeAutoSplit**

One or more PRI files should be created, determined by language or scale. See **Remarks** for more info.

**MrmPackagingModeResourcePack**

A single resource-pack PRI file should be created. See **Remarks** for more info.

## Remarks

PRI files created for unpackaged apps must use **MrmPackagingModeStandaloneFile** as MRT Core only supports a single PRI file.
For packaged apps, you should also use **MrmPackagingModeStandaloneFile** unless you plan on building Resource Packs to minimize
download / install size. A single stand-alone PRI file contains all resources in all languages / scales, and so is usable in all
target markets. If you are building a packaged app and want to create Resource Packs, you can use one of the other two values.

**MrmPackagingModeAutoSplit** creates a PRI file for each of the following kinds of resources:

1. A main PRI, including all resources with the default language qualifier and all neutral resources.
1. One language-specific PRI for each set of resources using a non-default language qualifier.
1. One scale-specific PRI for each scale factor that is not a default qualifier and did not also have a language specifier.

For example, assume the indexer was created with English as the default qualifer, and it contains resources with all the
following qualifiers:

1. \
1. language-en
1. language-en_scale-100
1. language-de
1. language-de_scale-200
1. scale-400

In this case, 3 PRI files will be created:

* The file `resources.pri` will contain resources #1 (neutral) and #2 & #3 (default language).
* The file `resources.language-de.pri` will contain resources #4 & #5 (non-default language).
* The file `resources.scale-400.pri` will contain resource #6 (scale but no language).

Note that if the option **MrmPackagingOptionsSplitLanguageVariants** is specified when creating the PRI files,
a PRI file will be created for each language variant (eg, en-US, en-AU, and en-GB) instead of just one for each
language.

**MrmPackagingModeResourcePack** produces a single PRI file that contains resources in a single language. All
resources must have the same language as the default qualifier language. The resource indexer *must* have been created using
[**MrmCreateResourceIndexerFromPreviousPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousprifile) or
[**MrmCreateResourceIndexerFromPreviousPriData**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviouspridata-) and passing
the main PRI file as the *priFile* or *priData* parameters, respectively. Unlike the **AutoSplit** mode, there is no
mechanism to create individual scale-based resource packs.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |

## See also

[**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile)

[**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefileinmemory)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)