# TLSLicenseEnumEnd function

Continues from a previous call to the [**TLSLicenseEnumBegin**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumbegin) function and terminates the enumeration.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server. Specify a handle that is opened by the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

*pdwErrCode* \[out\]

Pointer to a variable that receives one of the following error codes on return.

**LSERVER\_S\_SUCCESS** (0)

Call is successful.

**LSERVER\_E\_INVALID\_HANDLE** (5005)

The handle is not valid.

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

[**TLSLicenseEnumNext**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumnext)

