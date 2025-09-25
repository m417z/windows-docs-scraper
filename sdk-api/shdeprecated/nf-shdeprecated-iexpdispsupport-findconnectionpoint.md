# IExpDispSupport::FindConnectionPoint

## Description

Deprecated. Gets connection points for browser events.

## Parameters

### `riid` [in]

Type: **REFIID**

The IID of the interface on the connection point container whose connection point object is being requested. One of the following values.

#### DIID_DWebBrowserEvents

Value that indicates a member of the [DWebBrowserEvents](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768309(v=vs.85)) interface.

#### DIID_DWebBrowserEvents2

Value that indicates a member of the [DWebBrowserEvents2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768283(v=vs.85)) interface.

#### IID_IPropertyNotifySink

Value that indicates a member of the [IPropertyNotifySink](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink) interface.

### `ppccp` [out]

Type: **CIE4ConnectionPoint****

The address of a pointer to the browser connection point.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IExpDispSupport::FindCIE4ConnectionPoint** was created specifically for use with Windows Internet Explorer 4.0.