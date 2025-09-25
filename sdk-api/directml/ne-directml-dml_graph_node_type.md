## Description

Defines constants that specify a type of graph node. See [DML_GRAPH_NODE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_node_desc) for the usage of this enumeration.

## Constants

### `DML_GRAPH_NODE_TYPE_INVALID`

Specifies an unknown graph edge type, and is never valid. Using this value results in an error.

### `DML_GRAPH_NODE_TYPE_OPERATOR`

Specifies that the graph edge is described by the [DML_OPERATOR_GRAPH_NODE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_graph_node_desc) structure.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also

* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc)
* [DML_GRAPH_NODE_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_node_desc)
* [DML_OPERATOR_GRAPH_NODE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_graph_node_desc)