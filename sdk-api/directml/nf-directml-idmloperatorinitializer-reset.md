# IDMLOperatorInitializer::Reset

## Description

Resets the initializer to handle initialization of a new set of operators.

You may use an initializer only to initialize a fixed set of operators, which are provided either during creation
([IDMLDevice::CreateOperatorInitializer](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-createoperatorinitializer)), or when the initializer is reset. Resetting the initializer allows your
application to reuse an existing initializer object to initialize a new set of operators.

You must not call **Reset** until all outstanding work using the initializer has completed execution on the GPU.

This method is not thread-safe.

## Parameters

### `operatorCount`

Type: **UINT**

This parameter determines the number of elements in the array passed in the *operators* parameter.

### `operators` [in, optional]

Type: **[IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator)***

An optional pointer to a constant array of [IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator) pointers containing the operators that the initializer should initialize.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLOperatorInitializer](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperatorinitializer)