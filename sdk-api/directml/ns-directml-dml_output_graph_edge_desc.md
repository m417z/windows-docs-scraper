## Description

Describes a connection within a graph of DirectML operators defined by [DML_GRAPH_DESC](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_desc) and passed to [IDMLDevice1::CompileGraph](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph). This structure is used to define a connection from an output of an internal node to a graph output.

## Members

### `GraphOutputIndex`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The index of the graph output to which a connection from an internal node output is specified.

### `ToNodeIndex`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The index of the internal node from which the connection to the graph output is specified.

### `ToNodeOutputIndex`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The index of the output of the internal node where the connection is specified.

### `Name`

Type: \_Field\_z\_ \_Maybenull\_ **const char\***

An optional name for the graph connection. If provided, this might be used within certain error messages emitted by the DirectML debug layer.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also

* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_DESC structure](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_desc)
* [DML_GRAPH_EDGE_DESC structure](https://learn.microsoft.com/windows/desktop/api/directml/ns-directml-dml_graph_edge_desc)