# KS_VIDEODECODER_FLAGS enumeration

## Description

The KS_VIDEODECODER_FLAGS enumeration defines video decoder capabilities.

## Constants

### `KS_VIDEODECODER_FLAGS_CAN_DISABLE_OUTPUT`

The decoder can translate its output lines. Video decoders that use a video port use this flag.

### `KS_VIDEODECODER_FLAGS_CAN_USE_VCR_LOCKING`

The video decoder can alter its phase locked loop (PLL) timings to lock on to noisy signals. This flag typically is used when the video source is a VCR that introduces variability in the vertical and horizontal sync timing.

### `KS_VIDEODECODER_FLAGS_CAN_INDICATE_LOCKED`

The video decoder can distinguish whether it has locked to an incoming analog video signal.

## See also

[KSPROPERTY_VIDEODECODER_CAPS_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videodecoder_caps_s)