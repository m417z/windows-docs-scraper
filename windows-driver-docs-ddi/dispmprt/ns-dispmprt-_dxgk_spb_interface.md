# DXGK_SPB_INTERFACE structure

## Description

The **DXGK_SPB_INTERFACE** structure contains pointers to functions in the Simple Peripheral Bus (SPB) Interface that a Windows Display Driver Model (WDDM) 1.2 and later display miniport driver can call to inspect and alter SPB resources.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of the SPB interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_SPB_INTERFACE_VERSION_1).

### `Context`

A pointer to a context that is provided by the display miniport driver.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display miniport driver.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display miniport driver.

### `OpenSpbResource`

Opens a Simple Peripheral Bus (SPB) resource. All input parameters are supplied by the display miniport driver.

| OpenSpbResource Parameter | Description |
| ------------------------- | ----------- |
| **DeviceHandle** | Handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. |
| **SpbReourceId** | The resource ID of the SPB resource hub. |
| **SpbResourceSubName** | Optional pointer to the Unicode SPB resource subname. |
| **DesiredAccess** | An [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that determines the requested access to the SPB resource. For more information, see the *DesiredAccess* parameter of the [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) function. |
| **ShareAccess** | Type of share access for the file. For more information, see the *ShareAccess* parameter of [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile). |
| **OpenOptions** | The options to apply when opening the SPB resource. For more information, see the *CreateOptions* parameter of [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile). |
| **SpbResource** | A pointer to a buffer that is used to return the handle to the SPB resource. |

### `CloseSpbResource`

Closes an SPB resource. All input parameters are supplied by the display miniport driver.

Closing an open object handle causes that handle to become invalid. The system also decrements the handle count for the object and checks whether the object can be deleted. The system does not actually delete the object until all of the object's handles are closed and no referenced pointers remain.

The driver must call **CloseSpbResource** to close every handle that it has opened with **OpenSpbResource** as soon as the handle is no longer required.

Callers of **CloseSpbResource** should not assume that this function automatically waits for all I/O to complete prior to returning.

| CloseSpbResource Parameter | Description |
| -------------------------- | ----------- |
| **DeviceHandle** | A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. |
| **SpbResource** | A pointer to an SPB resource that the display miniport driver opened using the **OpenSpbResource** function. |

### `ReadSpbResource`

Reads data from an open SPB resource. All input parameters are supplied by the display miniport driver.

If the call to **OpenSpbResource** set either of the *OpenOptions* flags **FILE_SYNCHRONOUS_IO_ALERT** or **FILE_SYNCHRONOUS_IO_NONALERT** (defined in *Wdm.h*), the I/O Manager maintains the current file position. If so, the caller of **ReadSpbResource** can specify that the current file position offset be used instead of an explicit *ByteOffset* value. This specification can be made by using one of the following methods:

* Specify a pointer to a [**LARGE_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) value with the **HighPart** member set to -1 and the **LowPart** member set to the system-defined value **FILE_USE_FILE_POINTER_POSITION** (defined in Wdm.h).
* Pass a **NULL** pointer for *ByteOffset*.

**ReadSpbResource** updates the current file position by adding the number of bytes read when it completes the read operation, if it is using the current file position maintained by the I/O Manager.

Even when the I/O Manager is maintaining the current file position, the caller can reset this position by passing an explicit *ByteOffset* value to **ReadSpbResource**. Doing this automatically changes the current file position to that *ByteOffset* value, performs the read operation, and then updates the position according to the number of bytes actually read. This technique gives the caller atomic seek-and-read service.

| OpenSpbResource Parameter | Description |
| ------------------------- | ----------- |
| **DeviceHandle** | A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. |
| **SpbResource** | A pointer to an SPB resource that the display miniport driver opened using the **OpenSpbResource** function. |
| **Length** | The size, in bytes, of the buffer pointed to by the *Buffer* parameter. |
| **Buffer** | A pointer to a buffer that receives the data read from the specified SPB resource. |
| **ByteOffset** | An optional pointer to a variable that specifies the starting byte offset in the SPB resource where the read operation will begin. If an attempt is made to read beyond the end of the file, **ReadSpbResource** returns an error. |
| **EventHandle** | An optional handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the read operation is completed and the given event is set to the **Signaled** state. This parameter can be **NULL**. |
| **IoStatusBlock** | A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested read operation. The **Information** member of the **IO_STATUS_BLOCK** structure receives the number of bytes actually read from the SPB resource. |

### `WriteSpbResource`

Writes data to an open SPB resource.

If the call to the **OpenSpbResource** function set only the *DesiredAccess* flag **FILE_APPEND_DATA**, the *ByteOffset* parameter is ignored. In this case, data in the buffer pointed to by the *Buffer* parameter, for **Length** bytes, is written starting at the current end of file.

If the call to **OpenSpbResource** set either of the *CreateOptions* flags, **FILE_SYNCHRONOUS_IO_ALERT** or **FILE_SYNCHRONOUS_IO_NONALERT**, the I/O Manager maintains the current file position. If so, the caller of **WriteSpbResource** can specify that the current file position offset be used instead of an explicit *ByteOffset* value. This specification can be made by using one of the following methods:

* Specify a pointer to a [**LARGE_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) value with the **HighPart** member set to -1 and the **LowPart** member set to the system-defined value **FILE_USE_FILE_POINTER_POSITION** (defined in *Wdm.h*).
* Pass a **NULL** pointer for *ByteOffset*.

**WriteSpbResource** updates the current file position by adding the number of bytes written when it completes the write operation, if it is using the current file position maintained by the I/O Manager.

Even when the I/O Manager is maintaining the current file position, the caller can reset this position by passing an explicit *ByteOffset* value to **WriteSpbResource**. Doing this automatically changes the current file position to that *ByteOffset* value, performs the write operation, and then updates the position according to the number of bytes actually written. This technique gives the caller atomic seek-and-write service.

It is also possible to cause a write operation to start at the current end of file by specifying for *ByteOffset* a pointer to a [**LARGE_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) value with **HighPart** set to -1 and **LowPart** set to **FILE_WRITE_TO_END_OF_FILE**. This works regardless of whether the I/O Manager is maintaining the current file position.

| WriteSpbResource Parameter | Description |
| -------------------------- | ----------- |
| **DeviceHandle** | A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. |
| **SpbResource** | A pointer to an SPB resource that the display miniport driver opened using the **OpenSpbResource** function. |
| **Length** | The size, in bytes, of the buffer pointed to by the *Buffer* parameter. |
| **Buffer** | A pointer to a caller-allocated buffer that contains the data to be written to the specified SPB resource. |
| **ByteOffset** | An optional pointer to a variable that specifies the starting byte offset in the SPB resource where the write operation will begin. If the *Length* and *ByteOffset* parameters specify a write operation past the current end-of-file mark, **WriteSpbResource** automatically extends the file and updates the end-of-file mark; any bytes that are not explicitly written between such old and new end-of-file marks are defined to be zero. |
| **EventHandle** | An optional handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the write operation is completed and the given event is set to the **Signaled** state. This parameter can be **NULL**. |
| **IoStatusBlock** | A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested write operation. The **Information** member of the **IO_STATUS_BLOCK** structure receives the number of bytes actually written to the SPB resource.

### `SpbResourceIoControl`

Performs an I/O control operation on an open Simple Peripheral Bus (SPB) resource. All input parameters are supplied by the display miniport driver.

If the caller opened the file for asynchronous I/O (with neither **FILE_SYNCHRONOUS_XXX** create/open option set), the specified event, if any, will be set to the **Signaled** state when the device control operation completes. Otherwise, the file object specified by the *DeviceHandle* parameter will be set to the **Signaled** state.

| SpbResourceIoControl Parameter | Description |
| ------------------------------ | ----------- |
| **DeviceHandle** | A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function. |
| **SpbResource** | A pointer to an SPB resource that the display miniport driver opened using the **OpenSpbResource** function. |
| **IoControlCode** | A device I/O control code (IOCTL_XXX) that indicates which device I/O control operation is to be carried out on, usually by the underlying device driver. The value of this parameter determines the format and required length of the *InputBuffer* and *OutputBuffer* parameters, as well as which of the following parameter pairs are required. |
| **InBufferSize** | The size, in bytes, of the buffer pointed to by the *InputBuffer* parameter. This value is ignored if *InputBuffer* is **NULL**. |
| **InputBuffer** | A pointer to a caller-allocated input buffer that contains device-specific information to be given to the target device. If the *IoControlCode* parameter specifies an operation that does not require input data, this pointer can be **NULL**. |
| **OutBufferSize** | The size, in bytes, of the buffer pointed to by the *OutputBuffer* parameter. This value is ignored if *OutputBuffer* is **NULL**. |
| **OutputBuffer** | A pointer to a caller-allocated output buffer in which information is returned from the target device. If the *IoControlCode* parameter specifies an operation that does not produce output data, this pointer can be **NULL**. |
| **EventHandle** | An optional handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the requested operation is completed and the given event is set to the **Signaled** state. This parameter can be **NULL**. |
| **IoStatusBlock** | A pointer to a variable that receives the final completion status and information about the requested I/O control operation. For successful calls that return data, the number of bytes written to the buffer pointed to by the *OutputBuffer* parameter is returned in the **Information** member of the [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure. |

## Remarks

To use this structure's functions, first supply the **Size** and **Version** members of the **DXGK_SPB_INTERFACE** structure. Then call the [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services) function with the **ServicesType** parameter set to a value of **DxgkServicesFirmwareTable**, and set the **Interface** parameter to the address (cast as **PINTERFACE**) of the **DXGK_SPB_INTERFACE** structure.

For more information on SPB architecture, see [Simple Peripheral Buses](https://learn.microsoft.com/windows-hardware/design/component-guidelines/simple-peripheral-bus--spb-) and [SPB Peripheral Driver Design Guide**](https://learn.microsoft.com/windows-hardware/drivers/spb).