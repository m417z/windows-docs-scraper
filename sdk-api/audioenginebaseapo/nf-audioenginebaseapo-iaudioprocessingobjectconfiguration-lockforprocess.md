# IAudioProcessingObjectConfiguration::LockForProcess

## Description

The `LockForProcess` method is used to verify that the APO is locked and ready to process data.

## Parameters

### `u32NumInputConnections` [in]

Number of input connections that are attached to this APO.

### `ppInputConnections` [in]

Connection descriptor for each input connection that is attached to this APO.

### `u32NumOutputConnections` [in]

Number of output connections that are attached to this APO.

### `ppOutputConnections` [in]

Connection descriptor for each output connection that is attached to this APO.

## Return value

The `LockForProcess` method returns a value of S_OK if the call is completed successfully. At this stage, the APO is locked and is ready to process data.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Invalid pointer was passed to function. |
| **APOERR_INVALID_CONNECITON_FORMAT** | Invalid connection format. |
| **APOERR_NUM_CONNECTIONS_INVALID** | Number of input or output connections not valid on this APO. |
| **APOERR_APO_LOCKED** | APO is already locked. |
| **Other HRESULTS** | These failures will be tracked by the audio engine. |

## Remarks

When the `LockForProcess` method is called, it first performs an internal check to see if the APO has been initialized and is ready to process data. Each APO has different initialization requirements so each APO must define its own Initialize method if needed.