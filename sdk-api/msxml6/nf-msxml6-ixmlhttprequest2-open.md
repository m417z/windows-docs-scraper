# IXMLHTTPRequest2::Open

## Description

Initializes an [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) request and specifies the method, URL, and authentication information for the request. After calling this method, you must call the [Send](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-send) method to send the request and data, if any, to the server.

## Parameters

### `pwszMethod` [in]

The HTTP method used to open the connection, such as **GET** or **POST**. For XMLHTTP, this parameter is not case-sensitive.

### `pwszUrl` [in]

The requested URL. This must be an absolute URL, such as "http://Myserver/Mypath/Myfile.asp".

### `pStatusCallback` [in, optional]

A callback interface implemented by the app that is to receive callback events.

When the [Send Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-send) is successful, the methods on this interface are called to process the response or other events.

### `pwszUserName` [in, optional]

The name of the user for authentication. If this parameter is a Null and the site requires authentication, credentials will be managed by Windows, including displaying a logon UI, unless disabled by [SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty).

### `pwszPassword` [in, optional]

The password for authentication. This parameter is ignored if the *pwszUserName* parameter is Null or missing.

### `pwszProxyUserName` [in, optional]

The name of the user for authentication on the proxy server. If this parameter is a Null or empty string and the site requires authentication, credentials will be managed by Windows, including displaying a logon UI, unless disabled by [SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty).

### `pwszProxyPassword` [in, optional]

The password for authentication on the proxy server. This parameter is ignored if the *pwszProxyUserName* parameter is Null or missing.

## Return value

Returns **S_OK** on success.

## Remarks

Although this method accepts credentials passed via parameter, these credentials are not automatically sent to the server on the first request. The *pwszUserName* and *pwszPassword* parameters are not sent to the server unless the server challenges the client for credentials with a 401 - Unauthorized response.

#### Examples

``` syntax
//
// Create and initialize an IXMLHTTPRequest2 object
//
hr = CoCreateInstance(CLSID_FreeThreadedXMLHTTP60,
                      NULL,
                      CLSCTX_INPROC_SERVER,
                      IID_PPV_ARGS(&spXHR));

//
//Create and initialize an IXMLHTTPRequest2Callback object
//
hr = MakeAndInitialize<CXMLHttpRequest2Callback>(&spXhrCallback);

hr = spXHR->Open(L"GET",              // Method.
                 pcwszUrl,            // Url.
                 spXhrCallback.Get(), // Callback.
                 NULL,                // Username.
                 NULL,                // Password.
                 NULL,                // Proxy username.
                 NULL);               // Proxy password.

//
//Send the GET request
//
hr = spXHR->Send(NULL, 0);

hr = spXhrCallback->WaitForComplete(&dwStatus);
```

For the complete examples, see the [XML HTTP Request 2 GET sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/XmlHttpRequest2GetRequest) and [XML HTTP Request 2 POST sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/XmlHttpRequest2PostRequest).

## See also

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[IXMLHTTPRequest2Callback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)

[Send Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-send)