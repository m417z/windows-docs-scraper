# CreatePointerMoniker function

## Description

Creates a pointer moniker based on a pointer to an object.

## Parameters

### `punk` [in, optional]

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object to be identified by the resulting moniker.

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the new pointer moniker. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). When an error occurs, the returned interface pointer has a **NULL** value.

## Return value

This function can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

A pointer moniker wraps an existing interface pointer in a moniker that can be passed to those interfaces that require monikers. Pointer monikers allow an object that has no persistent representation to participate in a moniker-binding operation.

Pointer monikers are not commonly used, so this function is not often called.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)