# IWsbApplicationRestoreSupport::PreRestore

## Description

Performs application-specific [PreRestore](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) operations.

## Parameters

### `wszWriterMetadata` [in, optional]

A string that contains the VSS writer's metadata.

### `wszComponentName` [in, optional]

The name of the component or component set. This should match the name in the metadata that the *wszWriterMetadata* parameter points to.

### `wszComponentLogicalPath` [in, optional]

The [logical path](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components) of the component or component set. This should match the logical path in the metadata that the *wszWriterMetadata* parameter points to.

### `bNoRollForward` [in]

Set to **TRUE** if a previous point-in-time recovery operation is in progress and no application rollforward should be performed. The previous logs for the application will be deleted before the application restore operation is performed.

## Return value

Returns **S_OK** if successful, or an error value otherwise. Possible return values include the following.

## Remarks

During application restore, Windows Server Backup calls this method before restoring the files for each application component.

## See also

[IWsbApplicationRestoreSupport](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationrestoresupport)