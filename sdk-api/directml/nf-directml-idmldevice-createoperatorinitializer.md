# IDMLDevice::CreateOperatorInitializer

## Description

Creates an object that can be used to initialize compiled operators.

Once compiled, an operator must be
initialized exactly once on the GPU before it can be executed. The operator initializer holds the state
necessary for initialization of one or more target compiled operators.

Once instantiated, dispatch of the operator initializer can be recorded in a command list via
[IDMLCommandRecorder::RecordDispatch](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlcommandrecorder-recorddispatch). After execution completes on the GPU, all compiled operators that are
targets of the initializer enter the initialized state.

An operator initializer can be reused to initialize different sets of compiled operators. See
[IDMLOperatorInitializer::Reset](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmloperatorinitializer-reset) for more info.

An operator initializer can be created with no target operators. Executing such an initializer is a no-op.
Creating an operator initializer with no target operators may be useful if you wish to create an initializer
up-front, but don't yet know which operators it will be used to initialize. [IDMLOperatorInitializer::Reset](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmloperatorinitializer-reset) can be used to reset which
operators to target.

## Parameters

### `operatorCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This parameter determines the number of elements in the array passed in the *operators* parameter.

### `operators` [in, optional]

Type: **[IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator)***

An optional pointer to a constant array of [IDMLCompiledOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlcompiledoperator) pointers containing the set of operators that this initializer will target. Upon execution of the initializer, the target
operators become initialized. This array may be null or empty, indicating that the initializer has no target
operators.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *ppv*. This is expected to be the GUID of [IDMLOperatorInitializer](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperatorinitializer).

### `ppv` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the operator initializer. This is the address of a pointer to an [IDMLOperatorInitializer](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperatorinitializer), representing the operator initializer created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)