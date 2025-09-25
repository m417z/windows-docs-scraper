# IDMLObject::SetPrivateDataInterface

## Description

Associates an [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface with the DirectML device object, and associates that interface with an application-defined **GUID**. This method is thread-safe.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** to associate with the interface.

### `data` [in, optional]

Type: **const [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface to be associated with the device object.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLObject](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlobject)