# WPCFLAG_IM_FEATURE enumeration

## Description

Indicates information about the features accessed during an instant messaging interaction.

## Constants

### `WPCFLAG_IM_FEATURE_NONE:0x00`

No instant messaging features were used.

### `WPCFLAG_IM_FEATURE_VIDEO:0x01`

The video feature was used during the instant messaging session.

### `WPCFLAG_IM_FEATURE_AUDIO:0x02`

The audio feature was used during the instant messaging session.

### `WPCFLAG_IM_FEATURE_GAME:0x04`

The game feature was used during the instant messaging session.

### `WPCFLAG_IM_FEATURE_SMS:0x08`

The short message service feature was used during the instant messaging session.

### `WPCFLAG_IM_FEATURE_FILESWAP:0x10`

Files were swapped during the instant messaging session.

### `WPCFLAG_IM_FEATURE_URLSWAP:0x20`

URL or website locations were swapped during the instant messaging session.

### `WPCFLAG_IM_FEATURE_SENDING:0x80000000`

The top bit means sending or receiving.

### `WPCFLAG_IM_FEATURE_ALL:0xFFFFFFFF`

All features were used during the instant messaging session