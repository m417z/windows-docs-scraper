# MrmPackagingOptions enumeration

Defines constants that specify options for the PRI file created by [**MrmCreateResourceFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefile) and
[**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourcefileinmemory).

## Constants

**MrmPackagingOptionsNone**

No options. Most callers should use this value.

**MrmPackagingOptionsOmitSchemaFromResourcePacks**

Resource Pack PRIs should be created without an embedded schema. See **Remarks** for more info.

**MrmPackagingOptionsSplitLanguageVariants**

Auto-split PRIs should be created based on language variants. See **Remarks** for more info.

## Remarks

PRI files created for unpackaged desktop apps should specify **MrmPackagingOptionsNone** as resource packs are
not supported. Most packaged apps should also specify **MrmPackagingOptionsNone** as it eases development.

**MrmPackagingOptionsOmitSchemaFromResourcePacks** is used when creating a resource pack PRIs, either
with the **AutoSplit** or **ResourcePack** packaging modes. The resource pack PRIs will not contain the
resource names (only the indexes) which reduces the file size but makes certain debugging operations
(such as dumping to XML) harder. See the **Remarks** section of
[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile)
for additional info about schemas.

**MrmPackagingOptionsSplitLanguageVariants** is used when creating resource pack PRIs with the **AutoSplit**
mode. In this case, rather than creating a single PRI per language, each language variant (eg en-US, en-AU,
and en-GB) will have their own PRI files generated.

See [**MrmPackagingMode**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingmode) for more info.

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