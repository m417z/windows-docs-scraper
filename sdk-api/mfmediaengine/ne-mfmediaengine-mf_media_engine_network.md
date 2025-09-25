# MF_MEDIA_ENGINE_NETWORK enumeration

## Description

Defines network status codes for the Media Engine.

## Constants

### `MF_MEDIA_ENGINE_NETWORK_EMPTY:0`

The initial state.

### `MF_MEDIA_ENGINE_NETWORK_IDLE:1`

The Media Engine has started the resource selection algorithm, and has selected a media resource, but is not using the network.

### `MF_MEDIA_ENGINE_NETWORK_LOADING:2`

The Media Engine is loading a media resource.

### `MF_MEDIA_ENGINE_NETWORK_NO_SOURCE:3`

The Media Engine has started the resource selection algorithm, but has not selected a media resource.

## See also

[IMFMediaEngine::GetNetworkState](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaengine-getnetworkstate)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)