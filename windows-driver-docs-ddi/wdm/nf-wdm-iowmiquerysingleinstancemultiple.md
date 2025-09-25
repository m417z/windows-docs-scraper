# IoWMIQuerySingleInstanceMultiple function

## Description

The **IoWMIQuerySingleInstanceMultiple** routine returns all WMI data block instances that implement the specified WMI classes with the specified instance names.

## Parameters

### `DataBlockObjectList` [in]

Pointer to an array of pointers of WMI data block objects. The caller opens a data block object for each WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. Each object must be opened with the WMIGUID_QUERY access right.

### `InstanceNames` [in]

Pointer to an array of [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structures containing instance names. The *n*th instance name in the array corresponds to the value of the **InstanceName** property for the *n*th WMI class specified in the array pointed to by the *DataBlockObjectList* parameter.

### `ObjectCount` [in]

Specifies the number of entries in the arrays passed in the *DataBlockObjectList* and *InstanceNames* parameters.

### `InOutBufferSize` [in, out]

Pointer to a memory location that specifies the size of the buffer passed in the *OutBuffer* parameter. If the routine succeeds, it updates the memory location to specify the number of bytes actually stored in *OutBuffer*. If the routine fails with STATUS_BUFFER_TOO_SMALL, it returns the number of bytes required to return the data.

### `OutBuffer` [out, optional]

Pointer to the buffer where the routine returns the WMI data. The routine returns a sequence of variable-sized [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structures, one for each data block instance. The **WnodeHeader.Linkage** member of each **WNODE_SINGLE_INSTANCE** structure contains the offset from the beginning of the current **WNODE_SINGLE_INSTANCE** to the beginning of the next **WNODE_SINGLE_INSTANCE**. The final block in the chain has **WnodeHeader.Linkage** set to zero. Each distinct data block instance corresponds to a single matching WMI class and instance name. *OutBuffer* must point to a buffer allocated from nonpaged pool.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine returns the WMI data in the buffer pointed to by the *OutBuffer* parameter. The routine also returns the size, in bytes, of the returned data in the memory location pointed to by the *InOutBufferSize* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer passed by the caller in the *OutBuffer* parameter is too small. The routine returns the required buffer size in the memory location pointed to by the *InOutBufferSize* parameter. |

## Remarks

**IoWMIQuerySingleInstanceMultiple** determines which drivers might support the specified WMI classes and instance names, and issues an [IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance) request to each such driver. Each driver that exports the data block instance with matching **InstanceName** property returns the appropriate data.

If no drivers implement any of the specified WMI classes and instance names, the routine returns STATUS_SUCCESS. It also returns a value of zero in the memory location pointed to by the *InOutBufferSize* parameter.

To query for a single WMI class and instance name, use the [IoWMIQuerySingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstance) routine. Drivers can use the [IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance) routine to update a class instance.

## See also

[IRP_MN_QUERY_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-single-instance)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQuerySingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiquerysingleinstance)

[IoWMISetSingleInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmisetsingleinstance)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)