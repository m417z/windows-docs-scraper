## Description

The IoGetActivityIdIrp routine retrieves the current activity ID associated with an IRP.

## Parameters

### `Irp` [in]

The IRP from which to retrieve the activity ID.

### `Guid` [out]

A pointer to a location to store the retrieved GUID.

## Return value

IoGetActivityIdIrp returns **STATUS_SUCCESS** if the call is successful. Possible error return values include the following.

| Return code | Description |
|--|--|
| **STATUS_NOT_FOUND** | No activity ID is associated with the request. |