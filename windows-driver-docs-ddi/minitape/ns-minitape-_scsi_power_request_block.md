# _SCSI_POWER_REQUEST_BLOCK structure (minitape.h)

## Description

The **SCSI_POWER_REQUEST_BLOCK** structure is a special version of a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) that is used for power management requests.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

The size, in bytes, of the **SCSI_POWER_REQUEST_BLOCK** structure.

### `Function`

The operation to perform. For the **SCSI_POWER_REQUEST_BLOCK** structure, this member is always set to SRB_FUNCTION_POWER.

### `SrbStatus`

The status of the completed request. This member should be set by the miniport driver before it notifies the Storport driver that the request has completed. A miniport driver notifies the Storport driver that the request has completed by calling the [StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) function with the [RequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) notification type.

See [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) in the WDK documentation for a list of possible values for this member.

### `SrbPowerFlags`

The power management flags. Currently, the only flag allowed is SRB_POWER_FLAGS_ADAPTER_REQUEST, which indicates that the power management request is for the adapter. If this flag is set, the miniport driver should ignore the values in the **PathId**, **TargetId**, and **Lun**.

### `PathId`

The SCSI port or bus identifier for the request. This value is zero based.

### `TargetId`

The target controller or device identifier on the bus.

### `Lun`

The logical unit number (LUN) of the device.

### `DevicePowerState`

An enumerator value of type [STOR_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_device_power_state) that specifies the requested power state of the device.

### `SrbFlags`

Miniport driver should ignore this member.

### `DataTransferLength`

Miniport driver should ignore this member.

### `TimeOutValue`

The interval, in seconds, that the request can execute before the Storport driver determines that the request has timed out.

### `DataBuffer`

Miniport driver should ignore this member.

### `SenseInfoBuffer`

Miniport driver should ignore this member.

### `NextSrb`

Miniport driver should ignore this member.

### `OriginalRequest`

Miniport driver should ignore this member.

### `SrbExtension`

A pointer to the SRB extension. A miniport driver must not use this member if it set **SrbExtensionSize** to zero in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure. The Storport driver does not initialize the memory that this member points to. The HBA can directly access the data that the miniport driver writes into the SRB extension. A miniport driver can obtain the physical address of the SRB extension by calling the [StorPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetphysicaladdress) routine.

### `PowerAction`

An enumerator value of type [STOR_POWER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_power_action) that specifies the type of system shutdown that is about to occur. This value is meaningful only if the device is moving into the D1, D2, or D3 power state as indicated by the **DevicePowerState** member.

### `Reserved`

Reserved for system use.

### `Reserved5`

Reserved for system use.

## Remarks

The Storport driver calls [HwStorBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) to pass SRBs to the miniport driver. **HwStorBuildIo** should check the **Function** member of the SRB to determine the type of the SRB. If the **Function** member is set to SRB_FUNCTION_POWER, the SRB is a structure of type **SCSI_POWER_REQUEST_BLOCK**.

The Storport driver sends **SCSI_POWER_REQUEST_BLOCK** requests to a miniport driver to notify the miniport driver of Windows power events that affect storage devices that are connected to the adapter. In the case of a power up event, this request gives the miniport driver an opportunity to initialize itself. In the case of a hibernation or shutdown event, this request gives the miniport driver an opportunity to complete I/O requests and prepare for a power down. The miniport driver can use the value in the **PowerAction** member of the **SCSI_POWER_REQUEST_BLOCK** to determine what actions are required. After the miniport driver completes the **SCSI_POWER_REQUEST_BLOCK** request, the Storport driver calls [HwScsiAdapterControl](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557274(v=vs.85)) with a control request of **ScsiStopAdapter** to power down the adapter. The miniport driver reinitialize while processing the SRB_FUNCTION_POWER request, or it can wait and reinitialize when the Storport driver calls [HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) to perform a an **ScsiRestartAdapter** control request.

 When transitioning from the D0 power state to a lower-powered state (D1, D2, or D3) the Storport driver sends a **SCSI_POWER_REQUEST_BLOCK** request to the miniport driver before the underlying bus driver powers down the adapter.

The following conditions must exist before the Storport driver will send a **SCSI_POWER_REQUEST_BLOCK** request to the miniport driver:

* The adapter is not stopped.
* The I/O queue for the adapter is paused.
* The adapter hardware is powered up.
* The miniport can access the adapter's hardware resources.

## See also

[HwStorBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)