# eAVEncH264VProfile enumeration

## Description

Specifies an H.264 video profile.

## Constants

### `eAVEncH264VProfile_unknown:0`

The profile is unknown or not specified.

### `eAVEncH264VProfile_Simple:66`

Simple profile.

### `eAVEncH264VProfile_Base:66`

Baseline profile.

### `eAVEncH264VProfile_Main:77`

Main profile.

### `eAVEncH264VProfile_High:100`

High profile.

### `eAVEncH264VProfile_422:122`

High 4:2:2 profile.

### `eAVEncH264VProfile_High10:110`

High 10 profile.

### `eAVEncH264VProfile_444:244`

High 4:4:4 profile.

### `eAVEncH264VProfile_Extended:88`

Extended profile.

### `eAVEncH264VProfile_ScalableBase:83`

Scalable base profile. H.264 extension.

### `eAVEncH264VProfile_ScalableHigh:86`

Scalable high profile. H.264 extension.

### `eAVEncH264VProfile_MultiviewHigh:118`

Multiview high profile. H.264 extension.

### `eAVEncH264VProfile_StereoHigh:128`

Stereo high profile. H.264 extension.

### `eAVEncH264VProfile_ConstrainedBase:256`

Constrained base profile. H.264 extension.

### `eAVEncH264VProfile_UCConstrainedHigh:257`

Constrained high profile. H.264 extension.

### `eAVEncH264VProfile_UCScalableConstrainedBase:258`

UC Constrained base profile. H.264 extension.

### `eAVEncH264VProfile_UCScalableConstrainedHigh:259`

UC Constrained high profile. H.264 extension.

## Remarks

These values are used with the [MF_MT_MPEG2_PROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-mpeg2-profile-attribute) attribute.

These values are also used with [H.264 UVC 1.5 camera encoders](https://learn.microsoft.com/windows/desktop/medfound/camera-encoder-h264-uvc-1-5).

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)