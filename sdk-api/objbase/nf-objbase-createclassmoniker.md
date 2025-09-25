# CreateClassMoniker function

## Description

Creates a class moniker that refers to the specified class.

## Parameters

### `rclsid` [in]

A reference to the CLSID of the object type to which this moniker binds.

### `ppmk` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the new class moniker. On successful return, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). When an error occurs, the value of the moniker pointer is **NULL**.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The moniker has been created successfully. |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

The class moniker will support the binding to a fresh instance of the class identified by the CLSID in *rclsid*.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)