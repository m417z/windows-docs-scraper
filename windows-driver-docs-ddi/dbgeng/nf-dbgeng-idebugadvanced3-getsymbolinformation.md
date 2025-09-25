# IDebugAdvanced3::GetSymbolInformation

## Description

The **GetSymbolInformation** method returns specified information about a symbol.

## Parameters

### `Which` [in]

Specifies the piece of information to return. *Which* can take one of the values in the follow table.

| Value | Information returned |
| --- | --- |
| DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE | Returns the source code file name and line number for a specified breakpoint. The line number is returned to *Buffer* as a ULONG. The file name is returned to *StringBuffer*. |
| DEBUG_SYMINFO_IMAGEHLP_MODULEW64 | Returns an IMAGEHLP_MODULEW64 structure that describes a specified module. For details about this structure, see the IMAGEHLP_MODULE64 topic in the Debug Help Library documentation (dbghelp.chm).<br><br>No string is returned and *StringBuffer*, *StringBufferSize*, and *StringSize* must all be set to zero. |
| DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE | Returns the Unicode name of the symbol specified by location in memory and PDB tag type. The name is returned to *Buffer*. *StringBuffer* is not used. |
| DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS | Returns a list of symbol names and offsets for the symbols in the specified module with the specified PDB tag type. The offsets are returned as an array of ULONG values to *Buffer*. The names are returned in the same order as the offsets to *StringBuffer*. Some names might contain embedded zeros because annotations can have multi-part names; hence, each name is terminated with two null characters. |

### `Arg64` [in]

Specifies a 64-bit argument. This parameter has the following interpretations depending on the value of *Which*:

#### DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE

Ignored.

#### DEBUG_SYMINFO_IMAGEHLP_MODULEW64

The base address of the module whose description is being requested.

#### DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE

Specifies the address in the target's memory of the symbol whose name is being requested.

#### DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS

Specifies the module whose symbols are requested. *Arg64* is a location within the memory allocation of the module.

### `Arg32` [in]

Specifies a 32-bit argument. This parameter has the following interpretations depending on the value of *Which*:

#### DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE

The engine breakpoint ID of the desired breakpoint.

#### DEBUG_SYMINFO_IMAGEHLP_MODULEW64

Set to zero.

#### DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE

The PDB classification of the symbol. *Arg32* must be one of the values in the **SymTagEnum** enumeration defined in Dbghelp.h. For more information, see PDB documentation.

#### DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS

The PDB classification of the symbol. *Arg32* must be one of the values in the **SymTagEnum** enumeration defined in Dbghelp.h. For more information, see PDB documentation.

### `Buffer` [out, optional]

Receives the requested symbol information. The type of the data returned depends on the value of *Which*. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in bytes, of the buffer *Buffer*.

### `InfoSize` [out, optional]

If this method returns **S_OK**, *InfoSize* receives the size, in bytes, of the symbol information returned to *Buffer*. If this method returns **S_FALSE**, the supplied buffer is not big enough, and *InfoSize* receives the required buffer size. If *InfoSize* is **NULL**, this information is not returned.

### `StringBuffer` [out, optional]

Receives the requested string. The interpretation of this string depends on the value of *Which*. If *StringBuffer* is **NULL**, this information is not returned.

### `StringBufferSize` [in]

Specifies the size, in characters, of the string buffer *StringBuffer*.

### `StringSize` [out, optional]

Receives the size, in characters, of the string returned to *StringBuffer*. If *StringSize* is **NULL**, this information is not returned.

##### - Arg32.DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE

The engine breakpoint ID of the desired breakpoint.

##### - Arg32.DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS

The PDB classification of the symbol. *Arg32* must be one of the values in the **SymTagEnum** enumeration defined in Dbghelp.h. For more information, see PDB documentation.

##### - Arg32.DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE

The PDB classification of the symbol. *Arg32* must be one of the values in the **SymTagEnum** enumeration defined in Dbghelp.h. For more information, see PDB documentation.

##### - Arg32.DEBUG_SYMINFO_IMAGEHLP_MODULEW64

Set to zero.

##### - Arg64.DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE

Ignored.

##### - Arg64.DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS

Specifies the module whose symbols are requested. *Arg64* is a location within the memory allocation of the module.

##### - Arg64.DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE

Specifies the address in the target's memory of the symbol whose name is being requested.

##### - Arg64.DEBUG_SYMINFO_IMAGEHLP_MODULEW64

The base address of the module whose description is being requested.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the information would not fit in the buffer *Buffer* or the string would not fit in the buffer *StringBuffer*, so the information or name was truncated. |