# PxeGetServerInfoEx function

## Description

Returns information about the PXE server.

For more information about the OPTION_SERVERID option, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Parameters

### `uInfoType` [in]

Selects the information that will be returned.

| Value | Meaning |
| --- | --- |
| **PXE_GSI_TRACE_ENABLED**<br><br>1 | Returns a **BOOL** that indicates whether tracing is enabled for the server. **TRUE** indicates that tracing is enabled. |
| **PXE_GSI_SERVER_DUID**<br><br>2 | Returns a byte array that corresponds to the DHCPv6 DUID that is sent to DHCPv6 PXE clients in response packets in the OPTION_SERVERID option. **PXE_GSI_SERVER_DUID** cannot be used with [PxeGetServerInfo](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxegetserverinfo). |

### `pBuffer` [out]

Address of a buffer that will receive the results of the query. The size and format of the results depends
on the value of the *uInfoType* parameter.

### `uBufferLen` [in]

Size of buffer pointed to by the *pBuffer* parameter.

### `puBufferUsed` [out]

Size of buffer pointed to by the *pBuffer* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)