# _BAND_MANAGEMENT_CAPABILITIES structure

## Description

The **BAND_MANAGEMENT_CAPABILITIES** structure contains the security capabilities available for a storage device. This structure is returned in the system buffer by the [IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities) request.

## Members

### `StructSize`

The size of this structure in bytes. Set to **sizeof**(BAND_MANAGEMENT_CAPABILITIES).

### `Capabilities`

Security capability flags for a storage device. This is a bitwise OR value of the following flags.

| Value | Meaning |
| --- | --- |
| **CAPS_ACTIVATED** | If set, the capability members of this structure are available. Otherwise, the remaining members of this structure are not valid. |
| **CAPS_BANDCROSSING_SUPPORTED** | The storage device supports reads and writes across multiple bands. If this flag is not set, single reads or writes spanning multiple bands are divided into multiple IO requests for a device. |
| **CAPS_SID_SECURED** | SID authority is secured. If set, the default SID pin cannot be used to modify the security configuration of the storage device. |

### `KeyProtectionMechanism`

The mechanism used to protect the media keys. This member is set to one of the following.

| Value | Meaning |
| --- | --- |
| **0** | Keys are not protected. |
| **MEDIAKEY_PROTECTEDBY_VENDORSCHEME** | Keys are protected by a vendor-supplied method. Do not use. This option is not supported. |
| **MEDIAKEY_PROTECTEDBY_AUTHKEY** | Keys are encrypted by keys derived from band authentication keys. Key derivation results in negligible entropy loss from the band authentication data. |

### `MinAuthKeyLength`

The minimum length, in bytes, of the band authentication or erase keys accepted by the storage device.

### `MaxAuthKeyLength`

The maximum length, in bytes, of the band authentication or erase keys accepted by the storage device.

### `MaxBandCount`

The maximum number of simultaneous bands configured in the storage device. This includes the global band.

### `MaxSimultaneousReencryptionCount`

The number of simultaneous band re-encryptions the hardware on the device supports. If this member is 0, hardware-driven band re-encryptions are not supported.

### `BandMetadataSize`

The size, in bytes, of the per band metadata store.

## Remarks

If **CAPS_ACTIVATED** is not set in **Capabilities**, security functionality can be activated with the [IOCTL_EHSTOR_BANDMGMT_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_activate) request.

## See also

[IOCTL_EHSTOR_BANDMGMT_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_activate)

[IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities)