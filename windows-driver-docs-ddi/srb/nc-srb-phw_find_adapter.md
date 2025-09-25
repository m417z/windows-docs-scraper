# PHW_FIND_ADAPTER callback

## Description

The PHW_FIND_ADAPTER prototype declares a routine that uses supplied configuration to determine whether a specific HBA is supported and, if it is, to return configuration information about that adapter.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `HwContext` [in]

Reserved member when used by one of the Storport driver's miniport drivers. With SCSI miniport drivers this member points to a context value. For a description of the meaning of this member for a SCSI miniport driver, see [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)).

### `BusInformation` [in]

Reserved member when used by one of the Storport driver's miniport drivers. With SCSI miniport drivers this member points to bus-type-specific information that the OS-specific port driver has gathered. For a complete description of the meaning of this member for a SCSI miniport driver, see [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)).

### `ArgumentString` [in]

Reserved member when used by one of the Storport driver's miniport drivers. With SCSI miniport drivers this member points to a null-terminated ASCII string that contains device information such as a base parameter or an interrupt level from the registry. For a complete description of the meaning of this member for a SCSI miniport driver, see [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)).

### `ConfigInfo` [in, out]

Pointer to a [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information) structure that contains configuration information for the HBA.

### `Again` [out]

Reserved member when used by one of the Storport driver's miniport drivers. With SCSI miniport drivers this member points to a BOOLEAN variable that informs the port driver whether it should call this routine again. For more information about the meaning of this member for a SCSI miniport driver, see [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)).

## Return value

The routine declared by this prototype must return one of the following status values:

| Return code | Description |
| ----------- | ----------- |
| SP_RETURN_FOUND | Indicates a supported HBA was found and that the HBA-relevant configuration information was successfully determined and set in the PORT_CONFIGURATION_INFORMATION structure. |
| SP_RETURN_ERROR | Indicates an HBA was found but there was error obtaining the configuration information. If possible, such an error should be logged with [**ScsiPortLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportlogerror). |
| SP_RETURN_BAD_CONFIG | Indicates the supplied configuration information was invalid for the adapter. |
| SP_RETURN_NOT_FOUND | Indicates no supported HBA was found for the supplied configuration information. |

## Remarks

This declaration is used by both SCSI and StorPort miniport drivers.

For more information about the SCSI miniport driver's version of the routine associated with this declaration, see [**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)).

For more information about the Storport driver's version of the routine associated with this declaration, see [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter).

## See also

[**HwScsiFindAdapter**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)