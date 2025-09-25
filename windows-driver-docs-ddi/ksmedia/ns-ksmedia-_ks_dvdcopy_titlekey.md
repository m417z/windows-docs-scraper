## Description

The KS_DVDCOPY_TITLEKEY structure is used to describe the title key information for the DVD copyright protection authentication process.

## Members

### `KeyFlags`

Title key flags settings that provide Copyrighted Material flag (CPM), Copy Guard Management System (CGMS) and Copyright Protection System (CP_SEC) copyright protection flags from the DVD drive. The following CGMS flags are defined:

| Flag | Meaning |
|---|---|
| KS_DVD_CGMS_RESERVED_MASK | Specifies the mask of all defined CPM, CGMS and CP_SEC flags (that is, all the other flags listed here). |
| KS_DVD_CGMS_COPY_PROTECT_MASK | Specifies the mask of all defined CGMS flags. |
| KS_DVD_CGMS_COPY_PERMITTED | Indicates that the content protected by CGMS can be copied. |
| KS_DVD_CGMS_COPY_ONCE | Indicates that the content protected by CGMS can be copied only a single time. As part of the copy process, this flag should be cleared, and the KS_DVD_CGMS_NO_COPY flags must be set to prevent subsequent copying. |
| KS_DVD_CGMS_NO_COPY | Indicates that the content protected by CGMS cannot be copied. |
| KS_DVD_COPYRIGHT_MASK | Specifies the mask of all defined CPM flags (KS_DVD_NOT_COPYRIGHTED and KS_DVD_COPYRIGHTED). |
| KS_DVD_NOT_COPYRIGHTED | Indicates that the content marked by CPM is not copyrighted. |
| KS_DVD_COPYRIGHTED | Indicates that the content marked by CPM is copyrighted. |
| KS_DVD_SECTOR_PROTECT_MASK | The mask of all defined sector protection flags. |
| KS_DVD_SECTOR_NOT_PROTECTED | Indicates that the sector is not protected (encrypted). |
| KS_DVD_SECTOR_PROTECTED | Indicates that the sector is protected (encrypted). |

### `ReservedNT`

Reserved. Do not use.

### `TitleKey`

Specifies the current title key.

### `Reserved`

Reserved. Do not use.

## Remarks

The KS_DVDCOPY_TITLEKEY structure is used by the [KSPROPERTY_DVDCOPY_TITLE_KEY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-title-key) property.

For more information, see [DVD Copyright Protection](https://learn.microsoft.com/windows-hardware/drivers/stream/dvd-copyright-protection).

## See also

[KSPROPERTY_DVDCOPY_TITLE_KEY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-dvdcopy-title-key)