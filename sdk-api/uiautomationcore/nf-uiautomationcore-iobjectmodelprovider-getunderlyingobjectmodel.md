# IObjectModelProvider::GetUnderlyingObjectModel

## Description

Retrieves an interface used to access the underlying object model of the provider.

## Parameters

### `ppUnknown` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives an interface for accessing the underlying object model.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Client applications can use the object model to directly access the content of the control or application.

## See also

[IObjectModelProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iobjectmodelprovider)