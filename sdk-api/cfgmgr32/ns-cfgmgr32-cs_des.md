# CS_DES structure

## Description

The CS_DES structure is used for specifying a resource list that describes device class-specific resource usage for a device instance. For more information about resource lists, see [Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/kernel/hardware-resources).

## Members

### `CSD_SignatureLength`

The number of elements in the byte array specified by **CSD_Signature**.

### `CSD_LegacyDataOffset`

Offset, in bytes, from the beginning of the **CSD_Signature** array to the beginning of a block of data. For example, if the data block follows the signature array, and if the signature array length is 16 bytes, then the value for **CSD_LegacyDataOffset** should be 16.

### `CSD_LegacyDataSize`

Length, in bytes, of the data block whose offset is specified by **CSD_LegacyDataOffset**.

### `CSD_Flags`

*Not used.*

### `CSD_ClassGuid`

A globally unique identifier (GUID) identifying a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes). If both **CSD_SignatureLength** and **CSD_LegacyDataSize** are zero, the GUID is null.

### `CSD_Signature`

A byte array containing a class-specific signature.

## Remarks

The data block identified by **CSD_LegacyDataSize** and **CSD_LegacyDataOffset** can contain legacy, class-specific data, as stored in the **DeviceSpecificData** member of a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_cm_partial_resource_descriptor) structure, if the structure's **Type** member is **CmResourceTypeDeviceSpecific**.

The class-specific signature identified by **CSD_SignatureLength** and **CSD_Signature** can contain additional class-specific device identification information.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_cm_partial_resource_descriptor)

[CS_RESOURCE](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cs_resource)