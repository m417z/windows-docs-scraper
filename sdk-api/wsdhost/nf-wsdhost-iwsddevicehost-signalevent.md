# IWSDDeviceHost::SignalEvent

## Description

Notifies all subscribed clients that an event has occurred.

## Parameters

### `pszServiceId` [in]

The ID of the service that generates the event.

### `pBody` [in]

The body of the event.

### `pOperation` [in]

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_FAIL** | The host is not started. Call [Start](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-start) to start the device host. |
| **E_INVALIDARG** | *pszServiceId* is **NULL**, *pOperation* is **NULL**, the length in characters of *pszServiceId* exceeds WSD_MAX_TEXT_LENGTH (8192), there is no *ResponseType* structure associated with *pOperation*, or the service specified by *pszServiceId* is not subscribed to the event specified by the *ResponseType* member of *pOperation*. |

## Remarks

**SignalEvent** blocks until the event is sent to all clients. Since clients are contacted sequentially, it is possible that **SignalEvent** will block for a long time if any client responds slowly or is unreachable.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)