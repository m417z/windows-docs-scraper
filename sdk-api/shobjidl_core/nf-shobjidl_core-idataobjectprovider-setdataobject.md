# IDataObjectProvider::SetDataObject

## Description

Wraps an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) instance as a Windows Runtime [DataPackage](https://learn.microsoft.com/uwp/api/Windows.ApplicationModel.DataTransfer.DataPackage).

## Parameters

### `dataObject` [in]

An [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface pointer to the data object from which to build the DataPackage object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDataObjectProvider](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idataobjectprovider)

[IDataObjectProvider::GetDataObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idataobjectprovider-getdataobject)