# PFND3D12DDI_CALCPRIVATEDESERIALIZEDOBJECTSIZE callback function

## Description

CalcPrivateDeserializedObjectSize is called to get the size of the private driver data that the runtime should allocate for the driver to instantiate an object from serialized form.

## Parameters

### `HDEVICE`

Device handle.

### `HandleType`

Type of object being loaded.

### `BlobSize`

Size of serialized blob.

### `pBlob`

Serialized blob.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATEDESERIALIZEDOBJECTSIZE Pfnd3d12ddiCalcprivatedeserializedobjectsize;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatedeserializedobjectsize
(
	D3D12DDI_HDEVICE HDEVICE
	D3D12DDI_HANDLETYPE HandleType
	SIZE_T BlobSize
	 const UINT *pBlob
)
{...}

```

## Remarks

## See also