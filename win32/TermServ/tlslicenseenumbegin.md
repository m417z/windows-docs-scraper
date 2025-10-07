# TLSLicenseEnumBegin function

Begins enumeration of licenses that are issued by the Remote Desktop license server based on search criteria.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mstlsapi.dll.

## Parameters

*hHandle* \[in\]

Handle to a Remote Desktop license server. Specify a handle that is opened by the [**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver) function.

*dwSearchParm* \[in\]

Specifies the search criteria. The parameter can be one or a combination of the values that are described in the following list. The parameter specifies the type of key pack and which key pack to search.

**LSLICENSE\_SEARCH\_LICENSEID** (0x00000001)

Search by license ID.

**LSLICENSE\_SEARCH\_KEYPACKID** (0x00000002)

Search by key pack ID.

**LSLICENSE\_SEARCH\_MACHINENAME** (0x00000008)

Search by machine name.

**LSLICENSE\_SEARCH\_USERNAME** (0x00000010)

Search by user name.

**LSLICENSE\_SEARCH\_ISSUEDATE** (0x00000080)

Search by issue date.

**LSLICENSE\_SEARCH\_EXPIREDATE** (0x00000100)

Search by expiration date.

**LSLICENSE\_SEARCH\_ NUMLICENSES** (0x00000200)

Search by number of licenses.

**LSLICENSE\_SEARCH\_ ENTRY\_STATUS** (0x20000000)

Search by entry status.

**LSLICENSE\_EXSEARCH\_LICENSESTATUS** (0x00100000)

Search by license status.

**LSKEYPACK\_SEARCH\_ALL** (0xFFFFFFFF)

Search all licenses.

*bMatchAll* \[in\]

Specifies whether to match all search values.

*lpSearchParm* \[in\]

Pointer to a [**LSLicense**](https://learn.microsoft.com/windows/win32/termserv/lslicense) structure that specifies the search parameters to look for.

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

[**LSLicense**](https://learn.microsoft.com/windows/win32/termserv/lslicense)

[**TLSConnectToLsServer**](https://learn.microsoft.com/windows/win32/termserv/tlsconnecttolsserver)

[**TLSLicenseEnumNext**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumnext)

[**TLSLicenseEnumEnd**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumend)

