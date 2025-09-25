# _DVD_COPY_PROTECT_KEY structure

## Description

The **DVD_COPY_PROTECT_KEY** structure is used in conjunction with the [IOCTL_DVD_READ_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_key) request to execute a report key command of the specified type.

## Members

### `KeyLength`

Indicates the length of the key data to be retrieved.

### `SessionId`

Indicates the DVD session ID. The Authentication Grant Identifier (AGID) for a secure Advanced Access Content System (AACS) session is a long integer in the range -1 to 3 inclusive.

### `KeyType`

Indicates the key type. The DVD device driver uses this information to determine the key format in a report key command, as defined by the *SCSI Multimedia Commands - 3 (MMC-3)* specification. A report key command either reports key data for a specified key (challenge key, bus key, title key, RPC key, or disk key), reports the state of the authentication success flag (ASF), or invalidates an authentication grant ID (AGID). See the *MMC-3* specification for further information.

### `KeyFlags`

###### This member can have any of the following values:

################

### `Parameters`

### `Parameters.FileHandle`

Pointer to the file handle for the physical device that the copy protection is being negotiated on.

### `Parameters.TitleOffset`

Contains the logical block address on the media of the title.

The upper layers of the operating system use the **FileHandle** member. The file system converts the value in **FileHandle** into a logical block address and stores the result in the **TitleOffset** member. Kernel-mode drivers use the **TitleOffset** member.

### `KeyData`

Contains the key data that was returned.

## See also

[DVD_KEY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ne-ntddcdvd-dvd_key_type)

[IOCTL_DVD_READ_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_key)