# VideoPortCheckForDeviceExistence function

## Description

The **VideoPortCheckForDeviceExistence** function determines whether the specified PCI device exists in the system.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VendorId` [in]

Specifies the vendor ID.

### `DeviceId` [in]

Specifies the device ID.

### `RevisionId` [in]

Specifies the revision ID.

### `SubVendorId` [in]

Specifies the subvendor ID.

### `SubSystemId` [in]

Specifies the subsystem ID.

### `Flags` [in]

Is a set of flags that determine whether the *RevisionID* and *SubSystemID* parameters should be used in checking for the new device. This parameter can be the logical OR of the following values:

|Value|Meaning|
|--- |--- |
|CDE_USE_REVISION|Use the value in the RevisionID parameter in checking for the new device.|
|CDE_USE_SUBSYSTEM_IDS|Use the value in the SubSystemID parameter in checking for the new device.|

## Return value

**VideoPortCheckForDeviceExistence** returns **TRUE** if the device exists in the system, and **FALSE** otherwise.

## Remarks

For more information about PCI identifiers, see [Identifiers for PCI Devices](https://learn.microsoft.com/windows-hardware/drivers/install/identifiers-for-pci-devices).