# VSS_DIFF_VOLUME_PROP structure

## Description

The **VSS_DIFF_VOLUME_PROP** structure
describes a shadow copy storage area volume.

## Members

### `m_pwszVolumeName`

The shadow copy storage area volume name, in **\\\\?\\***Volume***{***GUID***}\\** format.

### `m_pwszVolumeDisplayName`

Points to a null-terminated Unicode string that can be displayed to a user, for example
*C***:\\**, for the shadow copy storage area volume.

### `m_llVolumeFreeSpace`

Free space, in bytes, on the shadow copy storage area volume.

### `m_llVolumeTotalSpace`

Total space, in bytes, on the shadow copy storage area volume.

## See also

[VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396)