# TLSKeyPackEnumBegin function

Begins enumeration through all key packs that are installed on a Remote Desktop license server based on search criteria.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server. Specify a handle that is opened by the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

*dwSearchParm* \[in\]

Specifies the search criteria. This parameter is reserved for future use and must contain 0xFFFFFFFF.

*bMatchAll* \[in\]

Specifies whether to match all search values.

*lpSearchParm* \[in\]

Pointer to a [**LSKeyPack**](https://learn.microsoft.com/windows/win32/termserv/lskeypack) structure that specifies the search parameters to look for.

*pdwErrCode* \[out\]

Pointer to a variable that receives one of the following error codes on return.

**LSERVER\_S\_SUCCESS** (0)

Call is successful.

**LSERVER\_E\_INTERNAL\_ERROR** (5001)

Internal error in license server.

**LSERVER\_E\_INVALID\_SEQUENCE** (5006)

The calling sequence was not valid. Most likely, a previous enumeration has not ended.

**LSERVER\_E\_SERVER\_BUSY** (5007)

License server is too busy to process the request.

**LSERVER\_E\_OUTOFMEMORY** (5008)

Cannot process the request because of insufficient memory.

**LSERVER\_E\_INVALID\_DATA** (5009)

Data in the search parameter is not valid.

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

[**LSKeyPack**](https://learn.microsoft.com/windows/win32/termserv/lskeypack)

[**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver)

[**TLSKeyPackEnumNext**](https://learn.microsoft.com/windows/win32/termserv/tlskeypackenumnext)

[**TLSKeyPackEnumEnd**](https://learn.microsoft.com/windows/win32/termserv/tlskeypackenumend)

