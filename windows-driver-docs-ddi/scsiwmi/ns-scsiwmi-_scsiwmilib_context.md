# _SCSIWMILIB_CONTEXT structure

## Description

A SCSI_WMILIB_CONTEXT structure provides registration information for a miniport driver's data and event blocks and defines entry points for the miniport driver's **HwScsiWmi*****Xxx*** callback routines.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `GuidCount`

Specifies the number of structures in the SCSIWMIGUIDREGINFO array at **GuidList**.

### `GuidList`

Points to an array of **GuidCount** SCSIWMIGUIDREGINFO structures that contain registration information for each block.

### `QueryWmiRegInfo`

Points to the driver's [HwScsiWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_query_reginfo) routine, which is a required entry point for miniport drivers that support WMI.

### `QueryWmiDataBlock`

Points to the driver's [HwScsiWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_query_datablock) routine, which is a required entry point for miniport drivers that support WMI.

### `SetWmiDataBlock`

Points to the driver's [HwScsiWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_set_datablock) routine, which is an optional entry point for miniport drivers that support WMI. If the miniport driver does not implement this routine, it must set this member to **NULL**

### `SetWmiDataItem`

Points to the driver's [HwScsiWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_set_dataitem) routine, which is an optional entry point for miniport drivers that support WMI. If the miniport driver does not implement this routine, it must set this member to **NULL**.

### `ExecuteWmiMethod`

Points to the driver's [HwScsiWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_execute_method) routine, which is an optional entry point for miniport drivers that support WMI. If the miniport driver does not implement this routine, it must set this member to **NULL**

### `WmiFunctionControl`

Points to the driver's [HwScsiWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_function_control) routine, which is an optional entry point for miniport drivers that support WMI. If the miniport driver does not implement this routine, it must set this member to **NULL**.

## Remarks

A SCSI miniport driver that supports WMI stores an initialized SCSI_WMILIB_CONTEXT structure (or a pointer to such a structure) in its device extension. A miniport driver can use the same SCSI_WMILIB_CONTEXT structure for multiple device objects if each device object supplies the same set of data blocks.

When the miniport driver receives an SRB in which the **Function** member is set to SRB_FUNCTION_WMI, it calls [ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction) with request parameters, including a pointer to an initialized SCSI_WMILIB_CONTEXT structure. **ScsiPortWmiDispatchFunction** handles the request by calling the miniport driver's appropriate HwScsiWmiXxx routine.

If the miniport driver does not implement an optional HwScsiWmiXxx routine, the port driver returns an appropriate status to the caller.

## See also

[HwScsiWmiExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_execute_method)

[HwScsiWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_function_control)

[HwScsiWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_query_datablock)

[HwScsiWmiQueryReginfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_query_reginfo)

[HwScsiWmiSetDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_set_datablock)

[HwScsiWmiSetDataItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_set_dataitem)

[SCSIWMIGUIDREGINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/ns-scsiwmi-scsiwmiguidreginfo)

[ScsiPortWmiDispatchFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nf-scsiwmi-scsiportwmidispatchfunction)