# FwpsQueryConnectionSioFormatRedirectRecords0 function

## Description

The **FwpsQueryConnectionSioFormatRedirectRecords0** function returns the connection redirect records for a redirected connection. For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

**Note** **FwpsQueryConnectionSioFormatRedirectRecords0** is a specific version of **FwpsQueryConnectionSioFormatRedirectRecords**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `RedirectRecords` [in]

The redirect records handle that the ALE_CONNECT_REDIRECT callout function received in the *inMetaValues* parameter of its [classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function. This handle can be found in the **redirectRecords** member of the [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure.

A WFP redirect record is a buffer of opaque data that WFP must set on an outbound proxy connection so that the redirected connection and the original connection are logically related.

### `OutputBuffer` [out, optional]

A pointer to an output buffer that receives the redirect records. The buffer must be pointer-aligned.

### `OutputBufferLength` [in]

The size, in bytes, of the output buffer.

### `BytesTransferred` [out, optional]

A pointer to a variable that receives the number of bytes that were transferred. If the return value is **STATUS_BUFFER_TOO_SMALL**, this parameter receives the required buffer size.

## Return value

Returns an NTSTATUS value such as one of the following.

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The output buffer was too small to contain all of the bytes to be transferred. The data transfer failed, and the required buffer size can be found in the *BytesTransferred* parameter. |
| **STATUS_NOT_FOUND** | The *RedirectRecords* parameter was null. |

## Remarks

The **FwpsQueryConnectionSioFormatRedirectRecords0** function applies only to local proxies.

For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

The **FwpsQueryConnectionSioFormatRedirectRecords0** function is designed to be used by a WFP connection redirection callout driver that doesn't accept the redirected connection until it has verified that it is able to connect to the actual remote endpoint. To do this, the callout driver pends the redirected connection request at the **FWPS_LAYER_ALE_CONNECT_REDIRECT_V4** or **FWPS_LAYER_ALE_CONNECT_REDIRECT_V6** layer and calls **FwpsQueryConnectionSioFormatRedirectRecords0** to retrieve the connection redirect records, which the callout driver then sends to the proxy to be used in a call to [SIO_SET_WFP_CONNECTION_REDIRECT_RECORDS](https://learn.microsoft.com/windows-hardware/drivers/network/sio-query-wfp-connection-redirect-records).

## See also

[SIO_QUERY_WFP_CONNECTION_REDIRECT_RECORDS (SDK)](https://learn.microsoft.com/windows/win32/winsock/sio-query-wfp-connection-redirect-records)

[SIO_QUERY_WFP_CONNECTION_REDIRECT_RECORDS (WDK)](https://learn.microsoft.com/windows-hardware/drivers/network/sio-query-wfp-connection-redirect-records)

[SIO_SET_WFP_CONNECTION_REDIRECT_RECORDS (SDK)](https://learn.microsoft.com/windows/win32/winsock/sio-query-wfp-connection-redirect-records)

[SIO_SET_WFP_CONNECTION_REDIRECT_RECORDS (WDK)](https://learn.microsoft.com/windows-hardware/drivers/network/sio-query-wfp-connection-redirect-records)

[Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)