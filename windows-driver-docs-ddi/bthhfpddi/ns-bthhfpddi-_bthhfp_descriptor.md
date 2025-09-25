# _BTHHFP_DESCRIPTOR structure

## Description

The BTHHFP_DESCRIPTOR data structure stores information describing a paired Handsfree profile (HFP) device.

The HFP driver returns this data structure in the output buffer for the [IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor) request.

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

## Remarks

The HFP driver calculates the *InputPinCategory* and *OutputPinCategory* GUIDs based on the 'Bluetooth Class of Device' data that is contained in the SDP information of the paired device. The audio driver sets the [KSPIN_DESCRIPTOR.Category](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor) members for the input and output bridge pins to the calculated GUIDs.

**Note**

In some cases the input and output pin categories may be the same.

The audio driver should make no particular assumptions about the category GUID values returned in *InputPinCategory* and *OutputPinCategory* members. The audio system uses this information to help determine the type of device (for example, headset versus speakers) and whether to use the device for different purposes such as the default communications device.

The audio driver stores the *ContainerId* in appropriate context data, and returns this value in its implementation of the [KSPROPERTY_JACK_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-containerid) KS property.

If *SupportsVolume* is true, the audio driver includes volume support in its KS topology.

The audio driver uses the string returned in *FriendlyName* to set the DEVPKEY_DeviceInterface_FriendlyName property on the KS filter’s KSCATEGORY_AUDIO device interface. To do this, the audio driver calls IoSetDeviceInterfacePropertyData and sets the property type to DEVPROP_TYPE_STRING_INDIRECT. An example string is "@System32\drivers\bthhfenum.sys,#2;%1 Hands-Free%0..;(SomeDeviceName)”. Note that this is an indirect string and therefore not necessarily the human readable string that is directly displayed in a user interface. The audio system uses this string to generate localized strings used for display to the user, such as in the Sounds control panel.

For information about the IOCTLs that work with this structure, see [Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls).

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[Bluetooth HFP DDI Structures](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-structures)

[IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor)

[IOCTL_BTHHFP_DEVICE_GET_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_volumepropertyvalues)

[KSPIN_DESCRIPTOR.Category](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[KSPROPERTY_JACK_CONTAINERID](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-containerid)