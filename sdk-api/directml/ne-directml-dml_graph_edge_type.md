## Description

Defines constants that specify a type of graph edge. See [DML_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc) for the usage of this enumeration.

## Constants

### `DML_GRAPH_EDGE_TYPE_INVALID`

Specifies an unknown graph edge type, and is never valid. Using this value results in an error.

### `DML_GRAPH_EDGE_TYPE_INPUT`

Specifies that the graph edge is described by the [DML_INPUT_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_input_graph_edge_desc) structure.

### `DML_GRAPH_EDGE_TYPE_OUTPUT`

Specifies that the graph edge is described by the [DML_OUTPUT_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_output_graph_edge_desc) structure.

### `DML_GRAPH_EDGE_TYPE_INTERMEDIATE`

Specifies that the graph edge is described by the [DML_INTERMEDIATE_GRAPH_EDGE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_intermediate_graph_edge_desc) structure.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also

* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc)
* [DML_GRAPH_EDGE_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_edge_desc)
* [DML_INPUT_GRAPH_EDGE_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_input_graph_edge_desc)
* [DML_OUTPUT_GRAPH_EDGE_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_output_graph_edge_desc)
* [DML_INTERMEDIATE_GRAPH_EDGE_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_intermediate_graph_edge_desc)