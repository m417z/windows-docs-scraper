# METAHEADER structure

## Description

The **METAHEADER** structure contains information about a Windows-format metafile.

## Members

### `mtType`

Specifies whether the metafile is in memory or recorded in a disk file. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 1 | Metafile is in memory. |
| 2 | Metafile is in a disk file. |

### `mtHeaderSize`

The size, in words, of the metafile header.

### `mtVersion`

The system version number. The version number for metafiles that support device-independent bitmaps (DIBs) is 0x0300. Otherwise, the version number is 0x0100.

### `mtSize`

The size, in words, of the file.

### `mtNoObjects`

The maximum number of objects that exist in the metafile at the same time.

### `mtMaxRecord`

The size, in words, of the largest record in the metafile.

### `mtNoParameters`

Reserved.

## See also

[METARECORD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metarecord)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)