# MFFOLDDOWN_MATRIX structure

## Description

Contains coefficients used to transform multichannel audio into a smaller number of audio channels. This process is called *fold-down*.

## Members

### `cbSize`

Size of the structure, in bytes.

### `cSrcChannels`

Number of source channels.

### `cDstChannels`

Number of destination channels.

### `dwChannelMask`

Specifies the assignment of audio channels to speaker positions in the transformed audio. This member is a bitwise **OR** of flags that define the speaker positions. For a list of valid flags, see [MF_MT_AUDIO_CHANNEL_MASK](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-channel-mask-attribute) attribute.

### `Coeff`

Array that contains the fold-down coefficients. The number of coefficients is **cSrcChannels**×**cDstChannels**. If the number of coefficients is less than the size of the array, the remaining elements in the array are ignored. For more information about how the coefficients are applied, see [Windows Media Audio Professional Codec Features](https://learn.microsoft.com/previous-versions/ms867218(v=msdn.10)).

## Remarks

To specify this information in the media type, set the [MF_MT_AUDIO_FOLDDOWN_MATRIX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-audio-folddown-matrix-attribute) attribute.

The ASF media source supports fold-down from six channels (5.1 audio) to two channels (stereo). It gets the information from the g_wszFold6To2Channels3 attribute in the ASF header. This attribute is documented in the Windows Media Format SDK documentation.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)