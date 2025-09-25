# ISpatialAudioClient::ActivateSpatialAudioStream

## Description

Activates and initializes spatial audio stream using one of the spatial audio stream activation structures.

## Parameters

### `activationParams` [in]

The structure defining the activation parameters for the spatial audio stream. The **vt** field should be set to VT_BLOB and the **blob** field should be populated with a [SpatialAudioObjectRenderStreamActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ns-spatialaudioclient-spatialaudioobjectrenderstreamactivationparams) or a [SpatialAudioObjectRenderStreamForMetadataActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams).

### `riid` [in]

The UUID of the spatial audio stream interface to activate.

### `stream` [out]

A pointer to the pointer which receives the activated spatial audio interface.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

This method supports activation of the following spatial audio stream interfaces:

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamForMetadata](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectrenderstreamformetadata)

#### Examples

```cpp
Microsoft::WRL::ComPtr<ISpatialAudioClient> spatialAudioClient;

// Activate ISpatialAudioClient on the desired audio-device
hr = defaultDevice->Activate(__uuidof(ISpatialAudioClient), CLSCTX_INPROC_SERVER, nullptr, (void**)&spatialAudioClient);

hr = spatialAudioClient->IsAudioObjectFormatSupported(&format);

// Create the event that will be used to signal the client for more data
HANDLE bufferCompletionEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

SpatialAudioObjectRenderStreamActivationParams streamParams;
streamParams.ObjectFormat = &format;
streamParams.StaticObjectTypeMask = ChannelMask_Stereo;
streamParams.MinDynamicObjectCount = 0;
streamParams.MaxDynamicObjectCount = 0;
streamParams.Category = AudioCategory_SoundEffects;
streamParams.EventHandle = bufferCompletionEvent;
streamParams.NotifyObject = nullptr;

PROPVARIANT activationParams;
PropVariantInit(&activationParams);
activationParams.vt = VT_BLOB;
activationParams.blob.cbSize = sizeof(streamParams);
activationParams.blob.pBlobData = reinterpret_cast<BYTE *>(&streamParams);

Microsoft::WRL::ComPtr<ISpatialAudioObjectRenderStream> spatialAudioStream;
hr = spatialAudioClient->ActivateSpatialAudioStream(&activationParams, __uuidof(spatialAudioStream), (void**)&spatialAudioStream);

```

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)

[SpatialAudioObjectRenderStreamActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ns-spatialaudioclient-spatialaudioobjectrenderstreamactivationparams)

[SpatialAudioObjectRenderStreamForMetadataActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams)