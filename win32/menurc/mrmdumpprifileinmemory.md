# MrmDumpPriFileInMemory function

Dumps a PRI file to its XML equivalent, storing the result in memory. PRI files are stored in an undocumented binary
format, so in order to view the contents of a file for debugging etc. it must be saved ("dumped") as XML.

This function performs the equivalent of the `makepri dump` command, with the results being stored in memory.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**) before using this function.

## Parameters

*indexFileName* \[in\]

Type: **PCWSTR**

The path to the PRI file to dump. If this file does not have an embedded schema, then *schemaPriFile* is required.

*schemaPriFile* \[in, optional\]

Type: **PCWSTR**

The path to the PRI file that provides the schema for the *indexFileName* if needed, otherwise **NULL**.
See the **Remarks** section of [**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile) for more info.

*dumpType* \[in\]

Type: **[**MrmDumpType**](https://learn.microsoft.com/windows/win32/menurc/mrmdumptype)**

Specified the kind of dump to create. For most use-cases, **MrmDumpTypeBasic** is sufficient. See the
[**MrmDumpType** reference](https://learn.microsoft.com/windows/win32/menurc/mrmdumptype) for more info.

*outputXmlData* \[out\]

Type: **BYTE\*\***

The address of a **BYTE** pointer. On successful return, contains a pointer to the buffer allocated by
the function that contains the generated XML content. You must free the memory by calling
[**MrmFreeMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmfreememory) when you are done with it.

*outputXmlSize* \[out\]

Type: **ULONG\***

The address of a **ULONG**. On successful return, contains the size of the allocated memory buffer pointed to by
*outputXmlData*.

## Return value

Type: **HRESULT**

S\_OK if the function succeeded, otherwise some other value. Use the **SUCCEEDED** or **FAILED** macros (defined in winerror.h)
to determine success or failure.

## Remarks

See the **Remarks** section of [**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile) for more info,
as this function is essentially the same (except it dumps the XML to memory instead of to a disk file).

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

[**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)