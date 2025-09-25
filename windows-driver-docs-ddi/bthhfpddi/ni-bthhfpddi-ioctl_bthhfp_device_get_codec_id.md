# IOCTL_BTHHFP_DEVICE_GET_CODEC_ID IOCTL

## Description

An audio driver can send an **IOCTL_BTHHFP_DEVICE_GET_CODEC_ID**
control code to query the Bluetooth driver stack about the codec ID used by the HFP service. This helps the audio driver determine the sampling rate for the data.

## Parameters

### Major code

### Input buffer

An [HFP_BYPASS_CODEC_ID_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ne-bthhfpddi-_hfp_bypass_codec_id_version) enumeration value. Currently, only REQ_HFP_BYPASS_CODEC_ID_V1 is supported.

### Input buffer length

The size of an [HFP_BYPASS_CODEC_ID_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ne-bthhfpddi-_hfp_bypass_codec_id_version) enumeration value.

### Output buffer

A codec ID structure containing the codec ID information. Currently, only [HFP_BYPASS_CODEC_ID_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ns-bthhfpddi-_hfp_bypass_codec_id_v1) is supported.

### Output buffer length

The size of a codec ID structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the routine succeeds, then Status is set to STATUS_SUCCESS and the *Information* member is the codec ID.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)