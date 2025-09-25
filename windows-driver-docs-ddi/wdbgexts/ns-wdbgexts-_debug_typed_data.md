# _DEBUG_TYPED_DATA structure

## Description

The DEBUG_TYPED_DATA structure describes typed data in the memory of the target.

## Members

### `ModBase`

The base address of the module, in the target's virtual address space, that contains the typed data.

### `Offset`

The location of the typed data in the target's memory. **Offset** is a virtual memory address unless there are flags present in **Flags** that specify that **Offset** is a physical memory address.

### `EngineHandle`

Set to zero.

### `Data`

The data cast to a ULONG64. If **Flags** does not contain the DEBUG_TYPED_DATA_IS_IN_MEMORY flag, the data is not available and **Data** is set to zero.

### `Size`

The size, in bytes, of the data.

### `Flags`

The flags describing the target's memory in which the data resides. The following bit flags can be set.

| Flag | Description |
| --- | --- |
| DEBUG_TYPED_DATA_IS_IN_MEMORY | The data is in the target's memory and is available. |
| DEBUG_TYPED_DATA_PHYSICAL_DEFAULT | **Offset** is a physical memory address, and the physical memory at **Offset** uses the default memory caching. |
| DEBUG_TYPED_DATA_PHYSICAL_CACHED | **Offset** is a physical memory address, and the physical memory at **Offset** is cached. |
| DEBUG_TYPED_DATA_PHYSICAL_UNCACHED | **Offset** is a physical memory address, and the physical memory at **Offset** is uncached. |
| DEBUG_TYPED_DATA_PHYSICAL_WRITE_COMBINED | **Offset** is a physical memory address, and the physical memory at **Offset** is write-combined. |

### `TypeId`

The type ID for the data's type.

### `BaseTypeId`

For generated types, the type ID of the type on which the data's type is based. For example, if the typed data represents a pointer (or an array), **BaseTypeId** is the type of the object pointed to (or held in the array).

For other types, **BaseTypeId** is the same as **TypeId**.

### `Tag`

The symbol tag of the typed data. This is a value from the **SymTagEnum** enumeration. For descriptions of the values, see the DbgHelp API documentation.

### `Register`

The index of the processor's register containing the data, or zero if the data is not contained in a register. (Note that the zero value can represent either that the data is not in a register or that it is in the register whose index is zero.)

### `Internal`

Internal [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) data.

## Remarks

Instances of this structure should be manipulated using the [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)
 [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation. In particular, instances should be created and released using this method, and members of this structure should not be changed directly.

There is one exception to the preceding rule: the **EXT_TDOP_SET_FROM_TYPE_ID_AND_U64** and **EXT_TDOP_SET_PTR_FROM_TYPE_ID_AND_U64** suboperations take a DEBUG_TYPED_DATA instance that is not manipulated using the **Request** method. These suboperations take a manually created instance with some members manually filled in.

**Note** Include WdbgExts.h before including DbgEng.h. Additionally, **SymTagEnum** is defined in DbgHelp.h (include DbgHelp.h).

## See also

[DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)

[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request)