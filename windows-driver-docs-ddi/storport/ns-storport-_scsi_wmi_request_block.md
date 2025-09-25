# _SCSI_WMI_REQUEST_BLOCK structure (storport.h)

## Description

This structure is a special version of a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) for use with WMI commands.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

Specifies the size in bytes of this structure.

### `Function`

SRB_FUNCTION_WMI, which specifies that the request is a WMI request. If this member is not set to SRB_FUNCTION_WMI, the miniport driver should fail the request.

### `SrbStatus`

Returns the status of the completed request. This member should be set by the miniport driver before it notifies the OS-specific driver that the request has completed by calling [ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification) with **RequestComplete**. The value of this member can be any value listed for **SrbStatus** in SCSI_REQUEST_BLOCK.

### `WMISubFunction`

Indicates the WMI action to be performed. A miniport driver calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with *MinorFunction* set to this value. The subfunction value corresponds to the WMI minor IRP number that identifies the WMI operation.

### `PathId`

Indicates the SCSI port or bus for the request. This value is zero-based. If SRB_WMI_FLAGS_ADAPTER_REQUEST is set in **WMIFlags**, this member is reserved.

### `TargetId`

Indicates the target controller or device on the bus. If SRB_WMI_FLAGS_ADAPTER_REQUEST is set in **WMIFlags**, this member is reserved.

### `Lun`

Indicates the logical unit number of the device. If SRB_WMI_FLAGS_ADAPTER_REQUEST is set in **WMIFlags**, this member is reserved.

### `Reserved1`

Reserved for system use and not available for use by miniport drivers.

### `WMIFlags`

Indicates that the WMI request is for the adapter if SRB_WMI_FLAGS_ADAPTER_REQUEST is set and that **PathId**, **TargetId**, and **Lun** are reserved. Otherwise, **WMIFlags** will be **NULL**, indicating that the request is for the device specified by **PathId**, **TargetId**, and **Lun**.

### `Reserved2`

Reserved for system use and not available for use by miniport drivers.

### `SrbFlags`

Indicates various parameters and options about the request. **SrbFlags** is read-only. This member will be set to one or more of the following flags ORed together:

#### SRB_FLAGS_DATA_IN

Indicates data will be transferred from the device to the system.

#### SRB_FLAGS_DATA_OUT

Indicates data will be transferred from the system to the device.

#### SRB_FLAGS_NO_DATA_TRANSFER

Indicates no data transfer with this request. If this is set, the flags SRB_FLAGS_DATA_OUT, SRB_FLAGS_DATA_IN, and SRB_FLAGS_UNSPECIFIED_DIRECTION are clear.

#### SRB_FLAGS_DISABLE_SYNCH_TRANSFER

Indicates the HBA, if possible, should perform asynchronous I/O for this transfer request. If synchronous I/O was negotiated previously, the HBA must renegotiate for asynchronous I/O before performing the transfer.

#### SRB_FLAGS_DISABLE_DISCONNECT

Indicates the HBA should not allow the target to disconnect from the SCSI bus during processing of this request.

### `DataTransferLength`

Indicates the size in bytes of the data buffer. A miniport driver calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with *BufferSize* set to this value. If an underrun occurs, the miniport driver must update this member to the number of bytes actually transferred.

### `TimeOutValue`

Indicates the interval in seconds that the request can execute before the OS-specific port driver might consider it timed out. Miniport drivers are not required to time requests because the port driver already does.

### `DataBuffer`

Points to the data buffer. A miniport driver calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with *Buffer* set to this value. Miniport drivers can use this value as a data pointer regardless of the value of **MapBuffers** in the PORT_CONFIGURATION_INFORMATION for the HBA. A miniport driver cannot transfer data directly into the buffer using DMA.

### `DataPath`

Specifies the WMI data path for this request. A miniport driver calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with *DataPath* set to this value.

### `Reserved3`

Reserved for system use and not available for use by miniport drivers.

### `OriginalRequest`

Points to the IRP for this request. This member is irrelevant to miniport drivers.

### `SrbExtension`

Points to the Srb extension. A miniport driver must not use this member if it set **SrbExtensionSize** to zero in the HW_INITIALIZATION_DATA. The memory at **SrbExtension** is not initialized by the OS-specific port driver, and the miniport driver-determined data can be accessed directly by the HBA. The corresponding physical address can be obtained by calling [ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress) with the **SrbExtension** pointer.

### `Reserved4`

Reserved for system use and not available for use by miniport drivers.

### `Reserved6`

Reserved for system use and not available for use by miniport drivers. This member is valid starting with Windows Server 2003 with SP1.

### `Reserved5`

Reserved for system use and not available for use by miniport drivers.

##### - SrbFlags.SRB_FLAGS_DATA_IN

Indicates data will be transferred from the device to the system.

##### - SrbFlags.SRB_FLAGS_DATA_OUT

Indicates data will be transferred from the system to the device.

##### - SrbFlags.SRB_FLAGS_DISABLE_DISCONNECT

Indicates the HBA should not allow the target to disconnect from the SCSI bus during processing of this request.

##### - SrbFlags.SRB_FLAGS_DISABLE_SYNCH_TRANSFER

Indicates the HBA, if possible, should perform asynchronous I/O for this transfer request. If synchronous I/O was negotiated previously, the HBA must renegotiate for asynchronous I/O before performing the transfer.

##### - SrbFlags.SRB_FLAGS_NO_DATA_TRANSFER

Indicates no data transfer with this request. If this is set, the flags SRB_FLAGS_DATA_OUT, SRB_FLAGS_DATA_IN, and SRB_FLAGS_UNSPECIFIED_DIRECTION are clear.

## Remarks

Windows NT storage class and filter drivers can send WMI SRBs to the system port driver. The system port driver will handle certain WMI requests on behalf of miniport drivers. If the port driver cannot handle a WMI request, it forwards the request to the miniport driver.

A miniport driver receives WMI requests from the port driver only if the miniport driver set **WmiDataProvider** in the PORT_CONFIGURATION_INFORMATION structure. If the miniport driver supports a request, it should process it and complete the request by calling **ScsiPortNotification** twice, first with **RequestComplete** and then with **NextRequest** (or **NextLuRequest**).

For information about supporting WMI in miniport drivers, see the [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi).

## See also

[HW_INITIALIZATION_DATA (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data)

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[ScsiPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportnotification)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)