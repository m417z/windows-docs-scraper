# ISCSI_ENCRYPTION_TYPES enumeration

## Description

The ISCSI_ENCRYPTION_TYPES enumeration indicates the type of encryption that is supported.

## Constants

### `ISCSI_ENCRYPT_NONE`

No type of encryption is supported.

### `ISCSI_ENCRYPT_3DES_HMAC_SHA1`

The initiator or target supports triple data encryption standard (DES), hashed message authentication code (HMAC), and the secure hash algorithm, version 1.

### `ISCSI_ENCRYPT_AES_CTR`

The initiator or target supports advanced encryption standard (AES) counter mode (CTR).

## Remarks

The ISCSI_ENCRYPTION_TYPES enumeration is used with the [MSiSCSI_SecurityCapabilities WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securitycapabilities-wmi-class).

## See also

[MSiSCSI_SecurityCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsicfg/ns-iscsicfg-_msiscsi_securitycapabilities)

[MSiSCSI_SecurityCapabilities WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securitycapabilities-wmi-class)