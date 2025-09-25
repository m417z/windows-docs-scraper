## Description

Associates an [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface with the device object, and associates that interface with an application-defined **GUID**.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** to associate with the interface.

### `pData` [in, optional]

Type: **const [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)\***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface to be associated with the device object. Its reference count is incremented when set, and decremented when either the [ID3D12Object](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12object) is destroyed, or when the data is overwritten by calling [SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setprivatedata) or **SetPrivateDataInterface** with the same **GUID**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 return codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

* [ID3D12Object](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12object)