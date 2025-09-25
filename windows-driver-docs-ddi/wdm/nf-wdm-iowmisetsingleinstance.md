# IoWMISetSingleInstance function

## Description

The **IoWMISetSingleInstance** routine sets the values for properties within the data block instance that matches the specified WMI class and instance name.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. The object must be opened with the WMIGUID_SET access right.

### `InstanceName` [in]

Specifies the name of the instance of the data block. This value corresponds to the value of the **InstanceName** property for the block.

### `Version` [in]

Reserved for future use. Callers must set this parameter to zero.

### `ValueBufferSize` [in]

Specifies the size, in bytes, of the buffer passed in the *ValueBuffer* parameter.

### `ValueBuffer` [in]

Pointer to the buffer that contains the new values for the properties within the data block.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The values of the WMI data block instance properties are updated to the contents of the buffer pointed to by the *ValueBuffer* parameter. |
| **STATUS_WMI_GUID_NOT_FOUND** | No drivers implement the WMI class. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | No driver implements an instance of the WMI class with **InstanceName** property equal to the value specified in the *InstanceName* parameter. |
| **STATUS_WMI_READ_ONLY** | All properties of the WMI class are read-only. |
| **STATUS_WMI_SET_FAILURE** | The driver that implements the WMI data block instance is unable to update the instance. |

## Remarks

**IoWMISetSingleInstance** determines which drivers might support the specified WMI class and instance name, and issues an [IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance) request to each such driver. The driver that exports the data block instance with matching **InstanceName** property updates its data block instance. Note that a data block might have both read-only and read/write properties. In this case, only the read/write properties will be updated and STATUS_SUCCESS is returned.

Drivers can also use the [IoWMISetSingleItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleitem) routine to update a single property within the class instance.

## See also

[IRP_MN_CHANGE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-change-single-instance)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQuerySingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstance)

[IoWMISetSingleItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleitem)