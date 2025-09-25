# IRDPSRAPIViewer::StartReverseConnectListener

## Description

[The [IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Initiates a listener for accepting reverse connections from the sharer to the viewer, or obtains the connection string that the sharer uses to reverse connect to the viewer.

## Parameters

### `bstrConnectionString` [in]

Type: **BSTR**

The connection string that the sharer will use to start the listener.

### `bstrUserName` [in]

Type: **BSTR**

The user name to use for authentication.

### `bstrPassword` [in]

Type: **BSTR**

The password to use for authentication.

### `pbstrReverseConnectString` [out]

Type: **BSTR***

A pointer to a **BSTR** that receives the connection string that the sharer can use to reverse connect to the viewer by using the [IRDPSRAPISharingSession::ConnectToClient](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapisharingsession-connecttoclient) method.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## Remarks

This method is used to perform two separate operations:

* The first is to allow the viewer to obtain the connection string that the sharer uses to reverse connect to the viewer. To do so, the *bstrConnectionString*, *bstrUserName*, and *bstrPassword* parameters must all be **NULL**. The viewer then sends this connection string to the sharer in an application-defined method, such as storing the connection string in a file and sharing the file with the sharer.
* The second operation is to initiate a listener that will watch for reverse connect attempts from the sharer. For this operation, the *pbstrReverseConnectString* parameter must be **NULL**.

The normal sequence of events for this procedure is as follows:

1. The viewer obtains its connection string by calling the **StartReverseConnectListener** method, passing **NULL** for the *bstrConnectionString*, *bstrUserName*, and *bstrPassword* parameters.
2. The viewer initiates a reverse connect listener by calling the **StartReverseConnectListener** method, passing **NULL** for the *pbstrReverseConnectString* parameter and valid values for the *bstrConnectionString*, *bstrUserName*, and *bstrPassword* parameters.
3. The viewer sends the connection string obtained in step 1 to the sharer.

## See also

[IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer)