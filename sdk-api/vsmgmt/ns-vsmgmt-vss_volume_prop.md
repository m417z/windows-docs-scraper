# VSS_VOLUME_PROP structure

## Description

The **VSS_VOLUME_PROP** structure contains the
properties of a shadow copy source volume.

## Members

### `m_pwszVolumeName`

The volume name, in \\?\*Volume*{*GUID*}\ format.

### `m_pwszVolumeDisplayName`

A pointer to a null-terminated Unicode string that contains the shortest mount
point that can be displayed to the user. The mount point can be a drive letter, for example, C:\, or a mounted folder, for example, C:\WriterData\Archive.

## See also

[VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396)

[Volume Shadow Copy API Structures](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-structures)