# _SYM_DUMP_PARAM structure

## Description

The IG_DUMP_SYMBOL_INFO [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation provides information about the type of a symbol. When calling **Ioctl** with *IoctlType* set to IG_DUMP_SYMBOL_INFO, *IpvData* should contain an instance of the SYM_DUMP_PARAM structure.

## Members

### `size`

Specifies the size, in bytes, of this structure. It should be set to `sizeof(SYM_DUMP_PARAM)`.

### `sName`

Specifies the name of the symbol to lookup.

### `Options`

Specifies the flags that determine the behavior of this **Ioctl** operation. For a description of these flags, see Remarks.

### `addr`

Specifies the address of the symbol.

### `listLink`

Specifies the field that contains the next item in a linked list. If the symbol is an entry in a linked list, this **Ioctl** operation can iterate over the items in the list using the field specified here as the pointer to the next item in the list. The type of this structure is [FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info).

The callback function specified in the **fieldCallBack** member of this structure is called, during this **Ioctl** operation, for each item in the list. When it is called, it is passed this **linkList** structure with the members filled in for the list entry along with the contents of the **Context** member.

DBG_DUMP_LIST should be set in **Options** to tell this **Ioctl** to iterate over the list.

### `Context`

Specifies a pointer that is passed to the callback function in the **CallbackRoutine** member and to the callback functions in the **fieldCallBack** member of the **linkList** and **Fields** members.

### `pBuffer`

Specifies a buffer that receives information about the symbol. This buffer is only used if the DBG_DUMP_COPY_TYPE_DATA flag is set in **Options**. The size of this buffer is specified in **BufferSize**.

### `CallbackRoutine`

Specifies a callback function that is called by the engine. The engine provides the callback function with information about the symbol and its members.

### `nFields`

Specifies the number of entries in the **Fields** array.

### `Fields`

Specifies an array of [FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info) structures that control the behavior of this operation for individual members of the specified symbol. See FIELD_INFO for details.

### `ModBase`

Receives the location in the target's memory of the start of the module that contains the symbol.

### `TypeId`

Receives the type ID of the symbol.

### `TypeSize`

Receives the size, in bytes, of the symbol in the target's memory.

### `BufferSize`

Specifies the size, in bytes, of the **pBuffer** buffer.

### `fPointer`

Receives a Boolean value that indicates whether the symbol is a pointer. **fPointer** is **FALSE** if the symbol is not a pointer. It is 1 if the symbol is a 32-bit pointer and 3 if the symbol is a 64-bit pointer.

### `fArray`

Receives a Boolean value that indicates whether the symbol is an array. **fArray** is **FALSE** if the symbol is not an array and **TRUE** if it is.

### `fStruct`

Receives a Boolean value that indicates whether the symbol is a structure. **fStruct** is **FALSE** if the symbol is not a structure and **TRUE** if it is.

### `fConstant`

Receives a Boolean value that indicates whether the symbol is a constant. **fConstant** is **FALSE** if the symbol is not a constant and **TRUE** if it is.

### `Reserved`

## Remarks

The parameters for the IG_DUMP_SYMBOL_INFO [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation are the members of the SYM_DUMP_PARAM structure.

This **Ioctl** operation looks up the module information for the symbol, loading module symbols if possible.

If **nFields** is zero and DBG_DUMP_CALL_FOR_EACH is set in **Options**, the callback function specified in **CallbackRoutine** is called for every field in the symbol.

If **nFields** is non-zero and DBG_DUMP_CALL_FOR_EACH is set in **Options**, callbacks are only made for those fields matching the **fName** member of one of the **Fields** elements. If a field matches a **fName** member and the **fieldCallBack** member is not **NULL**, the callback function in **fieldCallBack** is called; if it is **NULL**, the callback function in **CallbackRoutine** is called instead.

###

The DBG_DUMP_*XXX* bit flags are used by the **Options** member of the SYM_DUMP_PARAM structure to control the behavior of the **IG_DUMP_SYMBOL_INFO**[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation.

The following flags can be present.

| Flag | Effect |
| --- | --- |
| DBG_DUMP_NO_INDENT | Members are not indented in the output. |
| DBG_DUMP_NO_OFFSET | Offsets are not printed. |
| DBG_DUMP_VERBOSE | Verbose output. |
| DBG_DUMP_CALL_FOR_EACH | A callback function is called for each member. |
| DBG_DUMP_LIST | The symbol is an entry in a linked list and the IG_DUMP_SYMBOL_INFO **Ioctl** operation will iterate over this list. The description of the member that points to the next item in the list is specified by the **linkList** member of the SYM_DUMP_PARAM structure. |
| DBG_DUMP_NO_PRINT | Nothing is printed (only callback functions are called and data copies are performed). |
| DBG_DUMP_GET_SIZE_ONLY | The **Ioctl** operation returns the size of the symbol only; it will not print member information or call callback functions. |
| DBG_DUMP_COMPACT_OUT | Newlines are not printed after each member. |
| DBG_DUMP_ARRAY | The symbol is an array. The number of elements in the array is specified by the member **listLink->size** of the SYM_DUMP_PARAM structure. |
| DBG_DUMP_ADDRESS_OF_FIELD | The value of **addr** is actually the address of the member **listLink->fName** of the SYM_DUMP_PARAM structure and not the beginning of the symbol. |
| DBG_DUMP_ADDRESS_AT_END | The value of **addr** is actually the address at the end of the symbol and not the beginning of the symbol. |
| DBG_DUMP_COPY_TYPE_DATA | The value of the symbol is copied into the member **pBuffer**. This can only be used for primitive types--for example, ULONG or PVOID--it cannot be used with structures. |
| DBG_DUMP_READ_PHYSICAL | The symbol's value will be read directly from the target's physical memory. |
| DBG_DUMP_FUNCTION_FORMAT | When formatting a symbol that has a function type, the function format will be used, for example, `function(arg1, arg2, ...)` |
| DBG_DUMP_BLOCK_RECURSE | Recurse through nested structures; but do not follow pointers. |

In addition, the result of the macro DBG_DUMP_RECUR_LEVEL(*Level*) can be added to the bit-set to specify how deep into structures to recurse. *Level* can be a number between 0 and 15.

###

The DBG_DUMP_FIELD_*XXX* bit flags are used by the **fOptions** member of the [FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info) structure to control the behavior of the **IG_DUMP_SYMBOL_INFO**[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation.

The following flags can be present.

| Flag | Effect |
| --- | --- |
| DBG_DUMP_FIELD_CALL_BEFORE_PRINT | The callback function is called before printing the member. |
| DBG_DUMP_FIELD_NO_CALLBACK_REQ | No callback function is called. |
| DBG_DUMP_FIELD_RECUR_ON_THIS | Submembers of the member are processed. |
| DBG_DUMP_FIELD_FULL_NAME | **fName** must match completely, as opposed to just having a matching prefix, for the member to be processed. |
| DBG_DUMP_FIELD_ARRAY | Print array elements of an array member. |
| DBG_DUMP_FIELD_COPY_FIELD_DATA | The value of the member is copied into **pBuffer**. |
| DBG_DUMP_FIELD_RETURN_ADDRESS | During a callback or when **Ioctl** returns, the FIELD_INFO.**address** member contains the address of the symbol's member.<br><br>If no address is supplied for the type, FIELD_INFO.**address** contains total offset of the member from the beginning of the type. |
| DBG_DUMP_FIELD_SIZE_IN_BITS | For a bit field, return the offset and size in bits instead of bytes. |
| DBG_DUMP_FIELD_NO_PRINT | Do not print this member (only callback function are called and data copies are performed). |
| DBG_DUMP_FIELD_DEFAULT_STRING DBG_DUMP_FIELD_WCHAR_STRING DBG_DUMP_FIELD_MULTI_STRING DBG_DUMP_FIELD_GUID_STRING | If the member is a pointer, it is printed as a string, ANSI string , WCHAR string, MULTI string, or GUID. |

In addition, the result of the macro DBG_DUMP_RECUR_LEVEL(*Level*) can be added to the bit-set to specify how deep into structures to recurse. *Level* can be a number between 0 and 15.

## See also

[DBG_DUMP_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/dbg-dump-xxx)

[FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info)

[IG_DUMP_SYMBOL_INFO Error Codes](https://learn.microsoft.com/previous-versions/ff550910(v=vs.85))

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)