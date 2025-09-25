# WdsTransportClientQueryStatus function

## Description

Retrieves the current status of an ongoing or complete multicast transmission from the multicast client.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession).

### `puStatus` [out]

The current status of the transfer. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| WDS_TRANSPORTCLIENT_STATUS_IN_PROGRESS | The multicast session is still in progress. |
| WDS_TRANSPORTCLIENT_STATUS_SUCCESS | The multicast session completed successfully. |
| WDS_TRANSPORTCLIENT_STATUS_FAILURE | The multicast session failed. |

### `puErrorCode` [out]

If puStatus is set to **WDS_TRANSPORTCLIENT_STATUS_FAILURE**, this field will be set to the error code of the session.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

It is valid to call this function even after a transfer completes as long as the session key has not been closed.