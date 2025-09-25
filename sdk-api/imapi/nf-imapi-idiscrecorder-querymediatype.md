# IDiscRecorder::QueryMediaType

## Description

Detects the type of media currently inserted in the recorder, if any.

## Parameters

### `fMediaType` [out]

If there is no media, both *fMediaType* and *fMediaFlags* are zero. If there is media, *fMediaType* contains one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MEDIA_CD_EXTRA** | 4 |
| **MEDIA_CD_I** | 3 |
| **MEDIA_CD_OTHER** | 5 |
| **MEDIA_CD_ROM_XA** | 2 |
| **MEDIA_CDDA_CDROM** | 1 |
| **MEDIA_SPECIAL** | 6 |

### `fMediaFlags` [out]

If there is media, this parameter contains one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MEDIA_BLANK** | 0x1 |
| **MEDIA_RW** | 0x2 |
| **MEDIA_WRITABLE** | 0x4 |

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)