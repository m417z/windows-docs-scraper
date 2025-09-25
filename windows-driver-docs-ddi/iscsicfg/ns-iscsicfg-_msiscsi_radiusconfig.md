# _MSiSCSI_RADIUSConfig structure

## Description

The MSiSCSI_RADIUSConfig structure provides information that the initiator requires to use the remote authentication dial-in user service (RADIUS).

## Members

### `UseRADIUSForCHAP`

A Boolean value that indicates whether the initiator should use RADIUS for authentication during the challenge handshake of the challenge handshake authentication protocol (CHAP). If this member is **TRUE**, the initiator should use RADIUS for authentication during the challenge handshake of CHAP. If this member is **FALSE**, the initiator is not required to use RADIUS.

### `SharedSecretSizeInBytes`

The size, in bytes, of shared secret for use with RADIUS servers.

### `RADIUSServer`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that specifies a fixed address for the RADIUS server. The ISCSI_IP_Address structure defines the IP address in a way that is independent of the version of the IP protocol in use.

### `BackupRADIUSServer`

A ISCSI_IP_Address structure that specifies a fixed addresses for a backup RADIUS server.

### `Reserved`

Reserved for Microsoft use only. Set this member to zero.

### `SharedSecret`

A variable-length array that contains a shared secret. The initiator uses this shared secret to authenticate primary and backup RADIUS servers.

## Remarks

Initiators use RADIUS servers to perform authentication during the challenge handshake of CHAP.

The WMI tool suite automatically generates a declaration of the MSiSCSI_RADIUSConfig structure when it compiles the [MSiSCSI_RADIUSConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-radiusconfig-wmi-class) in *Config.mof*.

Initiators that support using RADIUS for CHAP authentication must implement the MSiSCSI_RADIUSConfig class.

Initiators should use RADIUS whenever possible, because RADIUS allows the centralized management of CHAP credentials.

Initiators should register each instance of the MSiSCSI_RADIUSConfig class using the name of the physical device object (PDO) for the HBAYou must implement this class if the adapter supports authentication via RADIUS.

## See also

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[MSiSCSI_RADIUSConfig WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-radiusconfig-wmi-class)