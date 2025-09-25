# _MSiSCSI_NICConfig structure

## Description

The MSiSCSI_NICConfig structure describes the configuration of a network interface card (NIC) port.

## Members

### `LinkSpeed`

The speed of the network link, in megabits per second.

### `MaxLinkSpeed`

The maximum speed of the network link, in megabits per second (Mbps).

### `LinkState`

A [ISCSI_NIC_LINKSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsicfg/ne-iscsicfg-iscsi_nic_linkstate) enumeration value that indicates whether the port is connected to the network or not.

### `MaxFrameSize`

The maximum frame size, in bytes.

### `MacAddress`

The Ethernet MAC address of the port.

## Remarks

The WMI tool suite automatically generates a declaration of the MSiSCSI_NICConfig structure when it compiles the [MSiSCSI_NICConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-nicconfig-wmi-class) in *Config.mof*.

Initiators are *not* required to implement the MSiSCSI_NICConfig class.

Initiators that implement the MSiSCSI_NICConfig class should create one instance of the class for each network port on the adapter.

Initiators should register each instance of the MSiSCSI_NICConfig class by using the name of the physical device object (PDO) for the corresponding network port. It is optional that you implement this class.

## See also

[ISCSI_NIC_LINKSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsicfg/ne-iscsicfg-iscsi_nic_linkstate)

[MSiSCSI_NICConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-nicconfig-wmi-class)