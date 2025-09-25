# SCSIWMIGUIDREGINFO structure

## Description

The SCSIWMIGUIDREGINFO structure contains information about a given data or event block supported by a SCSI miniport driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Guid`

Points to the GUID that identifies the block.

### `InstanceCount`

Specifies the number of instances defined for the block.

### `Flags`

Indicates characteristics of the block. The SCSI port driver sets all but the following WMIREG_FLAG_*XXX* on behalf of the miniport driver. A miniport driver might set one or more of the following flags:

#### WMIREG_FLAG_EVENT_ONLY_GUID

The block can be enabled or disabled as an event only, and cannot be queried or set. If this flag is clear, the block can also be queried or set.

#### WMIREG_FLAG_EXPENSIVE

Requests the port driver send an enable-collection SRB the first time a data consumer opens the data block and a disable-collection SRB when the last data consumer closes the data block. This is recommended if collecting such data affects performance. A miniport driver need not collect the data until a data consumer explicitly requests it by opening the block.

#### WMIREG_FLAG_REMOVE_GUID

Removes support for a previously registered block when set.

## Remarks

The miniport driver passes a pointer to a SCSI_WMILIB_CONTEXT which contains a SCSIWMIREGGUID array in the *WmiLibInfo* parameter of [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction). The miniport driver passes this information each time it calls **ScsiPortWmiDispatchFunction**. Each SCSIWMIREGGUID structure in the array represents one of the miniport driver's data or event blocks.

A miniport driver's SCSIWMIREGGUID array should include any standard data blocks defined in *wmicore.mof* for its device type, and might include miniport driver-defined data and event blocks. A miniport driver defines custom data and event blocks in a MOF file, which is compiled as a resource attached to the miniport driver's binary image and specified in the *MofResourceName* parameter of the miniport driver's HwScsiWmiQueryReginfo routine.

For more information about defining blocks, [Windows Management Instrumentation](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi).

## See also

[HwScsiWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_query_reginfo)

[SCSI_WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-_scsiwmilib_context)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)