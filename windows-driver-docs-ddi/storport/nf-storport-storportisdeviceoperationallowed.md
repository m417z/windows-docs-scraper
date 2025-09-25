# StorPortIsDeviceOperationAllowed function

## Description

A miniport driver can call the **StorPortIsDeviceOperationAllowedminiport** routine to determine if operations for a certain device management class are allowed. A status value is set in the return parameter to indicate whether such operations are allowed or not allowed for the device in its current operating environment.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in]

The address of a storage device unit.

### `DeviceOperation` [in]

A pointer to a GUID specifying a device management operation class. The following GUID is valid.

| Value | Meaning |
| --- | --- |
| **STORPORT_DEVICEOPERATION_SECURE_REPROVISION_GUID** | The device is enabled to receive secured provisioning commands. |

### `AllowedFlag` [out]

 TRUE when the operation specified in *DeviceOperation* is allowed. Otherwise, FALSE.

## Return value

The **StorPortIsDeviceOperationAllowed** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | A valid value for *AllowedFlag* was returned. |
| **STOR_STATUS_INVALID_PARAMETER** | *Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found.<br><br>-or-<br><br>The pointer value in *AllowedFlag* is NULL. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > PASSIVE_LEVEL. |
| **STOR_STATUS_NOT_IMPLEMENTED** | The management class specified in *DeviceOperation* is not available or invalid. |