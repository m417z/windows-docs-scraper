# PFND3D12DDI_SERIALIZE_LIBRARY_0010 callback function

## Description

Implemented by the client driver to serialize the library.

## Parameters

### `hDevice`

A device handle.

### `hLibrary`

A library handle.

### `pBlob`

Pointer to a blob.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_SERIALIZE_LIBRARY_0010 Pfnd3d12ddiSerializeLibrary0010;

// Definition

HRESULT Pfnd3d12ddiSerializeLibrary0010
(
	D3D12DDI_HDEVICE hDevice
	D3D12DDI_HPIPELINELIBRARY hLibrary
	VOID *pBlob
)
{...}

PFND3D12DDI_SERIALIZE_LIBRARY_0010

```

## Remarks

## See also