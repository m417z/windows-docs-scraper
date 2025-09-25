# DVD_KEY_TYPE enumeration

## Description

The DVD_KEY_TYPE enumeration type is used in conjunction with the [DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key) structure to indicate a key to be read, to invalidate an authentication grant ID (AGID), and to request state information or region settings.

## Constants

### `DvdChallengeKey`

Gets a challenge key. This is used during the authentication key exchange process.

### `DvdBusKey1`

Gets the first bus key.

### `DvdBusKey2`

Gets the second bus key.

### `DvdTitleKey`

Gets a title key that is obfuscated by a bus key.

### `DvdAsf`

Gets the current state of the authentication success flag (ASF).

### `DvdSetRpcKey`

Sets the region playback contents (RPC) for the logical unit.

### `DvdGetRpcKey`

Gets the region playback contents (RPC) for the logical unit.

### `DvdDiskKey`

Gets the disc key.

### `DvdInvalidateAGID`

Invalidates the specified authentication grant ID (AGID).

## Remarks

The driver for the DVD device uses the key type specified in this enumeration type to determine the key format in a report key command, as defined by the *SCSI Multimedia Commands - 3 (MMC-3)* specification. A report key command can either report key data for a specified key (challenge key, bus key, title key, RPC key, or disc key), or the state of the ASF flag. It can also invalidate an AGID. See the *MMC-3* specification for further information.

Drivers can issue a report key command to retrieve key data by means of an [IOCTL_DVD_READ_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_key) request.

## See also

[DVD_COPY_PROTECT_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_dvd_copy_protect_key)

[IOCTL_DVD_READ_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_key)

[IOCTL_DVD_SEND_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_send_key)