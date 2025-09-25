# TRANSPORTCLIENT_CALLBACK_ID enumeration

## Description

This enumeration is received by the [WdsTransportClientRegisterCallback](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientregistercallback) function.

## Constants

### `WDS_TRANSPORTCLIENT_SESSION_START:0`

Identifies the [PFN_WdsTransportClientSessionStart](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessionstart) callback.

### `WDS_TRANSPORTCLIENT_RECEIVE_CONTENTS`

Identifies the [PFN_WdsTransportClientReceiveContents](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientreceivecontents) callback.

### `WDS_TRANSPORTCLIENT_SESSION_COMPLETE`

Identifies the [PFN_WdsTransportClientSessionComplete](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessioncomplete) callback.

### `WDS_TRANSPORTCLIENT_RECEIVE_METADATA`

Identifies the [PFN_WdsTransportClientReceiveMetadata](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientreceivemetadata) callback.

### `WDS_TRANSPORTCLIENT_SESSION_STARTEX`

Identifies the [PFN_WdsTransportClientSessionStartEx](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessionstartex) callback.

### `WDS_TRANSPORTCLIENT_SESSION_NEGOTIATE`

### `WDS_TRANSPORTCLIENT_MAX_CALLBACKS`

Used for validation checking.