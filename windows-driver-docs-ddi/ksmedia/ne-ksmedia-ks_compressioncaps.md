# KS_CompressionCaps enumeration

## Description

The KS_CompressionCaps enumeration defines compression capabilities of a device.

## Constants

### `KS_CompressionCaps_CanQuality`

The video compressor supports quality settings.

### `KS_CompressionCaps_CanCrunch`

The video compressor can compress the video to a specified data rate. If a minidriver supports this capability, the **dwBitRate** member of the [KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader) structure specifies the default data rate.

### `KS_CompressionCaps_CanKeyFrame`

The video compressor supports a user-specified key-frame rate.

### `KS_CompressionCaps_CanBFrame`

The video compressor supports a user-specified P frame interval. The frames that occur between the key frames and P frames are bidirectional (B) frames.

### `KS_CompressionCaps_CanWindow`

The video compressor supports a user-specified window size (that is, the number of frames whose average size cannot exceed the specified data rate).

## See also

[KSPROPERTY_VIDEOCOMPRESSION_GETINFO_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videocompression_getinfo_s)

[KS_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader)