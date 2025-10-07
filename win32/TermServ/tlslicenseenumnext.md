# TLSLicenseEnumNext function

Continues from a previous call to the [**TLSLicenseEnumBegin**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumbegin) function and returns the next license that is installed on a Remote Desktop license server that matches the search criteria.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server. Specify a handle that is opened by the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

*lpLicense* \[in\]

Pointer to a [**LSLicense**](https://learn.microsoft.com/windows/win32/termserv/lslicense) structure that receives the next license that matches the search criteria.

*pdwErrCode* \[out\]

Pointer to a variable that receives one of the following error codes on return.

**LSERVER\_S\_SUCCESS** (0)

Call is successful.

**LSERVER\_I\_NO\_MORE\_DATA** (4001)

No more licenses match the search criteria.

**LSERVER\_E\_INTERNAL\_ERROR** (5001)

Internal error in license server.

**LSERVER\_E\_INVALID\_SEQUENCE** (5006)

The calling sequence was not valid. Must call the [**TLSLicenseEnumBegin()**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumbegin) function before this.

**LSERVER\_E\_SERVER\_BUSY** (5007)

License server is too busy to process the request.

**LSERVER\_E\_OUTOFMEMORY** (5008)

Cannot process the request because of insufficient memory.

## Return value

This function returns the following possible return values.

**RPC\_S\_OK**

The call succeeded. Check the value of the *pdwErrCode* parameter to get the return code for the call.

**RPC\_S\_INVALID\_ARG**

The argument was not valid.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| DLL<br> | Mstlsapi.dll |

## See also

[**LSLicense**](https://learn.microsoft.com/windows/win32/termserv/lslicense)

[**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver)

[**TLSLicenseEnumBegin**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumbegin)

[**TLSLicenseEnumEnd**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumend)

