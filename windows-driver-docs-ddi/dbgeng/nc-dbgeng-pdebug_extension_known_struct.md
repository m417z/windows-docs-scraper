# PDEBUG_EXTENSION_KNOWN_STRUCT callback function

## Description

The engine calls the *KnownStructOutput* callback function to request information about structures that the extension DLL can format for printing. The engine calls this function for the following reasons.

* Get a list of structures that the DLL can format for printing.
* Get a single-line representation of a particular structure.
* Ask whether a particular structure should have its name printed along with its single-line representation.

```cpp
 CALLBACK* PDEBUG_EXTENSION_KNOWN_STRUCT KnownStructOutput;
```

## Parameters

### `Flags` [in]

One of the following values, depending on what information the engine wants to obtain from the extension DLL.

| Value | Description |
| --- | --- |
| DEBUG_KNOWN_STRUCT_GET_NAMES | Get a list of structure names. |
| DEBUG_KNOWN_STRUCT_SUPPRESS_TYPE_NAME | Ask whether a structure should have its name printed. |
| DEBUG_KNOWN_STRUCT_GET_SINGLE_LINE_OUTPUT | Get a single-line representation of a structure. |

### `Offset` [in]

**When getting a list of names:** Unused.

**When asking whether a name should be printed:** Unused.

**When getting a single-line representation:** Specifies the location in the target's memory address space of the structure to be printed.

### `TypeName` [in]

**When getting a list of names:** Unused.

**When asking whether a name should be printed:** Specifies the name of the structure. This is one of the names returned from the DEBUG_KNOWN_STRUCT_GET_NAMES query.

**When getting a single-line representation:** Specifies the name of the structure. This is one of the names returned from the DEBUG_KNOWN_STRUCT_GET_NAMES query.

### `Buffer` [out]

**When getting a list of names:** Receives a list of the names of the structures that the extension can format for printing. One null character must appear between each pair of names. The list must be terminated with two null characters. The number of characters written to this buffer must not exceed the value of *BufferSize*.

**When asking whether a name should be printed:** Unused.

**When getting a single-line representation:** Receives a representation of the structure, identified by *StructName* and *Address*, as a string. The number of characters written to this buffer must not exceed the value of *BufferSize*.

### `BufferChars` [in, out]

**When getting a list of names:** On input, specifies the size, in characters, of *Buffer*. On output, if the buffer is too small, receives the required buffer size.

**When asking whether a name should be printed:** Unused.

**When getting a single-line representation:** On input, specifies the size, in characters, of *Buffer*. On output, if the buffer is too small, receives the required buffer size.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | **When getting a list of names:** *Buffer* contains the requested list of names.<br><br>**When asking whether a name should be printed:** The printing of the name should be suppressed. That is, the name should not be printed. <br><br>**When getting a single-line representation:** *Buffer* contains the requested single-line representation. |
| **S_FALSE** | **When getting a list of names:** *BufferSize* was too small on input. On output,  *BufferSize* contains the required buffer size.<br><br>**When asking whether a name should be printed:** The printing of the name should not be suppressed. That is, the name should be printed. <br><br>**When getting a single-line representation:** *BufferSize* was too small on input. On output,  *BufferSize* contains the required buffer size. |

All other return values indicate that the function failed. The engine will continue ignoring the contents of *Buffer*.

## Remarks

This function is optional. An extension DLL only needs to export **KnownStructOutput** if it has the ability to format special structures for printing on a single line. The engine looks for this function by name in the extension DLL.

After initializing the extension DLL, the engine calls this function to query the DLL for the list of structure names it knows how to print. Then, whenever the engine prints a summary of one of the structures whose name is in the list, it calls this function to format the structure for printing.

[KnownStructOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_known_struct) is called **PDEBUG_EXTENSION_KNOWN_STRUCT** in the Dbgeng.h header file.

## See also

[DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)