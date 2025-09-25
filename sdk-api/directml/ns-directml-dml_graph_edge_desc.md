## Description

A generic container for a connection within a graph of DirectML operators defined by [DML_GRAPH_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc) and passed to [IDMLDevice1::CompileGraph](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph).

## Members

### `Type`
Type: **[DML_GRAPH_EDGE_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_graph_edge_type)**

The type of graph edge. See [DML_GRAPH_EDGE_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_graph_edge_type) for available types, and [DML_GRAPH_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc) for where to use each type.

### `Desc`
Type: \_Field\_size\_(\_Inexpressible\_("Dependent on edge type")) **const void\***

A pointer to the graph edge description. The type of the pointed-to struct must match the value specified in *Type*.

## Availability

This API was introduced in DirectML version `1.1.0`.

## See also

* [IDMLDevice1::CompileGraph method](https://learn.microsoft.com/windows/desktop/api/directml/nf-directml-idmldevice1-compilegraph)
* [DML_GRAPH_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc)