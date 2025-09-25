# _TRACK_INFORMATION2 structure (scsi.h)

## Description

The TRACK_INFORMATION2 structure is used to report track information.

## Members

### `Length`

The length, in bytes, of this structure.

### `TrackNumberLsb`

The least significant byte of the track number.

### `SessionNumberLsb`

The least significant byte of the session number.

### `Reserved4`

Reserved.

### `TrackMode`

The track mode. See the *SCSI-3 Multi-Media* specification for an explanation of meaning of this member.

### `Copy`

The copy bit indicates whether the track is a copy or not. If this bit is 1, the track is a copy. If it is 0, the track is not a copy.

### `Damage`

The damage bit indicates, together with the NWA_V bit, whether a write to the media is complete or not, and what sort of methods the CD-ROM class driver can use to complete the write. See the *SCSI-3 Multi-Media* specification for an explanation of how to interpret the values in the **Damage** and **NWA_V** members.

### `Reserved5`

Reserved.

### `DataMode`

The data mode. This member can have any of the following values:

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| 0x1 | The track uses data mode 1 (ISO/IEC 10149) |
| 0x2 | The track uses data mode 2 (ISO/IEC 10149 or CD-ROM XA) |
| 0xf | There is no track descriptor block, and therefore the data block type of the track is unknown. |

### `FixedPacket`

The fixed packet bit indicates, under some circumstances, when set to 1, that write operations to the track must use fixed packets. For a complete explanation of the meaning of this bit, see the *SCSI Multimedia Commands - 3 (MMC-3)* specification.

### `Packet`

The fixed packet bit indicates, under some circumstances, when set to 1, that write operations to the track must use fixed packets. For a complete explanation of the meaning of this bit, see the *SCSI Multimedia Commands - 3 (MMC-3)* specification.

### `Blank`

The blank bit, when set to 1, indicates that the track contains no written data and last recorded address field is invalid. For a complete explanation of the meaning of this bit, see the *SCSI Multimedia Commands - 3 (MMC-3)* specification.

### `ReservedTrack`

The reserved track bit, when 1, indicates that the track is reserved.

### `NWA_V`

A boolean value that indicates, when 1, that the value in **NextWritableAddress** is valid. If 0, the value in **NextWritableAddress** is invalid.

### `LRA_V`

A boolean value that indicates whether the **LastRecordedAddress** member is valid or not. If **LRA_V** is 1, the **LastRecordedAddress** member is valid. If 0, the **LastRecordedAddress** member is not valid.

### `Reserved6`

Reserved.

### `TrackStartAddress`

The starting address of the specified track.

### `NextWritableAddress`

The logical block address of the next writable user block in the track specified by the track number (**TrackNumberLsb** and **TrackNumberMsb**).

### `FreeBlocks`

The maximum number of user data blocks that are available for recording in the track.

### `FixedPacketSize`

The blocking factor. This value The fixed packet size is valid only when the Packet and the FP bits are both set to one.

### `TrackSize`

Track Size is the number of user data blocks in the track.

### `LastRecordedAddress`

### `TrackNumberMsb`

The most significant byte of the track number.

### `SessionNumberMsb`

The most significant byte of the session number.

### `Reserved7`

Reserved7