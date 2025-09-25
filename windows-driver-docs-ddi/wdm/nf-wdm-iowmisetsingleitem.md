# IoWMISetSingleItem function

## Description

The **IoWMISetSingleItem** routine sets a single property in the data block instance that matches the specified WMI class and instance name.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. The object must be opened with the WMIGUID_SET access right.

### `InstanceName` [in]

Specifies the name of the instance of the data block. This value corresponds to the value of the **InstanceName** property for the block.

### `DataItemId` [in]

Specifies the data item ID for the property to be set. The value of this parameter corresponds to the value declared in the **WmiDataId** qualifier for the property.

### `Version` [in]

Reserved for future use. Callers must set this parameter to zero.

### `ValueBufferSize` [in]

Specifies the size, in bytes, of the buffer passed in the *ValueBuffer* parameter.

### `ValueBuffer` [in]

Pointer to the buffer that contains the new value for the property specified by the *DataItemId* parameter.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The value of the property within WMI data block instance is updated to the contents of the buffer pointed to by the *ValueBuffer* parameter. |
| **STATUS_WMI_GUID_NOT_FOUND** | No drivers implement the WMI class. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | No driver implements an instance of the WMI data block with **InstanceName** property equal to the value specified in the *InstanceName* parameter. |
| **STATUS_WMI_ITEMID_NOT_FOUND** | The WMI class does not contain a property with data item ID equal to the value of *DataItemId*. |
| **STATUS_WMI_READ_ONLY** | The data item ID in the data block is read-only. |
| **STATUS_WMI_SET_FAILURE** | The driver that implements the WMI data block instance is unable to update the property specified by *DataItemId*. |

## Remarks

**IoWMISetSingleItem** determines which drivers might support the specified WMI class and instance name. It issues an [IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item) request to each such driver. The driver that exports the data block instance with matching **InstanceName** property updates the specified property in the data block instance.

Drivers can also use [IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance) to update every property of the WMI class instance simultaneously.

## See also

[IRP_MN_CHANGE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-item)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQuerySingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstance)

[IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance)