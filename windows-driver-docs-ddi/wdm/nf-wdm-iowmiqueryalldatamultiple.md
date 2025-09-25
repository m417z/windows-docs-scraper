# IoWMIQueryAllDataMultiple function

## Description

The **IoWMIQueryAllDataMultiple** routine returns all WMI data blocks that implement one of a set of WMI classes.

## Parameters

### `DataBlockObjectList` [in]

Pointer to an array of pointers to WMI data block objects. The caller opens a data block object for each WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. Each object must be opened with the WMIGUID_QUERY access right.

### `ObjectCount` [in]

Specifies the number of entries in the array passed in the *DataBlockObjectList* parameter.

### `InOutBufferSize` [in, out]

Pointer to a memory location that specifies the size of the buffer passed in the *OutBuffer* parameter. If the routine succeeds, it updates the memory location to specify the number of bytes actually stored in *OutBuffer*. If the routine fails with status code of STATUS_BUFFER_TOO_SMALL, it returns the number of bytes required to return the data.

### `OutBuffer` [out, optional]

Pointer to the buffer where the routine returns the WMI data. The routine returns a sequence of variable-sized [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structures, one for each set of returned data blocks. The **WnodeHeader.Linkage** member of each **WNODE_ALL_DATA** structure contains the offset from the beginning of the current **WNODE_ALL_DATA** to the beginning of the next **WNODE_ALL_DATA**. The final block in the chain has **WnodeHeader.Linkage** set to zero. *OutBuffer* must point to a buffer allocated from nonpaged pool.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine returns the WMI data in the buffer pointed to by the *OutBuffer* parameter. The routine also returns the size, in bytes, of the returned data in the memory location pointed to by the *InOutBufferSize* parameter. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer passed by the caller in the *OutBuffer* parameter is too small. The routine returns the required buffer size in the memory location pointed to by the *InOutBufferSize* parameter. |

## Remarks

**IoWMIQueryAllDataMultiple** determines which drivers support the specified WMI classes, and issues an [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request to every such driver.

If no drivers implement any of the specified WMI classes, the routine returns STATUS_SUCCESS It also returns a value of zero in the memory location pointed to by the *InOutBufferSize* parameter.

To query a single WMI class, use [IoWMIQueryAllData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldata).

## See also

[IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQueryAllData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldata)