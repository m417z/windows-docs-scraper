# MrmDumpType enumeration

Defines constants that specify the type of PRI file dump to produce when calling one of the **MrmDumpPri...** functions.

## Constants

**MrmDumpType\_Basic**

Include string and file resources, but exclude embedded binary data. This is generally the most useful
dump type for debugging.

**MrmDumpType\_Detailed**

Include all resources, including embedded binary data, plus additional indexing information. This is most
useful for round-tripping XML back to a PRI file or debugging advanced problems.

**MrmDumpType\_Schema**

Include only resource names and indices, not candidates. This is the smallest dump type, and can be used
when building versioned PRI files (see **Remarks** for more info).

## Remarks

PRI files are stored an undocumented binary format, so the only way to view their contents is to dump them to XML
via one of the **MrmDumpPri...** functions. Dumping the XML is useful for three purposes:

1. The XML is human-readable, enabling you to see the contents of the file, debug issues with unresolved resources or
incorrectly-qualified candidates, and so on.
1. The XML is machine-readable, making it possible for tools to manipulate PRI files and generate new PRI files via the
intermediate XML format.
    * *Note that there is no built-in mechanism to turn an XML dump back into a PRI file; it must be done manually by
creating a Resource Indexer, adding the resource candidates from the XML file, and writing out the new file.*
1. The **Schema** dump type can be used to create versioned PRI files.

The **Basic** dump type is sufficient for most debugging purposes. It lists all resource names and candidate values,
with the exception of embedded binary data - but since embedded binary data isn't human-readable anyway, that is
typically not a problem.

The **Detailed** dump type is the most complete - including BASE64-encoded embedded binary data - but includes a lot
of extra data that make it harder to read (especially if there are large embedded binary resources). A **Detailed** dump
file can be used to round-trip back into the original PRI file.

The **Schema** dump type is the smallest dump type, and only includes information about the resource names and indices
in the PRI file (the "Schema" of the file). A **Schema** dump can be used with one of the
**MrmCreateResourceIndexerFromPreviousSchema...** functions to create versionable PRI files - see the **Remarks** in
[**MrmCreateResourceIndexerFromPreviousSchemaFile**](https://learn.microsoft.com/windows/win32/menurc/mrmcreateresourceindexerfrompreviousschemafile) for more
info. Note there is no guarantee that the resources listed in a **Schema** dump actually have candidates defined in
the PRI file, so this is insufficient for debugging "missing" resource errors.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1803 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server \[desktop apps only\]<br> |
| Header<br> | MrmResourceIndexer.h |

## See also

[**MrmDumpPriDataInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumppridatainmemory)

[**MrmDumpPriFile**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifile)

[**MrmDumpPriFileInMemory**](https://learn.microsoft.com/windows/win32/menurc/mrmdumpprifileinmemory)

[Package resource indexing (PRI) APIs and custom build systems](https://learn.microsoft.com/windows/uwp/app-resources/pri-apis-custom-build-systems)