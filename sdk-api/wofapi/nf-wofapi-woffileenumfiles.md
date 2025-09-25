# WofFileEnumFiles function

## Description

Enumerates all of the files which are compressed with a specified compression algorithm on a specified volume.

## Parameters

### `VolumeName` [in]

A full path to the volume containing the files to enumerate.

### `Algorithm` [in]

The compression algorithm to enumerate. For a list of valid compression algorithms, see [WOF_FILE_COMPRESSION_INFO_V1](https://learn.microsoft.com/windows/desktop/api/wofapi/ns-wofapi-wof_file_compression_info_v1). If this value is MAX_ULONG, files compressed with any supported compression algorithm will be returned.

### `EnumProc` [in]

The callback function for each data source. The enumeration will stop if *EnumProc* returns FALSE.

### `UserData` [in, optional]

User defined data passed to *EnumProc*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FSCTL_ENUM_EXTERNAL_BACKING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-enum-external-backing)