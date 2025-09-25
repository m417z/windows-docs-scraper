# PFND3D12DDI_RESOLVE_QUERY_DATA callback function

## Description

The *pfnResolveQueryData* callback function transforms a previously stored query into an API defined format.

## Parameters

### `unnamedParam1`

hCommandList

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

hQueryHeap

The handle of a query heap.

### `unnamedParam3`

QueryType

A query type.

### `StartElement`

The value of the start element.

### `ElementCount`

The element count.

### `hDrvDestinationBuffer`

The handle of a destination buffer.

### `DestinationOffset`

The destination offset.

## Remarks

Resolve functionality is used by applications to transform a query result previously stored in a query heap into the API defined format. The resolved data is stored in a buffer. The results can then be consumed by a shader, predication, or mapped and read on the CPU.