# _AVC_SUBUNIT_ADDR_SPEC structure

## Description

The AVC_SUBUNIT_ADDR_SPEC structure is used with virtual instances of *avc.sys* to describe virtual subunit addresses.

## Members

### `Flags`

The flags extend the operation in the following ways:

| Flag | Meaning |
| --- | --- |
| AVC_SUBUNIT_ADDR_PERSISTENT | Makes the change persistent (in the registry) so on reboot the virtual device instances are automatically enumerated. |
| AVC_SUBUNIT_ADDR_TRIGGERBUSRESET | Informs Device Manager that the PDO list has changed. This causes a 1394 bus reset, which notifies devices on the 1394 bus that the topology has changed. This flag is normally set, unless there are several different subunit types to enable at the same time. The IOCTL_AVC_BUS_RESET control code performs the equivalent bus reset operation. |

### `SubunitAddress`

A Subunit Address encoded according to Section 5.3.3 of the AV/C Digital Interface Command Set General Specification, Rev 3.0. The ID part (**SubunitAddress**[0] & 0x7) represents the max ID (not the count of subunits), so to enumerate a single tuner subunit, you would specify 0x28 (0x5 << 3). This struct supports extended subunit addresses (just allocate a bigger struct and pass the actual length with the IOCTL).

## See also

[IOCTL_AVC_BUS_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ni-avc-ioctl_avc_bus_reset)