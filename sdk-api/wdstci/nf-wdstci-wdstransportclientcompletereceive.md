# WdsTransportClientCompleteReceive function

## Description

Indicates that all processing on a block of data is finished, and that the multicast client may purge this block of data from its cache to make room for further receives.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession).

### `ulSize` [in]

The size of the block being released.

### `pullOffset` [in]

The offset of the block being released.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

There must be one call to **WdsTransportClientCompleteReceive** for each call to the [PFN_WdsTransportClientReceiveContents](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientreceivecontents) callback that the consumer receives. The length and offset parameters of this function call must match those provided in the receive contents callback. Failure to call this function will result in a stall in the multicast client once it hits the cache limit specified by the *ulCacheSize* of the [WDS_TRANSPORTCLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/api/wdstci/ns-wdstci-wds_transportclient_request) structure passed to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession).