# _MSiSCSI_DiscoveryConfig structure

## Description

The MSiSCSI_DiscoveryConfig structure contains information that indicates what methods an initiator uses to do discovery.

## Members

### `PerformiSNSDiscovery`

A Boolean value that indicates whether the initiator performs target discovery by using iSNS and a predetermined iSNS server. If this member is **TRUE**, the initiator performs target discovery by using iSNS and a predetermined iSNS server. If this member is **FALSE**, the initiator does not do discovery with iSNS.

### `PerformSLPDiscovery`

A Boolean value that indicates whether the initiator performs target discovery by using SLP. If this member is **TRUE**, the initiator performs target discovery by using SLP.

### `AutomaticiSNSDiscovery`

A Boolean value that indicates whether the initiator should automatically search for an iSNS server and then perform target discovery by using iSNS. If this member is **TRUE**, the initiator should automatically search for an iSNS server and then perform target discovery by using iSNS.

### `InitiatorName`

The default initiator name to register with the iSNS server.

### `iSNSServer`

If **AutomaticiSNSDiscovery** is **FALSE**, **iSNSServer** contains a [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that provides a fixed address of the iSNS server that is independent of the version of the IP protocol in use.

## Remarks

The WMI tool suite automatically generates a declaration of the MSiSCSI_DiscoveryConfig structure when it compiles the [MSiSCSI_DiscoveryConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-discoveryconfig-wmi-class) in *Config.mof*.

Initiators are required to implement the MSiSCSI_DiscoveryConfig class. You must implement this class.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[MSiSCSI_DiscoveryConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-discoveryconfig-wmi-class)