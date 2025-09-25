## Description

Describes a graph of DirectML operators used to compile a combined, optimized operator. See [IDMLDevice1::CompileGraph](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph).

## Members

### `InputCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of inputs of the overall graph. Each graph input may be connected to a variable number of internal nodes, therefore this may be different from *InputEdgeCount*.

### `OutputCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of outputs of the overall graph. Each graph output may be connected to a variable number of internal nodes, therefore this may be different from *OutputEdgeCount*.

### `NodeCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of internal nodes in the graph.

### `Nodes`
Type: \_Field\_size\_(NodeCount) **const [DML_GRAPH_NODE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_node_desc)\***

The internal nodes in the graph.

### `InputEdgeCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of connections between graph inputs and inputs of internal nodes in the graph.

### `InputEdges`
Type: \_Field\_size\_(InputEdgeCount) **const [DML_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc)\***

An array of connections between graph inputs and inputs of internal nodes in the graph. The *Type* field within each element should be set to [DML_GRAPH_EDGE_TYPE_INPUT](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_graph_edge_type).

### `OutputEdgeCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of connections between graph outputs and outputs of internal nodes in the graph.

### `OutputEdges`
Type: \_Field\_size\_(OutputEdgeCount) **const [DML_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc)\***

An array of connections between graph outputs and outputs of internal nodes in the graph. The *Type* field within each element should be set to [DML_GRAPH_EDGE_TYPE_OUTPUT](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_graph_edge_type).

### `IntermediateEdgeCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of internal connections between nodes in the graph.

### `IntermediateEdges`
Type: \_Field\_size\_(IntermediateEdgeCount) **const [DML_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc)\***

An array of connections between inputs and outputs of internal nodes in the graph. The Type field within each element should be set to [DML_GRAPH_EDGE_TYPE_INTERMEDIATE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_graph_edge_type)

## Remarks
The graph described by this structure must be a directed acyclic graph. You must define a connection for the input and output of each supplied node, except for inputs and outputs that are optional for the associated operator.

Nodes may use operators that were created using the [DML_TENSOR_FLAG_OWNED_BY_DML](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_flags) flag for certain inputs. Any operator inputs using this flag must be connected to graph inputs. All operator inputs connected to the same graph input must use or omit this flag equivalently.

It is legal to connect operators whose connected inputs and outputs use different dimension counts, sizes, and data types. This implies that the tensor data blob is interpreted differently by each operator. The *TotalTensorSizeInBytes* field of connected tensor inputs and outputs must be identical, though. Operators should only read regions of tensors written by earlier operators. Any padding regions in the output of an operation (resulting from the use of strides) are not guaranteed to be read as zero by down-stream operators.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also
* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_NODE_DESC struct](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_node_desc)
* [DML_GRAPH_EDGE_DESC struct](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc)