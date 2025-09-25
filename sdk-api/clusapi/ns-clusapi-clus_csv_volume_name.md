# CLUS_CSV_VOLUME_NAME structure

## Description

Represents the name of a cluster shared volume (CSV).

## Members

### `VolumeOffset`

The physical offset, in bytes, of the data on the CSV.

### `szVolumeName`

A Unicode string that contains the volume name of the CSV. The string has a terminating null character. The name provided can be either the cluster-assigned friendly name or the volume **GUID** path of the form "\\?\Volume{xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}\".

### `szRootPath`

The root path of the CSV.

## See also

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)