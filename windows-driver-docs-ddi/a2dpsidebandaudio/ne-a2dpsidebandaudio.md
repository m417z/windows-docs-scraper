## Description

Identifies the SIDEBANDAUDIO_PARAMS_SET_A2DP parameter.

## Constants

### `SIDEBANDAUDIO_PARAM_A2DP_CODECS`

Supported codecs information

The value is a sequence of Media Codec Capabilities fields as defined in table 8.52, section 8.21.5 of AVDTP 1.3. Also, see A2DP 1.3.1 section 4.2.5 and section 4.7.2 for additional information.

`SIDEBANDAUDIO_PARAM_A2DP_CODECS = 1,`

### `SIDEANDAUDIO_PARAM_A2DP_CONFIGURED_CODEC`

Configured codec information

The value is a single Media Codec Capabilities field as defined in table 8.52, section 8.21.5 of AVDTP 1.3.
Also, see A2DP 1.3.1 section 4.2.5 and section 4.7.2 for additional information.

`SIDEANDAUDIO_PARAM_A2DP_CONFIGURED_CODEC = 2,`

## Remarks

## See also

[A2DPSidebandAudio](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/)

[SET_VENDOR_ID_TO_PARAMSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/nf-a2dpsidebandaudio-set_vendor_id_to_paramset)

[GET_VENDOR_ID_FROM_PARAMSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/a2dpsidebandaudio/nf-a2dpsidebandaudio-get_vendor_id_from_paramset)