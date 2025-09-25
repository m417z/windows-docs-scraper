# _FIELD_INFO structure

## Description

The **FIELD_INFO** structure is used by the [IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param)
[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation to provide information about a member in a structure.

## Members

### `fName`

Specifies the name of the symbol's member to which this structure applies. Submembers can be specified using the delimiters "**.**" and "**->**". Unless DBG_DUMP_FIELD_FULL_NAME is set in **fOptions**, **fName** is considered to be the beginning of the member name.

### `printName`

Specifies an alternative name to use when printing the name of the member. If **printName** is **NULL**, the actual name of the member is used when printing the name of the member.

### `size`

Receives the size in the target's memory, in bytes, of the member that is specified by **fName**.

If the member is an array, **size** specifies the number of elements in the array.

### `fOptions`

Specifies the flags that determine the behavior of the IG_DUMP_SYMBOL_INFO **Ioctl** operation. For a description of these flags, see [DBG_DUMP_FIELD_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/dbg-dump-field-xxx).

### `address`

Receives the address in the target's memory of the member that is specified by **fName**. If no address is supplied for the symbol type in SYM_DUMP_PARAM.**addr**, **address** receives the offset of the member relative to the beginning of an instance of the type. For more information about SYM_DUMP_PARAM, see [IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param).

### `fieldCallBack`

Specifies a [PSYM_DUMP_FIELD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-psym_dump_field_callback) callback function to be called with the information about the member that is specified by **fName**. The callback function is passed a structure with the field information and the value of SYM_DUMP_PARAM.**context**.

No callback function is called if DBG_DUMP_FIELD_NO_CALLBACK_REQ is set in **fOptions**, **fieldCallBack** is **NULL**, or the **Options** member of the SYM_DUMP_PARAM structure passed to **Ioctl** does not have DBG_DUMP_CALL_FOR_EACH set. If DBG_DUMP_FIELD_COPY_FIELD_DATA is set in **fOptions**, **fieldCallBack** is not used.

### `pBuffer`

Specifies a buffer to receive the value of the member specified by **fName**. This member is only used if DBG_DUMP_FIELD_COPY_FIELD_DATA is set in **fOptions**.

### `TypeId`

Receives the identifier for the type of the member that is specified by **fName**.

### `FieldOffset`

Receives the offset of the member within the structure.

### `BufferSize`

Specifies the size, in bytes, of the **pBuffer** buffer.

### `BitField`

Receives information about bit fields in a structure.

### `BitField.Position`

Receives the start position of the bit field. This is the number of bits from to the beginning of the structure to the bit field.

### `BitField.Size`

Receives the size, in bits, of the bit field.

### `_BitField`

Receives information about bit fields in a structure.

### `fPointer`

Receives a Boolean value that indicates whether the member is a pointer. **fPointer** is **FALSE** if the member is not a pointer. It is 1 if the member is a 32-bit pointer and 3 if the member is a 64-bit pointer.

### `fArray`

Receives a Boolean value that indicates whether the member is an array. **fArray** is **FALSE** if the field is not an array and **TRUE** if it is.

### `fStruct`

Receives a Boolean value that indicates whether the member is a structure. **fStruct** is **FALSE** if the member is not a structure and **TRUE** if it is.

### `fConstant`

Receives a Boolean value that indicates whether the member is a constant. **fConstant** is **FALSE** if the member is not a constant and **TRUE** if it is.

### `fStatic`

### `Reserved`

## Remarks

When calling the [IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param)
[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation, the **fName** member of this structure should be set to the name of the symbol's member to which this structure applies and the **fOptions** member should reflect the desired functionality of the operation. The other members are either optional, or are filled in by **Ioctl**.

## See also

[DBG_DUMP_FIELD_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/dbg-dump-field-xxx)

[IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param)

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)

[PSYM_DUMP_FIELD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-psym_dump_field_callback)