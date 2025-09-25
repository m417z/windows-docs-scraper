# _HBAFCPScsiEntry structure

## Description

The HBAFCPScsiEntry structure is used with [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) method of the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class) to define a binding between the operating system information that uniquely identifies a logical unit and the fibre channel protocol (FCP) identifier that identifies the logical unit.

## Members

### `FCPId`

Contains a structure of type [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) that contains the FCP identifier for the logical unit and information about the port to be queried for information about the device.

### `Luid`

Contains the logical unit descriptor for the device that the operating system derives from SCSI inquiry data.

### `ScsiId`

Contains a structure of type [HBAScsiID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid) that contains the information that uniquely identifies a logical unit for the operating system.

## See also

[GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping)