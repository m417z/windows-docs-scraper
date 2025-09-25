# CVssWriter::GetSnapshotDeviceName

## Description

The **GetSnapshotDeviceName** method
returns the name of the device that hosts the shadow copy of the specified volume or file share. This method allows writers to support
[auto-recover](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-a) shadow copies, and
can only be called during the processing of the
[OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method.

## Parameters

### `wszOriginalVolume` [in]

Name of the original volume or the UNC path of the original file share that contains data used for the current shadow copy set. The name of the volume must be in one
of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)
* A UNC path that specifies a remote file share, for example, \\Clusterx\Share1\

### `ppwszSnapshotDevice` [out]

The address of a **LPCWSTR** that will receive a pointer to the device name of the
shadow copy.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the shadow copy volume name. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **VSS_E_BAD_STATE** | The call was not made during the [PostSnapshot event](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p). |
| **VSS_E_OBJECT_NOT_FOUND** | The *wszOriginalVolume* parameter is not one of the volumes or file shares in the shadow copy set. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

To get the name of the original volume for the *wszOriginalVolume* parameter, first call the [CVssWriter::GetCurrentVolumeCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumecount) method to query the number of volumes in the shadow copy set. Then call the [CVssWriter::GetCurrentVolumeArray](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumearray) method to enumerate the original names of the volumes in the shadow copy set.