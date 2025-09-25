# lineProxyResponse function

## Description

The
**lineProxyResponse** function indicates completion of a proxy request by a registered proxy handler, such as an ACD agent handler on a server.

## Parameters

### `hLine`

A handle to the open line device.

### `lpProxyRequest`

A pointer to the proxy request buffer given to the application by TAPI in a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message. In the case of proxy requests that return data to the client application, the proxy handler should have filled in the necessary structure in this buffer before calling this function. The **dwNeededSize** and **dwUsedSize** members of the structure to be returned must have been set appropriately.

**Note** If the size parameters in the structure are incorrect, it is possible that data could be overwritten. For more information about setting structure sizes, see
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation).

### `dwResult`

A function result returned to the calling application in a
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message (generated automatically by TAPI). Must be zero or one of the negative error values defined for the called function.

## Return value

Returns zero if the function succeeds or one of these negative error values:

**LINEERR_INVALLINEHANDLE**, **LINEERR_INVALPARAM**, **LINEERR_INVALPOINTER**, **LINEERR_NOMEM**, **LINEERR_NOTREGISTERED**, **LINEERR_OPERATIONFAILED**, **LINE ERR_OPERATIONUNAVAIL**, **LINEERR_RESOURCEUNAVAIL**, **LINEERR_UNINITIALIZED**.

## See also

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)