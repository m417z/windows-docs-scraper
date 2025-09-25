# StorPortGetActiveNodeCount function

## Description

The **StorPortGetActiveNodeCount** routine returns the number of nodes that are present in the system.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `NumberNodes` [out]

A pointer to a variable that holds the number of nodes.

## Return value

The **StorPortGetActiveNodeCount**routine returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |
| **STOR_STATUS_INVALID_PARAMETER** | The operation fails with this return value if one or more of the parameters are invalid, for example, if *NumberNodes* is set to **NULL**. |