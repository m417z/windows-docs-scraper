# _DEBUG_REGISTER_DESCRIPTION structure

## Description

The **DEBUG_REGISTER_DESCRIPTION** structure is returned by [GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getdescription) to describe a processor's register.

## Members

### `Type`

The type of value that this register holds. The possible values are the same as for the **Type** field in the [DEBUG_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_value) structure.

### `Flags`

A bit field of flags for the register. Currently, the only bit that can be set is DEBUG_REGISTER_SUB_REGISTER, which indicates that this register is a subregister.

### `SubregMaster`

The index of the register of which this register is a sub-register. This field is only used if the DEBUG_REGISTER_SUB_REGISTER bit is set in **Flags**; otherwise, it is set to zero.

### `SubregLength`

The size, in bits, of this sub-register. This field is only used if the DEBUG_REGISTER_SUB_REGISTER bit is set in **Flags**; otherwise, it is set to zero.

### `SubregMask`

The bit mask that converts the register specified in **SubregMaster** into this sub-register. This field is only used if the DEBUG_REGISTER_SUB_REGISTER bit is set in **Flags**; otherwise, it is set to zero.

### `SubregShift`

The bit shift that converts the register specified in **SubregMaster** into this sub-register. This field is only used if the DEBUG_REGISTER_SUB_REGISTER bit is set in **Flags**; otherwise, it is set to zero.

### `Reserved0`

Reserved for system use.

## Remarks

If this register is a subregister, the value of the full register can be turned into the value of the sub-register by first shifting **SubregShift** bits to the right and then combining the result with **SubregMask** using the bitwise-AND operator. The size of the sub-register (**SubregLength**) is the number of bits set in **SubregMask**.

For general information about registers, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).