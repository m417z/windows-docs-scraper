# PFND3D12DDI_BEGIN_END_QUERY_0003 callback function

## Description

The *pfnBeginQuery* callback function defines the beginning of the portion of a command list to which a query applies.

## Parameters

### `unnamedParam1`

*hCommandList*

A handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `unnamedParam2`

*hQueryHeap*

The handle of a query heap, which represents an array of query results. The underlying data representation of a query result is IHV dependent in query heaps and opaque to applications. Query results are stored in a query heap until they are later “resolved” into the API defined format.

### `unnamedParam3`

*QueryType*

The type of query. Resolve is used by applications to transform a query result previously stored in a query heap into the API defined format. The resolved data is stored in a D3D12 buffer. The results can then be consumed by a shader, predication, or mapped and read on the CPU.

### `unnamedParam4`

*StartElement*

The value of the start element.

## Remarks

Begin/End query and resolve query are scheduled commands that are processed on the GPU. There is no defined entry point to allow CPU processing on the query results.

Queries that don’t apply to multiple commands may be defined to only use EndQuery.
For example, if the D3D12DDI_QUERY_TYPE_VIDEO_DECODE_STATISTICS query only applies to the previous DecodeFrame command in the same command list, only EndQuery is used for this query type.