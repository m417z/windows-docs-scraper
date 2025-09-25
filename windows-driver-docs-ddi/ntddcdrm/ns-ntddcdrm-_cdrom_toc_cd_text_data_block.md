# _CDROM_TOC_CD_TEXT_DATA_BLOCK structure

## Description

This structure contains CD text descriptor data used in conjunction with the data in the [CDROM_TOC_CD_TEXT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data) structure.

## Members

### `PackType`

Indicates the type of pack data, as follows:

| Type | Description |
| ---- | ----------- |
| CDROM_CD_TEXT_PACK_ALBUM_NAME | Title of album or track. |
| CDROM_CD_TEXT_PACK_PERFORMER | Names of the performers (in ASCII). |
| CDROM_CD_TEXT_PACK_SONGWRITER | Names of the songwriters (in ASCII). |
| CDROM_CD_TEXT_PACK_COMPOSER | Names of the composers (in ASCII). |
| CDROM_CD_TEXT_PACK_ARRANGER | Names of the arrangers (in ASCII). |
| CDROM_CD_TEXT_PACK_MESSAGES | Messages from content provider and/or artist (in ASCII). |
| CDROM_CD_TEXT_PACK_DISC_ID | Disc identification information. |
| CDROM_CD_TEXT_PACK_GENRE | Genre identification and information. |
| CDROM_CD_TEXT_PACK_TOC_INFO | Table of contents information. |
| CDROM_CD_TEXT_PACK_TOC_INFO2 | Second table of contents information. |
| CDROM_CD_TEXT_PACK_UPC_EAN | UPC/EAN code of the album and ISRC code of each track. |
| CDROM_CD_TEXT_PACK_SIZE_INFO | Size information for the block.

### `TrackNumber`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `ExtensionFlag`

Must be set to zero.

### `SequenceNumber`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `CharacterPosition`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `BlockNumber`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `Unicode`

Indicates, when set to 1, that the text is stored in Unicode format.

### `Text`

Contains text descriptor data in the form of 8-bit ASCII characters.

### `WText`

Contains text descriptor data in the form of 16-bit (wide) characters.

### `CRC`

Contains the cyclic redundancy check.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[CDROM_TOC_CD_TEXT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_cd_text_data)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)