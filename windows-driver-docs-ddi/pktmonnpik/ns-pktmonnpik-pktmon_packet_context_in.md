## Description

The **PKTMON_PACKET_CONTEXT_IN** struct is used to contain the packet context, which can represent a piece of data that is meaningful to the component, like a connection ID.

## Members

### `Header`

Common header for version control.

### `Id`

Integer that is meaningful to the component, representing the type of data stored by fields *Value* and *Size*.

### `Value`

Pointer to the value stored in the packet context.

### `Size`

Size of the data pointed to by Value.

## Remarks

Currently only size 8 (sizeof(UINT64)) is supported. This implies that Value should point to a UINT64.

### See also

- [PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)
- [PktMonClntHeaderInfoDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfodrop)