# _SDP_NODE_DATA structure

## Description

The SDP_NODE_DATA union holds the data of an element in a tree-based representation of an SDP record.

## Members

### `int128`

The union member for a 128-bit integer.

### `uint128`

The union member for an unsigned 128-bit integer.

### `uuid128`

The union member for a 128-bit universally unique identifier (UUID).

### `uuid32`

The union member for a 32-bit UUID.

### `uuid16`

The union member for a 16-bit UUID.

### `int64`

The union member for a 64-bit integer.

### `uint64`

The union member for an unsigned 64-bit integer.

### `int32`

The union member for a 32-bit integer.

### `uint32`

The union member for an unsigned 32-bit integer.

### `int16`

The union member for a 16-bit integer.

### `uint16`

The union member for an unsigned 16-bit integer.

### `int8`

The union reserved for an 8-bit integer.

### `uint8`

The union member for an unsigned 8-bit integer.

### `boolean`

The union member for a Boolean value.

### `string`

The union member for a string value.

### `url`

The union member for a URL value.

### `sequence`

An [SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header) structure that references the elements of a sequence.

### `alternative`

An SDP_NODE_HEADER structure that references the elements of an alternate list sequence.

### `container`

A list of pointers to user-mode specific interfaces.

### `stream`

The address of a portion of the original SDP stream that produced the current SDP node.

### `streamLength`

The length of the portion of the original SDP stream that produced the current SDP node.

## Remarks

Each [SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node) structure in the tree representation of an SDP record contains a SDP_NODE_HEADER structure and an SDP_NODE_DATA union.

The header specifies the type of data. Driver developers can access links to peer **SDP_NODE** structures by calling the [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure of the header. By evaluating `Node.hdr.Link.Flink`and `Node.hdr.Link.Blink`, drivers can obtain the addresses of peer nodes in the tree. Keep in mind that **LIST_ENTRY** pointers contain the addresses of other LIST_ENTRY structures, and that the profile driver must use the [CONTAINING_RECORD](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record) memory manager macro to extract the address of the containing node record.

The unnamed struct contains the union member for a 128-bit integer.

## See also

- [SDP_NODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node_header)
- [SDP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/sdpnode/ns-sdpnode-_sdp_node)
- [LIST_ENTRY](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry)
- [CONTAINING_RECORD](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-containing_record)