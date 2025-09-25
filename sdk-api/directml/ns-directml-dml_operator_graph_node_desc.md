## Description

Decribes a node within a graph of DirectML operators defined by [DML_GRAPH_DESC](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_desc) and passed to [IDMLDevice1::CompileGraph](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph).

The behavior of this node is defined by a DirectML operator.

## Members

### `Operator`
Type: **[IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator)***

A DirectML operator defining the behavior of the node.

### `Name`

Type: \_Field\_z\_ \_Maybenull\_ **const char\***

An optional name for the graph connection. If provided, this might be used within certain error messages emitted by the DirectML debug layer.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also

* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_DESC structure](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_desc)
* [DML_GRAPH_NODE_DESC structure](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_node_desc)