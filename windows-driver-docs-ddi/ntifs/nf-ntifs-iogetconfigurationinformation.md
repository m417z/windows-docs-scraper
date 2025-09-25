# IoGetConfigurationInformation function (ntifs.h)

## Description

The **IoGetConfigurationInformation** routine returns a pointer to the I/O manager's global configuration information structure, which contains the current values for how many physical disk, floppy, CD-ROM, tape, SCSI HBA, serial, and parallel devices have device objects created to represent them by drivers as they are loaded.

## Return value

**IoGetConfigurationInformation** returns a pointer to a [**CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-configuration_information) structure.

## Remarks

Certain types of device drivers can use the configuration information structure's values to construct device object names with appropriate digit suffixes when each driver creates its device objects. Note that the digit suffix for device object names is a zero-based count, while the counts maintained in the configuration information structure represent the number of device objects of a particular type already created. That is, the configuration information counts are one-based.

Any driver that calls **IoGetConfigurationInformation** must increment the count for its kind of device in this structure when it creates a device object to represent a physical device.

The system-supplied SCSI port driver supplies the count of SCSI HBAs present in the computer. SCSI class drivers can read this value to determine how many HBA-specific miniport drivers might control a SCSI bus with an attached device of the class driver's type.

The configuration information structure also contains a value indicating whether an already loaded driver has claimed either of the "AT" disk I/O address ranges.

## See also

[HalAssignSlotResources](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[HalGetBusDataByOffset](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546644(v=vs.85))

[IoAssignResources](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)