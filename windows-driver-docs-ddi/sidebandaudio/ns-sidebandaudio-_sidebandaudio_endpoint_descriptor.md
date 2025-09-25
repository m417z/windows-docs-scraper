# _SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR structure

## Description

The **SIDEBANDAUDIO_ENDPOINT_DESCRIPTOR** structure describes the characteristics of a Sideband audio Endpoint. Audio driver should query this information to build the KS filter representing this endpoint.

## Members

### `CbSize`

Size of Descriptor including storage for UNICODE_STRING and any additional data.

### `ContainerId`

Pnp Container ID for connected device. See [Audio Endpoint Container ID](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-endpoint-container-id).

### `Category`

KSPIN_DESCRIPTOR.Category to indicate form factor. Specifies a pointer to a KS pin category GUID. The KS pin category GUID identifies the general category of functionality that the pin provides. Examples of KS pin category GUIDs are KSNODETYPE_SPEAKER, KSNODETYPE_HEADPHONES, and KSNODETYPE_MICROPHONE, which are all defined in Ksmedia.h. See [Pin Category Property](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-category-property).

### `Direction`

Specifies either KSPIN_DATAFLOW_IN or KSPIN_DATAFLOW_OUT. See [KSPIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-kspin_dataflow).

### `Capabilities`

Capabilities of the endpoint like (mute, volume, sidetone, etc.). See [SIDEBANDAUDIO_ENDPOINT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_endpoint_capabilities).

### `FriendlyName`

Storage for friendly name is attached after descriptor and is included in cbSize. See [Friendly Names for Audio Endpoint Devices](https://learn.microsoft.com/windows-hardware/drivers/audio/friendly-names-for-audio-endpoint-devices).

### `VolumePropertyValuesSize`

If remote volume control is supported, this member contains the size of the data returned by the [IOCTL_SBAUD_GET_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_volumepropertyvalues) request.

### `SidetoneVolumePropertyValueSize`

If remote volume control is supported, this member contains the size of the data returned by the [IOCTL_SBAUD_GET_SIDETONE_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_sidetone_volumepropertyvalues) request.

### `MutePropertyValuesSize`

If remote mute is supported, the member contains the size of data returned by [IOCTL_SBAUD_GET_MUTEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_mutepropertyvalues).

## Remarks

## Requirements

|   |   |
| ---- |:---- |
| **Header** | sidebandaudio.h |

## See also

[sidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/)

[SIDEBANDAUDIO_ENDPOINT_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ns-sidebandaudio-_sidebandaudio_endpoint_capabilities)

[IOCTL_SBAUD_GET_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_volumepropertyvalues)

[IOCTL_SBAUD_GET_SIDETONE_VOLUMEPROPERTYVALUES](https://learn.microsoft.com/windows-hardware/drivers/ddi/sidebandaudio/ni-sidebandaudio-ioctl_sbaud_get_sidetone_volumepropertyvalues)