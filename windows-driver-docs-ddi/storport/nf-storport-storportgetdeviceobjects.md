# StorPortGetDeviceObjects function

## Description

The **StorPortGetDeviceObjects** routine returns the device objects that are associated with the adapter device stack. The device objects that will be returned are the functional and physical device objects of the adapter and the device object to which the functional device object is attached.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `AdapterDeviceObject` [out]

A pointer to receive the functional device object (FDO) of the adapter.

### `PhysicalDeviceObject` [out]

A pointer to receive the physical device object (PDO).

### `LowerDeviceObject` [out]

A pointer to receive the device object of lower device to which the FDO is attached.

## Return value

**StorPortGetDeviceObjects** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the device objects were obtained successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The *HwDeviceExtension* was **NULL**. |