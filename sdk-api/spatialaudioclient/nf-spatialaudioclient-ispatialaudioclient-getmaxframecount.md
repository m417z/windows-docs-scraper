# ISpatialAudioClient::GetMaxFrameCount

## Description

Gets the maximum possible frame count per processing pass. This method can be used to determine the size of the source buffer that should be allocated to convey audio data for each processing pass.

## Parameters

### `objectFormat` [in]

The audio format used to calculate the maximum frame count. This should be the same format specified in the **ObjectFormat** field of the [SpatialAudioObjectRenderStreamActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ns-spatialaudioclient-spatialaudioobjectrenderstreamactivationparams) passed to [ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream).

### `frameCountPerBuffer` [out]

The maximum number of audio frames that will be processed in one pass.

## Return value

If the method succeeds, it returns S_OK.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)