# IoWMIExecuteMethod function

## Description

The **IoWMIExecuteMethod** routine runs a WMI class method on the specified WMI data block instance.

## Parameters

### `DataBlockObject` [in]

Pointer to a WMI data block object. The caller opens the data block object for the WMI class with [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock). The object must be opened with the WMIGUID_EXECUTE access right.

### `InstanceName` [in]

Specifies the name of the instance of the data block. This value corresponds to the value of the **InstanceName** property for the block.

### `MethodId` [in]

Specifies the method item ID for the method to be set. The value of this parameter corresponds to the value declared in the **WmiMethodId** qualifier for the method.

### `InBufferSize` [in]

Specifies the size, in bytes, of input data for the method. The actual input data is passed in the buffer pointed to by the *InOutBuffer* parameter.

### `OutBufferSize` [in, out]

Pointer to a ULONG that specifies the expected size, bytes, of the data output by the method. The actual output data is returned in the buffer pointed to by the *InOutBuffer* parameter. If the routine succeeds, it updates the memory location to specify the number of bytes actually stored in *InOutBuffer*. If the routine fails with STATUS_BUFFER_TOO_SMALL, it returns the number of bytes required to return the data.

### `InOutBuffer` [in, out]

Pointer to the buffer where the caller passes the WMI method's input data, and receives the WMI method's output data.

## Return value

The routine returns an NTSTATUS code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. The routine returns the WMI data in the buffer pointed to by the *InOutBuffer* parameter. The routine also returns the size, in bytes, of the returned data in the memory location pointed to by the *OutBufferSize* parameter. |
| **STATUS_WMI_GUID_NOT_FOUND** | No drivers implement the WMI class. |
| **STATUS_WMI_INSTANCE_NOT_FOUND** | No driver implements an instance of the WMI class with **InstanceName** property equal to the value specified in the *InstanceName* parameter. |
| **STATUS_WMI_ITEMID_NOT_FOUND** | The WMI class does not contain a method with method ID equal to the value of *MethodId*. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer passed by the caller in the *OutBuffer* parameter is too small. The routine returns the required buffer size in the memory location pointed to by the *InOutBufferSize* parameter. |
| **STATUS_WMI_GUID_DISCONNECTED** | The WMI GUID is no longer available or was never available. |

## Remarks

**IoWMIExecuteMethod** determines which drivers might support the specified WMI class and instance name. It issues an [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request to each such driver. The driver that exports the data block instance with matching **InstanceName** property then runs the specified WMI method.

## See also

[IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method)

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)