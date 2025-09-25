# IDebugAdvanced3::FindSourceFileAndToken

## Description

The **FindSourceFileAndToken** method returns the filename of a source file on the source path or return the value of a variable associated with a file token.

## Parameters

### `StartElement` [in]

Specifies the index of an element within the source path to start searching from. All elements in the source path before *StartElement* are excluded from the search. The index of the first element is zero. If *StartElement* is greater than or equal to the number of elements in the source path, the filing system is checked directly.

This parameter can be used with *FoundElement* to check for multiple matches in the source path.

*StartElement* is ignored if the flag DEBUG_FIND_SOURCE_TOKEN_LOOKUP is set in *Flags*.

### `ModAddr` [in]

Specifies a location within the memory allocation of the module in the target to which the source file is related. *ModAddr* is used for caching the search results and when querying source servers for the file. *ModAddr* can be **NULL**.

*ModAddr* is ignored if the flag DEBUG_FIND_SOURCE_TOKEN_LOOKUP is set in *Flags*. And it is not used for querying source servers if *FileToken* is not **NULL**.

### `File` [in]

Specifies the path and filename of the file to search for.

If the flag DEBUG_FIND_SOURCE_TOKEN_LOOKUP is set, the file is already specified by the token in *FileToken*. In this case, *File* specifies the name of a variable on the source server related to the file. The variable must begin and end with the percent sign ( **%** ), for example, **%SRCSRVCMD%**. The value of this variable is returned.

### `Flags` [in]

Specifies the flags that control the behavior of this method. For a description of these flags, see Remarks.

### `FileToken` [in, optional]

Specifies a file token representing a file on a source server. A file token can be obtained by setting *Which* to DEBUG_SRCFILE_SYMBOL_TOKEN in the method [GetSourceFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-getsourcefileinformation).

If the flag DEBUG_FIND_SOURCE_TOKEN_LOOKUP is set, *FileToken* must not be **NULL**.

### `FileTokenSize` [in]

Specifies the size in bytes of the *FileToken* token. If *FileToken* is **NULL**, this parameter is ignored.

### `FoundElement` [out, optional]

Receives the index of the element within the source path that contained the file. If the file was found directly on the filing system (not using the source path), -1 is returned to *FoundElement*. If *FoundElement* is **NULL** or *Flags* contain DEBUG_SRCFILE_SYMBOL_TOKEN, this information is not returned.

### `Buffer` [out, optional]

Receives the name of the file that was found. If the file is not on a source server, this is the name of the file in the local source cache. If the flag DEBUG_FIND_SOURCE_FULL_PATH is set, this is the full canonical path name for the file. Otherwise, it is the concatenation of the directory in the source path with the tail of *File* that was used to find the file.

If the flag DEBUG_SRCFILE_SYMBOL_TOKEN is set in *Flags*, *Buffer* receives the value of the variable named *File* associated with the file token *FileToken*.

If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the *Buffer* buffer. This size includes the space for the '\0' terminating character. If *Buffer* is **NULL**, this parameter is ignored.

### `FoundSize` [out, optional]

Specifies the size in characters of the name of the file. This size includes the space for the '\0' terminating character. If *foundSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the *Buffer* buffer was too small to hold the file name or variable value, so the string was truncated to fit in the buffer. |

## Remarks

When the flag DEBUG_SRCFILE_SYMBOL_TOKEN is set in *Flags*, this method does not search for a file on the source path. Instead, it looks up a variable associated with the file token provided in *FileToken*. These variables are documented in the topic [Language Specification 1](https://learn.microsoft.com/windows-hardware/drivers/debugger/language-specification-1). For example, to retrieve the value of the variable SRCSRVCMD--the command to extract the source file from source control (also returned by the DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE function of [GetSourceFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-getsourcefileinformation))--set *File* to **%SRCSRVCMD%**.

The engine uses the following steps--in order--to search for the file:

1. If the source path contains any source servers and the flag DEBUG_FIND_SOURCE_NO_SRCSRV is not set, the source server in the source path is searched first.

   The first match found is returned.
2. For each directory in the source path, an attempt is made to find an overlap between the end of the directory path and the beginning of the file path. For example, if the source path contains a directory C:\a\b\c\d and *File* is c\d\e\foo.c, the file C:\a\b\c\d\e\foo.c is a match.

   If the flag DEBUG_FIND_SOURCE_BEST_MATCH is set, the match with the longest overlap is returned; otherwise, the first match is returned.
3. For each directory in the source path, *File* is appended to the directory. If no match is found, this process is repeated and each time the first directory is removed from the beginning of the file path. For example, if the source path contains a directory C:\a\b and *File* is c\d\e\foo.c, the file C:\a\b\e\foo.c is a match.

   The first match found is returned.
4. The file *File* is looked up directly on the filing system.

For more information about source files, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

The DEBUG_FIND_SOURCE_*XXX* bit-flags are used to control the behavior of the methods [FindSourceFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-findsourcefile) and **FindSourceFileAndToken** when searching for source files.

The flags can be any combination of values from the following table.

| Constant | Description |
| --- | --- |
| **DEBUG_FIND_SOURCE_FULL_PATH** | Always return the full canonical path name for the found file.<br><br>If not set and the source path contains relative directories, relative path names can be returned. |
| **DEBUG_FIND_SOURCE_BEST_MATCH** | Continue searching after a match has been found to look for a better match. |
| **DEBUG_FIND_SOURCE_NO_SRCSRV** | Do not include source servers in the search. |
| **DEBUG_FIND_SOURCE_TOKEN_LOOKUP** | Return a variable associated with a file token.<br><br>If this flag is set, the other flags are ignored. This flag cannot be used in the [FindSourceFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-findsourcefile) method. |

The value DEBUG_FIND_SOURCE_DEFULT defines the default set of flags, which means that all of the flags in the previous table are turned off.

## See also

[DEBUG_FIND_SOURCE_XXX](https://learn.microsoft.com/previous-versions/ff541495(v=vs.85))

[FindSourceFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-findsourcefile)

[GetSourceFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-getsourcefileinformation)

[GetSourcePathElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepathelement)

[IDebugAdvanced2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced2)

[IDebugAdvanced3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced3)