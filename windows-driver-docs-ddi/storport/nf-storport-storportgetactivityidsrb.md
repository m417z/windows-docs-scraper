# StorPortGetActivityIdSrb function

## Description

Retrieves the Event Tracing for Windows (ETW) activity ID associated with a request block.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Srb` [in]

The request block to retrieve the ETW activity ID for.

### `ActivityId` [out]

A pointer to a caller-supplied GUID to receive the ETW activity ID.

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The ETW activity ID was returned in *ActivityId*. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer in *ActivityId* or *Srb* is NULL. |
| **STOR_STATUS_UNSUCCESSFUL** | An ETW activity ID is not associated with the request in *Srb*. |