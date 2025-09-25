# IMAPI_MEDIA_PHYSICAL_TYPE enumeration

## Description

Defines values for the currently known media types supported by IMAPI.

## Constants

### `IMAPI_MEDIA_TYPE_UNKNOWN:0`

The disc recorder contains an unknown media type or the recorder is empty.

### `IMAPI_MEDIA_TYPE_CDROM:0x1`

The drive contains CD-ROM or CD-R/RW media.

### `IMAPI_MEDIA_TYPE_CDR:0x2`

The drive contains write once (CD-R) media.

### `IMAPI_MEDIA_TYPE_CDRW:0x3`

The drive contains rewritable (CD-RW) media.

### `IMAPI_MEDIA_TYPE_DVDROM:0x4`

Either the DVD drive or DVD media is read-only.

### `IMAPI_MEDIA_TYPE_DVDRAM:0x5`

The drive contains DVD-RAM media.

### `IMAPI_MEDIA_TYPE_DVDPLUSR:0x6`

The drive contains write once media that supports the DVD plus format (DVD+R) .

### `IMAPI_MEDIA_TYPE_DVDPLUSRW:0x7`

The drive contains rewritable media that supports the DVD plus format (DVD+RW).

### `IMAPI_MEDIA_TYPE_DVDPLUSR_DUALLAYER:0x8`

The drive contains write once dual layer media that supports the DVD plus format (DVD+R DL).

### `IMAPI_MEDIA_TYPE_DVDDASHR:0x9`

The drive contains write once media that supports the DVD dash format (DVD-R).

### `IMAPI_MEDIA_TYPE_DVDDASHRW:0xa`

The drive contains rewritable media that supports the DVD dash format (DVD-RW).

### `IMAPI_MEDIA_TYPE_DVDDASHR_DUALLAYER:0xb`

The drive contains write once dual layer media that supports the DVD dash format (DVD-R DL).

### `IMAPI_MEDIA_TYPE_DISK:0xc`

The drive contains a media type that supports random-access writes. This media type supports hardware defect management that identifies and avoids using damaged tracks.

### `IMAPI_MEDIA_TYPE_DVDPLUSRW_DUALLAYER:0xd`

The drive contains rewritable dual layer media that supports the DVD plus format (DVD+RW DL).

### `IMAPI_MEDIA_TYPE_HDDVDROM:0xe`

The drive contains high definition read only DVD media (HD DVD-ROM).

### `IMAPI_MEDIA_TYPE_HDDVDR:0xf`

The drive contains write once high definition media (HD DVD-R).

### `IMAPI_MEDIA_TYPE_HDDVDRAM:0x10`

The drive contains random access high definition media (HD DVD-RAM).

### `IMAPI_MEDIA_TYPE_BDROM:0x11`

The drive contains read only Blu-ray media (BD-ROM).

### `IMAPI_MEDIA_TYPE_BDR:0x12`

The drive contains write once Blu-ray media (BD-R).

### `IMAPI_MEDIA_TYPE_BDRE:0x13`

The drive contains rewritable Blu-ray media (BD-RE) media.

### `IMAPI_MEDIA_TYPE_MAX:0x13`

This value is the maximum value defined in IMAPI_MEDIA_PHYSICAL_TYPE.

## Remarks

The values in the range 0x00000000..0x0000FFFF inclusive are reserved for extension by Microsoft. If third parties wish to report a media type not in this list using this enumeration (for example, if implementing [IDiscFormat2Data::get_CurrentPhysicalMediaType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_currentphysicalmediatype) to support a non-listed format) they should define values only in the range 0x00010000..0xFFFFFFFF for these media types.

## See also

[IDiscFormat2Data::get_CurrentPhysicalMediaType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_currentphysicalmediatype)