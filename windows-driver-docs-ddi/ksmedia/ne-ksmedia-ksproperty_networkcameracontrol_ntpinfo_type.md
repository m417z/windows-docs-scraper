# KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE enumeration

## Description

The **KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE** enumeration defines the network camera control NTP types.

## Constants

### `KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE_DISABLE`

Sets the camera into manual mode. The user can set the time on the camera manually.

### `KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE_HOSTNTP`

Sets the camera to use the same NTP server as is configured on the host.

### `KSPROPERYT_NETWORKCAMERACONTROL_NTPINFO_TYPE_CUSTOM`

Sets a specific custom NTP server on the camera.

## Remarks

If NTP is enabled on the camera, a get operation will return the name of the NTP server that is set on the Onvif protocol device.

If use of a NTP server is disabled on the camera, a get operation will return KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE_DISABLE.

## See also

[KSPROPERTY_NETWORKCAMERACONTROL_EVENTTOPICS_XML](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-eventtopics-xml)

[KSPROPERTY_NETWORKCAMERACONTROL_METADATA](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-metadata)

[KSPROPERTYSETID_NetworkCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-networkcameracontrol)

[KSPROPERTY_NETWORKCAMERACONTROL_NTP](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-ntp)

[KSPROPERTY_NETWORKCAMERACONTROL_URI](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-uri)

[KSPROPERTY_NETWORKCAMERACONTROL_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_networkcameracontrol_event_info)

[KSPROPERTY_NETWORKCAMERACONTROL_METADATA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_networkcameracontrol_metadata_info)

[KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_networkcameracontrol_ntpinfo_header)

[KSPROPERTY_NETWORKCAMERACONTROL_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_networkcameracontrol_property)