# IWbemEventSink::SetBatchingParameters

## Description

The
**IWbemEventSink::SetBatchingParameters** method is used to set the maximum event buffer size and its associated processing latency value.

## Parameters

### `lFlags` [in]

Determines batching behavior.

#### WBEM_FLAG_BATCH_IF_NEEDED (0)

System determines if batching is used.

#### WBEM_FLAG_MUST_BATCH (0x1)

Batching required.

#### WBEM_FLAG_MUST_NOT_BATCH (0x2)

Do not batch.

### `dwMaxBufferSize` [in]

Maximum batch buffer size. To specify maximum batch size, use MAX_INT.

### `dwMaxSendLatency` [in]

Maximum batch send latency. To specify infinite timeout, use **WBEM_INFINITE**.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.