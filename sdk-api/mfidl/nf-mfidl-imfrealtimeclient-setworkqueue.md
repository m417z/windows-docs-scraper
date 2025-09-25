# IMFRealTimeClient::SetWorkQueue

## Description

Specifies the work queue for the topology branch that contains this object.

## Parameters

### `dwWorkQueueId` [in]

The identifier of the work queue, or the value **MFASYNC_CALLBACK_QUEUE_UNDEFINED**. See Remarks.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application can register a branch of the topology to use a private work queue. The Media Session notifies any pipeline object that supports [IMFRealTimeClient](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclient) by calling **SetWorkQueue** with the application's work queue identifier.

When the application unregisters the topology branch, the Media Session calls **SetWorkQueue** again with the value **MFASYNC_CALLBACK_QUEUE_UNDEFINED**.

## See also

[IMFRealTimeClient](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclient)

[IMFWorkQueueServices::BeginRegisterTopologyWorkQueuesWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginregistertopologyworkqueueswithmmcss)