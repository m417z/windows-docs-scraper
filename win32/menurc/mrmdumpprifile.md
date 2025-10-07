# MrmDumpPriFile function

Dumps a PRI file to its XML equivalent. PRI files are stored in an undocumented binary format, so in order to view
the contents of a file for debugging etc. it must be saved ("dumped") as an XML file.

This function performs the equivalent of the `makepri dump` command.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**) before using this function.

## Parameters

*indexFileName* \[in\]

Type: **PCWSTR**

The path to the PRI file to dump. If this file does not have an embedded schema, then *schemaPriFile* is required.

*schemaPriFile* \[in, optional\]

Type: **PCWSTR**

The path to the PRI file that provides the scheme for the *indexFileName* if needed, otherwise **NULL**.
See **Remarks** for more info.

*dumpType* \[in\]

Type: [**MrmDumpType**](https://learn.microsoft.com/windows/win32/menurc/mrmdumptype)

Specified the kind of dump to create. For most use-cases, **MrmDumpTypeBasic** is sufficient. See the
[**MrmDumpType** reference](https://learn.microsoft.com/windows/win32/menurc/mrmdumptype) for more info.

*outputXmlFile* \[in\]

Type: **PCWSTR**

The path of the XML file to create. If the file already exists, it will be overwritten.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Remarks

You can create XML dumps from a PRI file, but there is no equivalent function to build a PRI file from an
XML dump - that must be done manually by using the other Resource Indexer APIs.

### When to use a *schemaPriFile*

In a PRI file, resources are identified by both a name and an index (known as the "Schema"). When a resource-pack
PRI file is created, the resource names can be omitted to save space. The resource-pack PRI file will contain only
the resource indexes, not the names. In order to produce the dump file (which includes resource names), the original
base PRI file is required.

A schema-free resource pack PRI file is created by using the
[**MrmPackagingOptionsOmitSchemaFromResourcePacks**](https://learn.microsoft.com/windows/win32/menurc/mrmpackagingoptions) option when creating a resource file via
one of the **MrmCreateResourceFile...** functions. When dumping such a resource-pack PRI file, pass the original (main)
PRI file as the *schemaPriFile* argument.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmDumpPriDataInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumppridatainmemory)

[**MrmDumpPriFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifileinmemory)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)