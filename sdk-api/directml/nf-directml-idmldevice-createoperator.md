# IDMLDevice::CreateOperator

## Description

Creates a DirectML operator.

In DirectML, an operator represents an abstract bundle of functionality, which can be compiled into a form suitable
for execution on the GPU. Operator objects cannot be executed directly; they must first be compiled into an
[IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator).

## Parameters

### `desc`

Type: **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

The description of the operator to be created.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the operator. This is the address of a pointer to an [IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator), representing the operator created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)

[IDMLDevice::CompileOperator](https://msdn.microsoft.com/745DB37D-20BF-4422-B224-A6BDEF272B8D)