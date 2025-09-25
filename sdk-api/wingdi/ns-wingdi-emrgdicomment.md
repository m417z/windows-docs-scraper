# EMRGDICOMMENT structure

## Description

The **EMRGDICOMMENT** structure contains application-specific data. This enhanced metafile record is only meaningful to applications that know the format of the data and how to utilize it. This record is ignored by graphics device interface (GDI) during playback of the enhanced metafile.

## Members

### `emr`

The base structure for all record types.

### `cbData`

Size of data buffer, in bytes.

### `Data`

Application-specific data.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)