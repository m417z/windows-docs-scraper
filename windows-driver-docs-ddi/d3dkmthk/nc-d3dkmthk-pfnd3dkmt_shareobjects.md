# PFND3DKMT_SHAREOBJECTS callback function

## Description

The PFND3DKMT_SHAREOBJECTS callback function shares resource objects that were created with the D3DKMTCreateAllocation, D3DKMTCreateKeyedMutex2, and D3DKMTCreateSynchronizationObject2 functions.

## Parameters

### `cObjects:`

### `hObjects:`

### `pObjectAttributes:`

### `dwDesiredAccess:`

### `phSharedNtHandle:`

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

PFND3DKMT_SHAREOBJECTS Pfnd3dkmtShareobjects;

// Definition

NTSTATUS Pfnd3dkmtShareobjects
(
	UINT cObjects
	 const D3DKMT_HANDLE *hObjects
	POBJECT_ATTRIBUTES pObjectAttributes
	DWORD dwDesiredAccess
	HANDLE *phSharedNtHandle
)
{...}

```

## Remarks

## See also