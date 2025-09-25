# HttpReceiveClientCertificate function

## Description

The
**HttpReceiveClientCertificate** function is used by a server application to retrieve a client SSL certificate or channel binding token (CBT).

## Parameters

### `RequestQueueHandle` [in]

A handle to the request queue with which the specified SSL client or CBT is associated. A request queue is created and its handle returned by a call to the
[HttpCreateRequestQueue](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreaterequestqueue) function.

**Windows Server 2003 with SP1 and Windows XP with SP2:** The handle to the request queue is created by the [HttpCreateHttpHandle](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpcreatehttphandle) function.

### `ConnectionId` [in]

A value that identifies the connection to the client. This value is obtained from the **ConnectionId** element of an
[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure filled in by the
[HttpReceiveHttpRequest](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpreceivehttprequest) function.

### `Flags` [in]

A value that modifies the behavior of the **HttpReceiveClientCertificate** function

| Value | Meaning |
| --- | --- |
| **HTTP_RECEIVE_SECURE_CHANNEL_TOKEN**<br><br>0x1 | The *pSslClientCertInfo* parameter will be populated with CBT data.<br><br>This value is supported on Windows 7, Windows Server 2008 R2, and later. |

### `SslClientCertInfo` [out]

If the *Flags* parameter is 0, then this parameter points to an
[HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info) structure into which the function writes the requested client certificate information. The buffer pointed to by the *pSslClientCertInfo* should be sufficiently large enough to hold the **HTTP_SSL_CLIENT_CERT_INFO** structure plus the value of the **CertEncodedSize** member of this structure.

If the *Flags* parameter is **HTTP_RECEIVE_SECURE_CHANNEL_TOKEN**, then this parameter points to an
[HTTP_REQUEST_CHANNEL_BIND_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_channel_bind_status) structure into which the function writes the requested CBT information. The buffer pointed to by the *pSslClientCertInfo* should be sufficiently large enough to hold the **HTTP_REQUEST_CHANNEL_BIND_STATUS** structure plus the value of the **ChannelTokenSize** member of this structure.

### `SslClientCertInfoSize` [in]

The size, in bytes, of the buffer pointed to by the *pSslClientCertInfo* parameter.

### `BytesReceived` [out, optional]

An optional pointer to a variable that receives the number of bytes to be written to the structure pointed to by *pSslClientCertInfo*. If not used, set it to **NULL**.

When making an asynchronous call using *pOverlapped*, set *pBytesReceived* to **NULL**. Otherwise, when *pOverlapped* is set to **NULL**, *pBytesReceived* must contain a valid memory address, and not be set to **NULL**.

### `Overlapped` [in, optional]

For asynchronous calls, set *pOverlapped* to point to an
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure, or for synchronous calls, set it to **NULL**.

A synchronous call blocks until the client certificate is retrieved, whereas an asynchronous call immediately returns **ERROR_IO_PENDING** and the calling application then uses
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) or I/O completion ports to determine when the operation is completed. For more information about using
[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structures for synchronization, see the section
[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output).

## Return value

| Value | Meaning |
| --- | --- |
| **NO_ERROR** | The function succeeded. <br><br>All the data has been written into the buffer pointed to by the *pSslClientCertInfo* parameter. The *NumberOfBytesTransferred* indicates how many bytes were written into the buffer. |
| **ERROR_IO_PENDING** | The function is being used asynchronously. The operation has been initiated and will complete later through normal overlapped I/O completion mechanisms. |
| **ERROR_INVALID_PARAMETER** | One or more of the supplied parameters is not valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pSslClientCertInfo* parameter is too small to receive the data and no data was written. |
| **ERROR_MORE_DATA** | The buffer pointed to by the *pSslClientCertInfo* parameter is not large enough to receive all the data. Only the basic structure has been written and only partially populated.<br><br>When the *Flags* parameter is 0, the [HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info) structure has been written with the **CertEncodedSize** member populated. The caller should call the function again with a buffer that is at least the size, in bytes, of the **HTTP_SSL_CLIENT_CERT_INFO** structure plus the value of the **CertEncodedSize** member.<br><br>When the *Flags* parameter is **HTTP_RECEIVE_SECURE_CHANNEL_TOKEN**, the [HTTP_REQUEST_CHANNEL_BIND_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_channel_bind_status) structure has been written with the **ChannelTokenSize** member populated. The caller should call the function again with a buffer that is at least the size, in bytes, of the **HTTP_REQUEST_CHANNEL_BIND_STATUS** plus the value of the **ChannelTokenSize** member. |
| **ERROR_NOT_FOUND** | The function cannot find the client certificate or CBT. |
| **Other** | A [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) defined in the *WinError.h* header file. |

## Remarks

The behavior of the **HttpReceiveClientCertificate** function varies based on whether a client SSL certificate or a channel binding token is requested.

In the case of a synchronous call to the **HttpReceiveClientCertificate** function , the number of bytes received is returned in the value pointed to by the *pBytesReceived* parameter.

In the case of an asynchronous call to the **HttpReceiveClientCertificate** function, the number of bytes received is returned by the standard mechanisms used for asynchronous calls. The *lpNumberOfBytesTransferred* parameter returned by the
[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function contains the number of bytes received.

## See also

[GetOverlappedResult](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult)

[HTTP Server API Version 1.0 Functions](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-functions)

[HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85))

[HTTP_REQUEST_CHANNEL_BIND_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_channel_bind_status)

[HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[Synchronization and Overlapped Input and Output](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output)