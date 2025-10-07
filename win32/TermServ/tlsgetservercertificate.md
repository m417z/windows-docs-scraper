# TLSGetServerCertificate function

Returns the certificate of the Remote Desktop license server.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server that is opened by a call to the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

*bSignCert* \[in\]

**TRUE** if signature certificate, **FALSE** if exchange certificate.

*ppbCertBlob* \[out\]

Pointer to a variable that receives a pointer to a buffer that contains the certificate.

*lpdwCertBlobLen* \[out\]

Pointer to a variable that receives the size of the certificate that is returned.

*pdwErrCode* \[out\]

Pointer to a variable that receives the error code.

**LSERVER\_S\_SUCCESS** (0)

Call is successful.

**TLS\_W\_SELFSIGN\_CERTIFICATE** (4007)

Certificate returned is a self-signed certificate.

**TLS\_W\_TEMP\_SELFSIGN\_CERT** (4009)

Certificate returned is temporary.

**TLS\_E\_ACCESS\_DENIED** (5003)

Access denied.

**TLS\_E\_ALLOCATE\_HANDLE** (5007)

Server is too busy to process the request.

**TLS\_E\_NO\_CERTIFICATE** (5022)

Cannot retrieve a certificate.

## Return value

This function returns the following possible return values.

**RPC\_S\_OK**

The call succeeded. Check the value of the *pdwErrCode* parameter to get the return code for the call.

**RPC\_S\_INVALID\_ARG**

The argument was invalid.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| DLL<br> | Mstlsapi.dll |

## See also

[**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver)

