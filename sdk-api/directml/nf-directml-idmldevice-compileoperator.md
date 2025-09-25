# IDMLDevice::CompileOperator

## Description

Compiles an operator into an object that can be dispatched to the GPU.

A compiled operator represents the efficient, baked form of an operator suitable for execution on the GPU.
A compiled operator holds state (such as shaders and other objects) required for execution. Because a compiled operator
implements the [IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable) interface, you're able to evict one from GPU memory if you wish. See
[IDMLDevice::Evict](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-evict) and [IDMLDevice::MakeResident](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-makeresident) for more info.

The compiled operator maintains a strong reference to the supplied [IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator) pointer.

## Parameters

### `op`

Type: **[IDMLOperator](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmloperator)***

The operator (created with [IDMLDevice::CreateOperator](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-createoperator)) to compile.

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

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)