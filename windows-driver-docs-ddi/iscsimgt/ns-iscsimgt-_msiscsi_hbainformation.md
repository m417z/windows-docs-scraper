# _MSiSCSI_HBAInformation structure

## Description

The MSiSCSI_HBAInformation structure is used by storage miniport drivers to report information about the host bus adapters (HBAs) that they manage to the iSCSI initiator service.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID).

### `IntegratedTCPIP`

A Boolean value that indicates if the Windows TCP/IP stack manages TCP/IP traffic for the HBA. If this member is **TRUE**, the Windows TCP/IP stack manages TCP/IP traffic for the HBA. If this member is **FALSE**, the Windows TCP/IP stack does not manage TCP/IP traffic for the HBA. A miniport driver for an adapter with its own TCP/IP stack should set this member to **FALSE**.

### `RequiresBinaryIpAddresses`

A Boolean value that indicates whether the miniport driver for the HBA instructs the iSCSI initiator service to perform DNS lookup and provide the HBA with binary IP addresses. If this member is **TRUE**, the miniport driver for the HBA instructs the iSCSI initiator service to perform DNS lookup and provide the HBA with binary IP addresses. For the iSCSI initiator service to honor this request, the HBA must be on the same network as the Windows TCP/IP stack. If **RequiresBinaryIpAddresses** is **FALSE**, the HBA and its miniport driver have direct access to DNS.

### `VersionMin`

The earliest version of the iSCSI specification that the HBA and its miniport driver support.

### `VersionMax`

The most recent version of the iSCSI specification that the HBA and its miniport driver support.

### `MultifunctionDevice`

A Boolean value that indicates whether the HBA is a multifunction device. If this member is **TRUE**, the HBA is a multifunction device, and it exposes a netcard interface. If this member **FALSE**, the HBA is not a multifunction device.

### `CacheValid`

A Boolean value that indicates if the adapter caches are value. If this member is **TRUE**, the adapter caches are valid. If this member is **FALSE**, the caches are invalid or the adapter does not cache data.

### `NumberOfPorts`

The number of ports (or TCP/IP addresses on the adapter).

### `Status`

The current status of HBA. This member can hold any of the following values:

| Status | Meaning |
| --- | --- |
| ISCSI_HBA_STATUS_WORKING | The HBA is functioning normally. |
| ISCSI_HBA_STATUS_DEGRADED | The HBA is functioning in a degraded state of operation. |
| ISCSI_HBA_STATUS_CRITICAL | The HBA is in a critical state and might fail at any moment. |
| ISCSI_HBA_STATUS_FAILED | The HBA is not functioning at all. |

### `FunctionalitySupported`

A bitwise OR of the flags that define the functionality that the HBA supports. The following table describes the possible flags.

| Flags | Meaning |
| --- | --- |
| ISCSI_HBA_PRESHARED_KEY_CACHE | The host bus adapter (HBA) supports an onboard cache for a preshared key. |
| ISCSI_HBA_ISCSI_AUTHENTICATION_CACHE | The HBA supports an onboard cache for CHAP secrets. |
| ISCSI_HBA_IPSEC_TUNNEL_MODE | The HBA supports IPsec tunnel mode. |
| ISCSI_HBA_CHAP_VIA_RADIUS | The HBA supports the Remote Authentication Dial-In User Service (RADIUS) attributes of the challenge handshake authentication protocol (CHAP). |
| ISCSI_HBA_ISNS_DISCOVERY | The HBA supports iSNS discovery. |
| ISCSI_HBA_SLP_DISCOVERY | The HBA supports SLP discovery. |

### `GenerationalGuid`

The generational GUID. This GUID is the GUID value that the [SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid) method in the [MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class) last set.

### `MaxCDBLength`

The maximum CDB length, in bytes, that the HBA supports.

### `BiDiScsiCommands`

A Boolean value that indicates if the HBA supports bidirectional SCSI commands. If this member is **TRUE**, the HBA supports bidirectional SCSI commands. If this member is **FALSE**, the HBA does not support bidirectional commands.

### `VendorID`

The manufacturer of the HBA.

### `VendorModel`

A string that specifies the model of the HBA. The manufacturer defines this string.

### `VendorVersion`

A string that specifies the version of the HBA. The manufacturer defines this string.

### `FirmwareVersion`

A string that specifies the version of the firmware in the HBA. The manufacturer defines this string.

### `AsicVersion`

A string that specifies the Asic version. The manufacturer defines this string.

### `OptionRomVersion`

A string that specifies the option ROM version of the HBA. The manufacturer defines this string.

### `SerialNumber`

A string that specifies the serial number of the HBA. The manufacturer defines this string.

### `DriverName`

A string that specifies the name of the driver for the HBA.

## Remarks

You must implement this class.

## See also

[MSiSCSI_HBAInformation WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-hbainformation-wmi-class)

[MSiSCSI_Operations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-operations-wmi-class)

[SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid)