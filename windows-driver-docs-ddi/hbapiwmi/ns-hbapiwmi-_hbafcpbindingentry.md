# _HBAFCPBindingEntry structure

## Description

The HBAFCPBindingEntry structure defines a binding between the information that uniquely identifies a logical unit for the operating system and the fibre channel protocol (FCP) identifier for the logical unit.

## Members

### `Type`

Contains a binding type that indicates how the target is specified in the binding. This member can have any of the following values:

| Type Value | Meaning |
| --- | --- |
| HBA_BIND_TO_D_ID | Indicates that the target is identified by its fibre channel protocol (FCP) ID. The **Fcid** member of the [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_WWPN | Indicates that the target is identified by its worldwide port name. The **PortWWN** member of the [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_WWNN | Indicates that the fibre channel target device is identified by its worldwide node name. The **NodeWWN** member of the [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_LUID | Indicates that the target is identified by its fibre channel logical unit ID. The **FcpLun** member of the [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TARGETS | Indicates that the system should automatically generate target mappings from logical unit numbers to fibre channel protocol identifiers. |

You must include file *hbaapi.h* to use the symbolic constants in this table (See the **Headers** section).

For a comparable set of values that define how an HBA specifies targets and logical units in the persistent bindings that it maintains, see the WMI property qualifier [HBA_BIND_TYPE](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-bind-type).

For a more detailed description of the values that this member can have, see the T11 committee's *Fibre Channel HBA API* specification.

### `FCPId`

Contains a structure of type [HBAFCPID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) that contains the FCP identifier for the logical unit and information about the port to be queried for information about the device.

### `ScsiId`

Contains a structure of type [HBAScsiID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid) that contains the information that uniquely identifies a logical unit for the operating system.

## Remarks

The WMI tool suite generates a declaration of this structure automatically when it compiles the [HBAFCPBindingEntry WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/hbafcpbindingentry-wmi-class) in *hbaapi.mof*.

For an explanation of the fibre channel protocol (FCP), see the T11 committee's *Fibre Channel Protocol for SCSI* specification.

## See also

[HBAFCPBindingEntry WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/hbafcpbindingentry-wmi-class)