## Description

Compiles a graph of DirectML operators into an object that can be dispatched to the GPU.

A compiled operator represents the efficient, baked form of an operator suitable for execution on the GPU. A compiled operator holds state (such as shaders and other objects) required for execution. Because a compiled operator implements the [IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable) interface, you're able to evict one from GPU memory if you wish. See [IDMLDevice1::Evict](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-evict) and [IDMLDevice1::MakeResident](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-makeresident) for more info.

The compiled operator doesn't use nor reference the [IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator) objects supplied within the graph description after this method returns.

## Parameters

### `desc`

Type: **[DML_GRAPH_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc)\***

A description of the graph to compile. See [DML_GRAPH_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_graph_desc).

### `flags`

Type: [**DML_EXECUTION_FLAGS**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_execution_flags)

Any flags to control the execution of this operator.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the compiled operator. This is the address of a pointer to an [IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator), representing the compiled operator created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks
The DirectML operator graph API provides an abstract way to use DirectML efficiently across diverse hardware. DirectML applies tensor-level optimizations such as choosing the most efficient tensor layout based on the adapter being used. It also applies optimizations such as the removal of Join or Split operators.

We recommend that you apply high-level optimizations before building a DirectML graph. For example, fusing Convolution operators with BatchNorm, constant folding, and common subexpression elimination. The optimizations within DirectML's graph optimizer are intended to complement such device-independent optimizations, which are typically handled generically by machine learning frameworks.

## See also

[IDMLDevice1](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)