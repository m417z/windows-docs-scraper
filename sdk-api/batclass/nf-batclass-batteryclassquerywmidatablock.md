# BatteryClassQueryWmiDataBlock function

## Description

The **BatteryClassQueryWmiDataBlock** routine is used by battery miniclass drivers inside their [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routines to allow the battery class driver to process the WMI data block query requests it handles on behalf of the driver.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle that was previously received from [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

### `DeviceObject` [in, out]

Pointer to the driver's device object. The battery miniclass driver should pass the matching parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

### `Irp` [in, out]

Pointer to the WMI query data block request. The battery miniclass driver should pass the matching parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

### `GuidIndex` [in]

Specifies the WMI class by its index. The battery miniclass driver should pass the matching parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

### `InstanceLengthArray` [out]

Pointer to an array of ULONG values that indicate the length of each instance to be returned. The battery miniclass driver should pass the matching parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

### `OutBufferSize` [in]

Specifies the maximum number of bytes available to receive data in the buffer specified by the *Buffer* parameter. The battery miniclass driver should pass the value of the *BufferAvail* parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

### `Buffer` [out, optional]

Pointer to the buffer to receive the instance data. If the buffer is too small to hold the data, **BatteryClassQueryWmiDataBlock** returns a status value of STATUS_BUFFER_TOO_SMALL. The battery miniclass driver should pass the matching parameter it receives as input to its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine.

## Return value

**BatteryClassQueryWmiDataBlock** returns an NT status code. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The battery class driver successfully handled the request. |
| **STATUS_BUFFER_TOO_SMALL** | The battery class driver cannot handle the request because the buffer specified by the *Buffer* parameter is too small. |
| **STATUS_WMI_GUID_NOT_FOUND** | The battery class driver does not handle this WMI class. |

## Remarks

By design, a battery miniclass driver should call **BatteryClassQueryWmiDataBlock** inside its [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine before processing the request. The miniclass driver should pass the parameters it receives as input to its **DpWmiQueryDataBlock** routine. If the battery class driver returns any status other than STATUS_WMI_GUID_NOT_FOUND, the routine has handled the request on behalf of the miniclass driver. In that case, the class driver has already called [WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nf-wmilib-wmicompleterequest), and miniclass driver must not call it again.

## See also

[BatteryClassSystemControl](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclasssystemcontrol)

[DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback)

[WmiCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nf-wmilib-wmicompleterequest)