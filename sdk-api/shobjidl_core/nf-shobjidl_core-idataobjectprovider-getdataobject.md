# IDataObjectProvider::GetDataObject

## Description

Gets an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) representation of the current [DataPackage](https://learn.microsoft.com/uwp/api/Windows.ApplicationModel.DataTransfer.DataPackage) object.

## Parameters

### `dataObject` [out]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)****

The address of an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface pointer that, when this method returns successfully, points to the **IDataObject** representation of the [DataPackage](https://learn.microsoft.com/uwp/api/Windows.ApplicationModel.DataTransfer.DataPackage) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDataObjectProvider](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idataobjectprovider)

[IDataObjectProvider::SetDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idataobjectprovider-setdataobject)