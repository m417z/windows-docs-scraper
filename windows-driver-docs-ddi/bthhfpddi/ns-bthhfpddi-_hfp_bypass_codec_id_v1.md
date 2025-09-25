# _HFP_BYPASS_CODEC_ID_V1 structure

## Description

The HFP_BYPASS_CODEC_ID_V1 structure defines version 1 of the supported codec ID structure.

## Members

### `CodecId`

The codec ID can be any of the values in the following table.

| Value | Description |
| --- | --- |
| 0 | Undefined codec |
| 1 | CVSD codec (narrow band) |
| 2 | mSBC codec (wide band speech) |

## See also

[HFP_BYPASS_CODEC_ID_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ne-bthhfpddi-_hfp_bypass_codec_id_version)

[IOCTL_BTHHFP_DEVICE_GET_CODEC_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_codec_id)