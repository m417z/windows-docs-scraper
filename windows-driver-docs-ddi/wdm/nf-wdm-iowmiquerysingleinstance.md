# IoWMIQuerySingleInstance function

## Description

The **IoWMIQuerySingleInstance** routine returns the specified instance of a WMI data block.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. The object must be opened with the WMIGUID_QUERY access right.

### `InstanceName` [in]

Specifies the name of the instance of the data block. This value corresponds to the value of the **InstanceName** property for the block.

### `InOutBufferSize` [in, out]

Pointer to a memory location that specifies the size of the buffer passed in the *OutBuffer* parameter. If the routine succeeds, it updates the memory location to specify the number of bytes actually stored in *OutBuffer*. If the routine fails with status code of STATUS_BUFFER_TOO_SMALL, it returns the number of bytes required to return the data.

### `OutBuffer` [out, optional]

Pointer to the buffer where the routine returns the WMI data. The routine returns a variable-sized [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structure. *OutBuffer* must point to a buffer allocated from nonpaged pool.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine returns the WMI data in the buffer pointed to by the *OutBuffer* parameter. The routine also returns the size, in bytes, of the returned data in the memory location pointed to by the *InOutBufferSize* parameter. |
| **STATUS_WMI_GUID_NOT_FOUND** | No drivers implement the specified WMI class. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | No driver implements an instance of the WMI class with **InstanceName** property equal to the value specified in the *InstanceName* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer passed by the caller in the *OutBuffer* parameter is too small. The routine returns the required buffer size in the memory location pointed to by the *InOutBufferSize* parameter. |

## Remarks

**IoWMIQuerySingleInstance** determines which drivers might support the specified WMI class with the specified instance name, and issues an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) request to each such driver. The driver that exports the data block instance with matching **InstanceName** property returns the appropriate data.

To query for multiple WMI classes and instance names, use the [IoWMIQuerySingleInstanceMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstancemultiple) routine. Drivers can use the [IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance) routine to update the class instance.

## See also

[IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQuerySingleInstanceMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstancemultiple)

[IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance)