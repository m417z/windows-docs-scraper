# IMAPI_CD_SECTOR_TYPE enumeration

## Description

Defines the sector types that can be written to CD media.

## Constants

### `IMAPI_CD_SECTOR_AUDIO:0`

With this sector type, Audio data has 2352 bytes per sector/frame. This can be broken down into 588 contiguous samples, each sample being four bytes. The layout of a single sample matches the 16-bit stereo 44.1KHz WAV file data. This type of sector has no additional error correcting codes.

### `IMAPI_CD_SECTOR_MODE_ZERO:0x1`

With this sector type, user data has 2336 bytes per sector/frame. This seldom-used sector type contains all zero data, and is almost never seen in media today.

### `IMAPI_CD_SECTOR_MODE1:0x2`

With this sector type, user data has 2048 bytes per sector/frame. Mode1 data is the most common data form for pressed CD-ROM media. This data type also provides the greatest level of ECC/EDC among the standard sector types.

### `IMAPI_CD_SECTOR_MODE2FORM0:0x3`

With this sector type, user data has 2336 bytes per sector/frame. All Mode 2 sector types are also known as "CD-ROM XA" modes, which allows mixing of audio and data tracks on a single disc. This sector type is also known as Mode 2 "Formless", is considered deprecated, and is very seldom used.

### `IMAPI_CD_SECTOR_MODE2FORM1:0x4`

With this sector type, user data has 2048 bytes per sector/frame. All Mode 2 sector types are also known as "CD-ROM XA" modes, which allows mixing of audio and data tracks on a single disc.

### `IMAPI_CD_SECTOR_MODE2FORM2:0x5`

With this sector type, user data has 2336 bytes per sector/frame, of which the final four bytes are an optional CRC code (zero if not used). All Mode 2 sector types are also known as "CD-ROM XA" modes, which allows mixing of audio and data tracks on a single disc. This sector type is most often used when writing VideoCD discs.

### `IMAPI_CD_SECTOR_MODE1RAW:0x6`

With this sector type, user data has 2352 bytes per sector/frame. This is pre-processed Mode1Cooked data sectors, with sector header, ECC/EDC, and scrambling already added to the data stream.

### `IMAPI_CD_SECTOR_MODE2FORM0RAW:0x7`

With this sector type, user data has 2352 bytes per sector/frame. This is pre-processed Mode2Form0 data sectors, with sector header, ECC/EDC, and scrambling already added to the data stream.

### `IMAPI_CD_SECTOR_MODE2FORM1RAW:0x8`

With this sector type, user data has 2352 bytes per sector/frame. This is pre-processed Mode2Form1 data sectors, with sector header, ECC/EDC, and scrambling already added to the data stream.

### `IMAPI_CD_SECTOR_MODE2FORM2RAW:0x9`

With this sector type, user data has 2352 bytes per sector/frame. This is pre-processed Mode2Form2 data sectors, with sector header, ECC/EDC, and scrambling already added to the data stream.

## Remarks

Some sector types are not compatible with other sector types within a single image. The following are typical examples of this condition:

* If the first track is audio, then all tracks must be audio.
* If the first track is Mode1, then all tracks must be Mode1.
* Only the three Mode2 (XA) sectors (Mode 2 Form 0, Mode 2 Form 1, and Mode 2 Form 2) may be mixed within a single disc image, and even then, only with other Mode 2 (XA) sector types.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)