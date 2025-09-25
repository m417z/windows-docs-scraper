# IUPnPDescriptionDocument::LoadAsync

## Description

The
**LoadAsync** method loads a document asynchronously. This method returns control to the caller immediately, and uses the specified callback to notify the caller when the operation is complete.

## Parameters

### `bstrUrl` [in]

Specifies the URL of the document to load. If the URL specified is a relative URL, the server name is prepended to the value of *bstrUrl*.

### `punkCallback` [in]

Reference to an **IUnknown** specifying the callback that the UPnP framework uses to notify the caller when the operation is complete. If the load operation did not fail immediately, this callback indicates whether or not the load operation succeeded or failed. The object referred to by *pUnkCallback* must support either the
[IUPnPDescriptionDocumentCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocumentcallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP return values.

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_ELEMENT_EXPECTED** | The XML document does not have a device element It is missing either from the root element or the **DeviceList** element. |
| **UPNP_E_DEVICE_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Device** element. |
| **UPNP_E_ICON_ELEMENT_EXPECTED** | The XML document does not have an icon element. It is missing from the **IconList** element, or the **DeviceList** element does not contain an **IconList** element. |
| **UPNP_E_ICON_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Icon** element. |
| **UPNP_E_ROOT_ELEMENT_EXPECTED** | The XML document does not have a root element at the top level of the document. |
| **UPNP_E_SERVICE_ELEMENT_EXPECTED** | The XML document does not have a service element. It is missing from the **ServiceList** element, or the **DeviceList** element does not contain a **ServiceList** element. |
| **UPNP_E_SERVICE_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Service** element. |

## Remarks

This method should not be called from a user interface thread because it can take a long time for the method to return.

If you invoke this method for the same object immediately after a previous invocation, the first invocation of
**LoadAsync** is aborted. To avoid this, wait for the
[IUPnPDescriptionDocumentCallback::LoadComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocumentcallback-loadcomplete) callback, and then use
[LoadResult](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-get_loadresult) to view the state information.

If the
**LoadAsync** method is called by a script within a Web page, *bstrUrl* might be a relative URL. The address of the current Web page is used as the base URL.

If this method is called from a Web page, the URL that the caller specifies must refer to the same server from which the Web page was loaded.

The object referred to by *pUnkCallback* must either support the
[IUPnPDescriptionDocumentCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocumentcallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. The
**LoadAsync** method first queries *pUnkCallback* for the
**IUPnPDescriptionDocumentCallback** interface. If this interface is not supported, the
**LoadAsync** method then queries *pUnkCallback* for the **IDispatch** interface. If the **IDispatch** interface is not supported, both checks have failed and the
**LoadAsync** method returns E_FAIL.

The callback based on [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) for the
**LoadAsync** method works as a script function that takes one parameter. This parameter is the result of the load operation. If the parameter is zero, the load succeeded, and the user can retrieve device objects from the document. If the parameter is non-zero, it describes the error. The value is the same as the error code that the [IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load) method returns.

In Visual Basic Scripting Edition (VBScript) development software, the second argument must be **GetRef**(*funcname*), where *funcname* is the name of the callback subroutine.

If this function returns S_OK,
[IUPnPDescriptionDocumentCallback::LoadComplete](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocumentcallback-loadcomplete) is invoked by the UPnP framework.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load)