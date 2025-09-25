# NetGetAnyDCName function

## Description

The
**NetGetAnyDCName** function returns the name of any domain controller (DC) for a domain that is directly trusted by the specified server.

Applications that support DNS-style names should call the
[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function. This function can locate any DC in any domain, whether or not the domain is directly trusted by the specified server.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used. For more information, see the following Remarks section.

### `domainname` [in]

Pointer to a constant string that specifies the name of the domain. If this parameter is **NULL**, the name of the domain controller for the primary domain is used. For more information, see the following Remarks section.

### `bufptr` [out]

Pointer to an allocated buffer that receives a string that specifies the server name of a domain controller for the domain. The server name is prefixed by \\. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_NO_LOGON_SERVERS** | No domain controllers could be found. |
| **ERROR_NO_SUCH_DOMAIN** | The specified domain is not a trusted domain. |
| **ERROR_NO_TRUST_LSA_SECRET** | The client side of the trust relationship is broken. |
| **ERROR_NO_TRUST_SAM_ACCOUNT** | The server side of the trust relationship is broken or the password is broken. |
| **ERROR_DOMAIN_TRUST_INCONSISTENT** | The server that responded is not a proper domain controller of the specified domain. |

## Remarks

No special group membership is required to successfully execute the
**NetGetAnyDCName** function.

If *servername* specifies a stand-alone workstation or a stand-alone server, no *domainname* is valid.

If *servername* specifies a workstation that is a member of a domain, or a server that is a member of a domain, the *domainname* must be in the same domain as *servername*.

If *servername* specifies a domain controller, the *domainname* must be one of the domains trusted by the domain for which the server is a controller. The domain controller that this call finds has been operational at least once during this call.

## See also

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[Get Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/get-functions)

[NetGetDCName](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgetdcname)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)