# MrmDumpPriDataInMemory function

Dumps an in-memory PRI file to its XML equivalent, storing the result in memory. PRI files are stored in an
undocumented binary format, so in order to view the contents of a file for debugging etc. it must be saved
("dumped") XML.

This function performs the equivalent of the `makepri dump` command, but entirely in memory.

COM must be initialized (e.g. by calling **[CoInitializeEx](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex)**) before using this function.

## Parameters

*inputPriData* \[in\]

Type: **BYTE\***

A pointer to an in-memory PRI file. If this in-memory file does not have an embedded schema, then *schemaPriData*
is required.

*inputPriSize* \[in\]

Type: **ULONG**

The size of the data pointed to by *inputPriData*.

*schemaPriData* \[in, optional\]

Type: **BYTE\***

A pointer to an in-memory PRI file that provides the schema for *inputPriData* if needed, otherwise **NULL**.
See the **Remarks** section of [**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile) for more info.

*schemaPriSize* \[in\]

Type: **ULONG**

The size of the data pointed to by *schemaPriData*.

*dumpType* \[in\]

Type: **[**MrmDumpType**](https://learn.microsoft.com/windows/win32/menurc/mrmdumptype)**

Specified the kind of dump to create. For most debugging use-cases, **MrmDumpTypeBasic** is sufficient. See the
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
as this function is essentially the same (except it works with in-memory data instead of files).

You can obtain an in-memory PRI file either by manually loading an existing PRI file from disk, or by creating it
in-memory with [**MrmCreateResourceFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateconfig).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |
| Library<br> | Mrmsupport.lib |
| DLL<br> | Mrmsupport.dll |

## See also

[**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile)

[**MrmDumpPriFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifileinmemory)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)

