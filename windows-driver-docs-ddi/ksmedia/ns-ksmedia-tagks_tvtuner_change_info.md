## Description

The **KS_TVTUNER_CHANGE_INFO** structure provides vertical blanking interval (VBI) codecs with information about the currently tuned channel.

## Members

### `dwFlags`

Specifies flags indicating the status of the tuning operation. This member must be set to one of the following values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KS_TVTUNER_CHANGE_BEGIN_TUNE | Indicates that a tuning operation has begun. VBI codecs should stop decoding at this time, because the video signal may become corrupted. |
| KS_TVTUNER_CHANGE_END_TUNE | Indicates completion of a tuning operation. VBI codecs should resume decoding. |

### `dwCountryCode`

Specifies the country code in use. This corresponds to the International Telecommunications Unit (ITU) long distance dialing code.

### `dwAnalogVideoStandard`

Specifies the current analog video standard. This member should be set to a value from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

### `dwChannel`

Specifies the current channel number.

## Remarks

A packet containing a KS_TVTUNER_CHANGE_INFO structure normally originates at a TV tuner filter, and is propagated through any crossbars to an analog video decoder capture filter. The capture filter in turn must propagate this packet to downstream VBI codecs as part of a VBI media sample.

## See also

[KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)