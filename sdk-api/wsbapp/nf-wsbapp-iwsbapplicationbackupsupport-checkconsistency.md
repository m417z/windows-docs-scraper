# IWsbApplicationBackupSupport::CheckConsistency

## Description

Checks the consistency of the VSS writer's components in the shadow copy after shadow copies are created
for the volumes to be backed up.

## Parameters

### `wszWriterMetadata` [in, optional]

A string that contains the VSS writer's metadata.

### `wszComponentName` [in, optional]

The name of the component or component set to be checked. This should match the name in the metadata that
the *wszWriterMetadata* parameter points to.

### `wszComponentLogicalPath` [in, optional]

The [logical path](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components) of the component or
component set to be checked. This should match the logical path in the metadata that the
*wszWriterMetadata* parameter points to.

### `cVolumes` [in]

The number of shadow copy volumes. The value of this parameter can range from 0 to
**MAX_VOLUMES**.

### `rgwszSourceVolumePath` [in, optional]

A pointer to an array of volume **GUID** paths, one for each of the source
volumes. The format of a volume **GUID** path is
"\\?\*Volume*{*GUID*}\".

### `rgwszSnapshotVolumePath` [in, optional]

A pointer to an array of volume **GUID** paths, one for each of the shadow copy
volumes. The consistency check is performed on these volumes.

### `ppAsync` [out, optional]

A pointer to a variable that will receive an
[IWsbApplicationAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationasync) interface pointer that can be
used to retrieve the status of the consistency-check operation. This pointer can be **NULL**
if a consistency check is not required. When the consistency-check operation is complete, the
[IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method must be called to free all
resources held by the **IWsbApplicationAsync** object.

## Return value

Returns **S_OK** if successful, or an error value otherwise. Possible return values
include the following.

## Remarks

The application should perform the consistency check as an asynchronous operation, because it might be a
long-running operation. The application should check the consistency of the files for the VSS writer's components in
the shadow copy. These files will be backed up as part of the backup operation. If the consistency check fails, the
backup of the components will still succeed, but recovery of the components will not be allowed from the resulting
backup set.

## See also

[IWsbApplicationBackupSupport](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationbackupsupport)