# _BTHHFP_DESCRIPTOR2 structure

## Description

The BTHHFP_DESCRIPTOR2 data structure stores information describing a paired Handsfree profile (HFP) device.

The HFP driver returns this data structure in the output buffer for the [IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor2) request.

## Members

### `InputPinCategory`

KS pin category for the input function of the paired HFP device.

### `OutputPinCategory`

KS pin category for the output function of the paired HFP device.

### `ContainerId`

The PnP container ID for the paired HFP device.

### `SupportsVolume`

Indicates whether the paired HFP device supports remote volume control.

### `VolumePropertyValuesSize`

If remote volume control is supported, this member contains the size of the data returned by the [IOCTL_BTHHFP_DEVICE_GET_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_volumepropertyvalues) request.

### `FriendlyName`

An indirect string identifying the human readable friendly name of the paired HFP device.

### `SupportsNREC`

Indicates whether the paired HFP device supports noise reduction / echo cancellation (NREC).

## Remarks

When the *SupportsNREC* parameter's value is TRUE, the audio driver should not support RAW mode pins. In this mode, the audio driver cannot support RAW mode pins because the remote Bluetooth device can enable its internal NREC processing at any time.

When *SupportsNREC* is set to FALSE, the audio driver should support RAW mode pins. The driver can, optionally, also support non-RAW modes and provide its own signal processing. In this case, the driver can provide signal processing in one of three ways: within the driver code itself; by using its digital signal processing (DSP) module; by using its associated audio processing object (APO).

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[Bluetooth HFP DDI Structures](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-structures)

[IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor2)

[IOCTL_BTHHFP_DEVICE_GET_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_volumepropertyvalues)