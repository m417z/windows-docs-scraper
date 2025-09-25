# PFND3D12DDI_WAITFORSYNCHRONIZATIONOBJECT2CB callback function

## Description

Inserts a wait for the specified synchronization objects in the specified context stream.

## Parameters

### `hDevice`

Handle to a device.

### `unnamedParam2`

Pointer to a [D3D12DDICB_WAITFORSYNCHRONIZATIONOBJECT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_waitforsynchronizationobject2) structure.

## Return value

Returns HRESULT.

## Prototype

```
//Declaration

PFND3D12DDI_WAITFORSYNCHRONIZATIONOBJECT2CB Pfnd3d12ddiWaitforsynchronizationobject2cb;

// Definition

HRESULT Pfnd3d12ddiWaitforsynchronizationobject2cb
(
	D3D12DDI_HRTDEVICE hDevice
	 const D3D12DDICB_WAITFORSYNCHRONIZATIONOBJECT2 *
)
{...}

```

## Remarks

## See also