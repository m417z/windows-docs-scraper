# _FA_ENTRY_TYPE enumeration

## Description

A [DebugFailureAnalysis](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) object has a collection of [failure analysis entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries) (FA entries). Each FA entry has a tag, and each tag is associated with one of the data types in the **FA_ENTRY_TYPE** enumeration. For more information, see [Failure Analysis Entries, Tags, and Data Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze).

An FA entry is an [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure along with an optional data block. The data type of the tag indicates the type of data in the data block.

## Constants

### `DEBUG_FA_ENTRY_NO_TYPE`

There is no data type associated with the tag, and there is no data block.

### `DEBUG_FA_ENTRY_ULONG`

The data block holds a **ULONG** value.

### `DEBUG_FA_ENTRY_ULONG64`

The data block holds a **ULONG64** value.

### `DEBUG_FA_ENTRY_INSTRUCTION_OFFSET`

The data block holds a 64-bit instruction offset.

### `DEBUG_FA_ENTRY_POINTER`

The data block holds a 64-bit pointer.

### `DEBUG_FA_ENTRY_ANSI_STRING`

The data block holds a null-terminated string. The **DataSize** member of the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure holds the size of the string including the null terminator.

### `DEBUG_FA_ENTRY_ANSI_STRINGs`

### `DEBUG_FA_ENTRY_EXTENSION_CMD`

The data block holds a null-terminated string that is a debugger command. An example of a debugger command string is "!analyze -v".

### `DEBUG_FA_ENTRY_STRUCTURED_DATA`

The data block holds a pointer to an [IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2) interface.

### `DEBUG_FA_ENTRY_UNICODE_STRING`

The data block holds a null-terminated Unicode string. The **DataSize** member of the [FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry) structure holds the size of the Unicode string including the null terminator.

### `DEBUG_FA_ENTRY_ARRAY`

A bitwise OR of this value and one of the basic types indicates an array. For example, if the data type is **DEBUG_FA_ENTRY_ARRAY** or **DEBUG_FA_ENTRY_POINTER**, the data block holds an array of pointers.

## See also

[FA_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/ns-extsfns-_fa_entry)

[Failure Analysis Entries](https://learn.microsoft.com/windows-hardware/drivers/debugger/failure-analysis-entries)

[IDebugFAEntryTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfaentrytags)

[IDebugFailureAnalysis2](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nn-extsfns-idebugfailureanalysis2)

[Writing an Analysis Extension Plug-in to Extend !analyze](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-an-analysis-extension-to-extend--analyze)