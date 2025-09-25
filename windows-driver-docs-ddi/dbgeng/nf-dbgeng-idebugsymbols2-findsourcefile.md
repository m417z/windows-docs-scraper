# IDebugSymbols2::FindSourceFile

## Description

The **FindSourceFile** method searches the source path for a specified source file.

## Parameters

### `StartElement` [in]

Specifies the index of an element within the source path to start searching from. All elements in the source path before *StartElement* are excluded from the search. The index of the first element is zero. If *StartElement* is greater than or equal to the number of elements in the source path, the filing system is checked directly.

This parameter can be used with *FoundElement* to check for multiple matches in the source path.

### `File` [in]

Specifies the path and file name of the file to search for.

### `Flags` [in]

Specifies the search flags. For a description of these flags, see [DEBUG_FIND_SOURCE_XXX](https://learn.microsoft.com/previous-versions/ff541495(v=vs.85)).

The flag DEBUG_FIND_SOURCE_TOKEN_LOOKUP should not be set. The flag DEBUG_FIND_SOURCE_NO_SRCSRV is ignored because this method does not include source servers in the search.

### `FoundElement` [out, optional]

Receives the index of the element within the source path that contains the file. If the file was found directly on the filing system (not using the source path) then **-1** is returned to *FoundElement*. If *FoundElement* is **NULL**, this information is not returned.

### `Buffer` [out, optional]

Receives the path and name of the found file. If the flag DEBUG_FIND_SOURCE_FULL_PATH is set, this is the full canonical path name for the file. Otherwise, it is the concatenation of the directory in the source path with the tail of *File* that was used to find the file. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `FoundSize` [out, optional]

Specifies the size, in characters, of the name of the file. If *FoundSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | *File* was not found on the source path. |

## Remarks

The engine uses the following steps--in order--to search for the file:

1. For each directory in the source path, an attempt is made to find an overlap between the end of the directory path and the beginning of the file path. For example, if the source path contains a directory C:\a\b\c\d and *File* is c\d\e\samplefile.c, the file C:\a\b\c\d\e\samplefile.c is a match.

   If the flag DEBUG_FIND_SOURCE_BEST_MATCH is set, the match with the longest overlap is returned; otherwise, the first match is returned.
2. For each directory in the source path, *File* is appended to the directory. If no match is found, this process is repeated and each time the first directory is removed from the beginning of the file path. For example, if the source path contains a directory C:\a\b and *File* is c\d\e\samplefile.c, then the file C:\a\b\e\samplefile.c is a match.

   The first match found is returned.
3. *File* is looked up directly on the filing system.

**Note** Any source servers in the source path are ignored. To include the source servers in the search, use [FindSourceFileAndToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-findsourcefileandtoken) with a module address specified in *ModAddr*.

For more information about using the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

## See also

[DEBUG_FIND_SOURCE_XXX](https://learn.microsoft.com/previous-versions/ff541495(v=vs.85))

[FindSourceFileAndToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-findsourcefileandtoken)

[GetSourceFileLineOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcefilelineoffsets)

[GetSourcePathElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepathelement)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)