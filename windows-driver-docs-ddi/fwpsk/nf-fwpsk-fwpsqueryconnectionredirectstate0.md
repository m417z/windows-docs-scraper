# FwpsQueryConnectionRedirectState0 function

## Description

The **FwpsQueryConnectionRedirectState0** function returns the connection redirect state.

**Note** **FwpsQueryConnectionRedirectState0** is a specific version of **FwpsQueryConnectionRedirectState**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `redirectRecords`

The redirect records handle indicated to ALE_CONNECT_REDIRECT callout by the classify metadata.

### `redirectHandle`

A redirect handle that was previously created by a call to the
[FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0) function.

### `redirectContext`

An optional handle to the redirect context. If the pointer is specified, and if the connection
redirect state
[FWPS_CONNECTION_REDIRECT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_connection_redirect_state_) associated with the injection handle is FWPS_CONNECTION_REDIRECTED_BY_SELF
or FWPS_CONNECTION_PREVIOUSLY_REDIRECTED_BY_SELF, the redirect context supplied when the connection was redirected
will be returned.

## Return value

The
**FwpsQueryConnectionRedirectState0** function returns one of the states that are specified in the [FWPS_CONNECTION_REDIRECT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_connection_redirect_state_) enumeration.

## Remarks

A callout driver calls the **FwpsQueryConnectionRedirectState0** function to get the redirect state of a connection.

If the redirect status is FWPS_CONNECTION_NOT_REDIRECTED, the ALE_CONNECT_REDIRECT callout can proceed to proxy the connection.

If the redirect status is FWPS_CONNECTION_REDIRECTED_BY_SELF, the ALE_CONNECT_REDIRECT callout should return FWP_ACTION_PERMIT/FWP_ACTION_CONTINUE.

If the redirect status is FWPS_CONNECTION_REDIRECTED_BY_OTHER, the ALE_CONNECT_REDIRECT callout could proceed to proxy the connection if it does not trust the other inspector's result.

If the redirect status is FWPS_CONNECTION_PREVIOUSLY_REDIRECTED_BY_SELF, the ALE_CONNECT_REDIRECT callout must not perform redirection even if other inspectors' results are not acceptable. In this case, it must either permit or block the connection (at the ALE_AUTH_CONNECT layer).

## See also

[FWPS_CONNECTION_REDIRECT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_connection_redirect_state_)

[FwpsRedirectHandleCreate0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsredirecthandlecreate0)