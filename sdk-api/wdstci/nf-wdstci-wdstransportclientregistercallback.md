# WdsTransportClientRegisterCallback function

## Description

Registers a callback with the multicast client.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession).

### `CallbackId` [in]

Identifier specifying which callback is being registered. This parameter receives a [TRANSPORTCLIENT_CALLBACK_ID](https://learn.microsoft.com/windows/desktop/api/wdstci/ne-wdstci-transportclient_callback_id) enumeration value.

| Value | Meaning |
| --- | --- |
| WDS_TRANSPORTCLIENT_SESSION_START | Identifies the [PFN_WdsTransportClientSessionStart](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessionstart) callback. This callback is required. |
| WDS_TRANSPORTCLIENT_RECEIVE_CONTENTS | Identifies the [PFN_WdsTransportClientReceiveContents](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientreceivecontents) callback. This callback is required. |
| WDS_TRANSPORTCLIENT_SESSION_COMPLETE | Identifies the [PFN_WdsTransportClientSessionComplete](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessioncomplete) callback. This callback is required. |
| WDS_TRANSPORTCLIENT_RECEIVE_METADATA | Identifies the [PFN_WdsTransportClientReceiveMetadata](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientreceivemetadata) callback. This callback is optional. |

### `pfnCallback` [in]

Pointer to the function pointer associated with this id.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

All callbacks must be registered with the client before the consumer calls [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession). Once the session is started, no further callbacks may be registered.