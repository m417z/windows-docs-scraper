# PFND3D12DDI_CREATESYNCHRONIZATIONOBJECT2CB callback function

## Description

Creates a GPU synchronization object that a device context can signal and wait for. Used by WDDM 2.6 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (that is, the graphics context) that will own the synchronization object that pfnCreateSynchronizationObject2Cb creates.

### `unnamedParam2`

A pointer to a D3D12DDICB_CREATESYNCHRONIZATIONOBJECT2 structure that describes the synchronization object to create.

## Return value

Returns one of the following HRESULT values:

|Return code|Description|
|---|---|
|S_OK|The synchronization object was successfully created.|
|E_OUTOFMEMORY|The function could not allocate memory that was required for it to complete.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Prototype

```
//Declaration

PFND3D12DDI_CREATESYNCHRONIZATIONOBJECT2CB Pfnd3d12ddiCreatesynchronizationobject2cb;

// Definition

HRESULT Pfnd3d12ddiCreatesynchronizationobject2cb
(
	D3D12DDI_HRTDEVICE hDevice
	D3D12DDICB_CREATESYNCHRONIZATIONOBJECT2 *
)
{...}

```

## Remarks

## See also