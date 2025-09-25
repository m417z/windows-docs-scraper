# _MSiSCSI_SecurityCapabilities structure

## Description

The MSiSCSI_SecurityCapabilities structure describes the security capabilities of an initiator.

## Members

### `ProtectiScsiTraffic`

A Boolean value that indicates whether the initiator can use IPsec to protect iSCSI traffic. If this member is **TRUE**, the initiator can use IPsec to protect iSCSI traffic. If **FALSE**, the initiator cannot use IPsec.

### `ProtectiSNSTraffic`

A Boolean value that indicates whether the initiator can use IPsec to protect iSNS traffic. If this member is **TRUE**, the initiator can use IPsec to protect iSNS traffic. If **FALSE**, the initiator cannot use IPsec.

### `CertificatesSupported`

A Boolean value that indicates whether the initiator supports certificates. If this member is **TRUE**, the initiator supports certificates. If this member is **FALSE**, the initiator does not support certificates.

### `EncryptionAvailableCount`

The number of encryption types that the initiator supports.

### `EncryptionAvailable`

A variable length array of [ISCSI_ENCRYPTION_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsicfg/ne-iscsicfg-iscsi_encryption_types) structures, which indicate types of encryption that the initiator supports.

## Remarks

The WMI tool suite automatically generates a declaration of the MSiSCSI_SecurityCapabilities structure when it compiles the [MSiSCSI_SecurityCapabilities WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securitycapabilities-wmi-class) in *Config.mof*.

Initiators that support IPsec must implement the MSiSCSI_SecurityCapabilities class.

Initiators must register the MSiSCSI_SecurityCapabilities class using the name of the physical device object (PDO) for the HBA. You must implement this class if the adapter supports IPsec.

## See also

[ISCSI_ENCRYPTION_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsicfg/ne-iscsicfg-iscsi_encryption_types)

[MSiSCSI_SecurityCapabilities WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securitycapabilities-wmi-class)