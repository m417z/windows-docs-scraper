# HBAFCPBindingEntry2 structure

## Description

The **HBAFCPBindingEntry2** structure defines a binding between the information that uniquely identifies a logical unit for the operating system and the fibre channel protocol (FCP) identifier for the logical unit.

## Members

### `Type`

Indicates the binding type. For a description of the values that this member can have, see the T11 committee's *Fibre Channel HBA API* specification.

| Value | Meaning |
| ----- | ------- |
| HBA_BIND_TO_D_ID | The target is identified by its fibre channel protocol (FCP) ID. The **Fcid** member of the [**HBAFCPID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_WWPN | The target is identified by its worldwide port name. The **PortWWN** member of the [**HBAFCPID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_WWNN | The fibre channel target device is identified by its worldwide node name. The **NodeWWN** member of the [**HBAFCPID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TO_LUID | The target is identified by its fibre channel logical unit ID. The **FcpLun** member of the [**HBAFCPID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) structure contains this value. |
| HBA_BIND_TARGETS | The system should automatically generate target mappings from logical unit numbers to fibre channel protocol identifiers. |

For information about what needs to be included to use the symbols that represent the binding types, see the Headers section.

### `FCPId`

Contains a structure of type [**HBAFCPID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpid) that contains the FCP identifier for the logical unit and information about the port to be queried for information about the device.

### `Luid[256]`

Contains the logical unit descriptor for the device that the operating system derives from SCSI inquiry data.

### `ScsiId`

Contains a structure of type [**HBAScsiID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid) that contains the information that uniquely identifies a logical unit for the operating system.

## Remarks

This structure is very similar to the [**HBAFCPBindingEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry) structure. The only difference is that **HBAFCPBindingEntry2** includes the number that the operating system generates for the logical unit.

The WMI tool suite generates a declaration of **HBAFCPBindingEntry2** automatically when it compiles the [HBAFCPBindingEntry WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/hbafcpbindingentry-wmi-class) that is defined in *hbaapi.mof*.

For an explanation of the fibre channel protocol (FCP), see the T11 committee's *dpANS Fibre Channel Protocol for SCSI* specification.

## See also

[**HBAFCPBindingEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry)

[HBAFCPBindingEntry2 WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/hbafcpbindingentry2-wmi-class)