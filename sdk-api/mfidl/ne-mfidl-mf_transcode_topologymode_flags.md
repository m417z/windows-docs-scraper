# MF_TRANSCODE_TOPOLOGYMODE_FLAGS enumeration

## Description

Defines flags for the [MF_TRANSCODE_TOPOLOGYMODE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-topologymode) attribute.

## Constants

### `MF_TRANSCODE_TOPOLOGYMODE_SOFTWARE_ONLY:0`

The topology loader will exclude hardware-based transforms (such as codecs and color converters) from the topology. It will use only software transforms.

### `MF_TRANSCODE_TOPOLOGYMODE_HARDWARE_ALLOWED:1`

The topology loader may insert hardware-based transforms into the transcode topology.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)