# KSNODEPROPERTY_AUDIO_CHANNEL structure

## Description

The KSNODEPROPERTY_AUDIO_CHANNEL structure specifies a property of a channel in a node.

## Members

### `NodeProperty`

Specifies both the target node and the property to get or set. This member is a structure of type [KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty).

### `Channel`

Specifies a channel number. This member identifies the channel that is to be controlled. Given a stream with *n* channels, the channels are numbered 0 to *n*-1. When a channel number of -1 (0xFFFFFFFF) is specified, the level applies to the entire stream.

It is important to note that the standard USB audio specification provides a mechanism that allows audio drivers that support the master channel control feature, to apply channel-specific information to an entire stream. To implement this mechanism, the USB audio driver must set the channel number to zero (0). Therefore, when a USB audio driver sets the channel number to -1, there is no guarantee that the property information will be applied to the entire stream.

### `Reserved`

Reserved for internal use by operating system. Do not use.

## See also

[KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty)

[KSPROPERTY_AUDIOENGINE_VOLUMELEVEL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-volumelevel)