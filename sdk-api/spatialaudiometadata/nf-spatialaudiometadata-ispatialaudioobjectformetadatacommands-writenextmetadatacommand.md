# ISpatialAudioObjectForMetadataCommands::WriteNextMetadataCommand

## Description

Writes a metadata command to the spatial audio object, each command may only be added once per object per processing cycle. Valid commands and value lengths are defined by the metadata format specified in the [SpatialAudioObjectRenderStreamForMetadataActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams) when the [ISpatialAudioObjectRenderStreamForMetadata](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectrenderstreamformetadata) was created.

## Parameters

### `commandID` [in]

The ID of the metadata command.

### `valueBuffer` [in]

The buffer containing the value data for the metadata command.

### `valueBufferLength` [in]

The length of the *valueBuffer*.

## Return value

If the method succeeds, it returns S_OK.

## See also

[ISpatialAudioObjectForMetadataCommands](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadatacommands)