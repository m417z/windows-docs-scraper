# KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_HEADER structure

## Description

The **KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_HEADER** structure contains a NTP-specific payload that is used to set or disable an NTP server on a Onvif protocol camera.

## Members

### `Size`

The size of the NTP-specific payload.

### `Type`

Contains one of the values from the [KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ne-ksmedia-ksproperty_networkcameracontrol_ntpinfo_type) enumeration.

## Remarks

This command will be used to set or disable an NTP server on the Onvif protocol camera. The app can choose to configure the camera to use the same NTP server as is used by the local machine (for example, the Windows device that is controlling the camera.) It can also be used to configure the camera to use a custom NTP server.

The local PC's NTP server entry is found by parsing the registry value at SYSTEM\\CurrentControlSet\\Services\\W32Time\\Parameters\\. Apps can scan the space-separated registry value for the most optimal server to set on the camera.

## See also

[KSPROPERTY_NETWORKCAMERACONTROL_EVENTTOPICS_XML](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-eventtopics-xml)

[KSPROPERTY_NETWORKCAMERACONTROL_METADATA](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-metadata)

[KSPROPERTYSETID_NetworkCameraControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropertysetid-networkcameracontrol)

[KSPROPERTY_NETWORKCAMERACONTROL_NTP](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-ntp)

[KSPROPERTY_NETWORKCAMERACONTROL_URI](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-networkcameracontrol-uri)

[KSPROPERTY_NETWORKCAMERACONTROL_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_networkcameracontrol_event_info)

[KSPROPERTY_NETWORKCAMERACONTROL_METADATA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_networkcameracontrol_metadata_info)

[KSPROPERTY_NETWORKCAMERACONTROL_NTPINFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_networkcameracontrol_ntpinfo_type)

[KSPROPERTY_NETWORKCAMERACONTROL_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_networkcameracontrol_property)