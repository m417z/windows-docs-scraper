# IoWMIQueryAllData function

## Description

The **IoWMIQueryAllData** routine returns all WMI data blocks that implement a given WMI class.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. The object must be opened with the WMIGUID_QUERY access right.

### `InOutBufferSize` [in, out]

Pointer to a memory location that specifies the size of the buffer passed in the *OutBuffer* parameter. If the routine succeeds, it updates the memory location to specify the number of bytes actually stored in *OutBuffer*. If the routine fails with status code of STATUS_BUFFER_TOO_SMALL, it returns the number of bytes required to return the data.

### `OutBuffer` [out, optional]

Pointer to the buffer where the routine returns the WMI data. The routine returns a sequence of variable-sized [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structures, one for each set of returned data blocks. The **WnodeHeader.Linkage** member of each **WNODE_ALL_DATA** structure contains the offset from the beginning of the current **WNODE_ALL_DATA** to the beginning of the next **WNODE_ALL_DATA**. The final block in the chain has **WnodeHeader.Linkage** set to zero. *OutBuffer* must point to a buffer allocated from nonpaged pool.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine returns the WMI data in the buffer pointed to by the *OutBuffer* parameter. The routine also returns the size, in bytes, of the returned data in the memory location pointed to by the *InOutBufferSize* parameter. |
| **STATUS_WMI_GUID_NOT_FOUND** | No drivers implement the specified WMI class. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer passed by the caller in the *OutBuffer* parameter is too small. The routine returns the required buffer size in the memory location pointed to by the *InOutBufferSize* parameter. |

## Remarks

**IoWMIQueryAllData** determines which drivers support the specified WMI class, and issues an **IRP_MN_QUERY_ALL_DATA** request to every such driver.

To query for multiple WMI classes, use [IoWMIQueryAllDataMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldatamultiple).

## See also

[IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[IoWMIQueryAllDataMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiqueryalldatamultiple)