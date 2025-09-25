# StorPortGetActiveGroupCount function

## Description

The **StorPortGetActiveGroupCount** routine returns the number of processor groups that are present in the system.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `NumberGroups` [out]

A pointer to a variable that holds the number of groups.

## Return value

The **StorPortGetActiveGroupCount** routine returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | The operation was successful. |