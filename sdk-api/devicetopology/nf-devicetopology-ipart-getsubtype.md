# IPart::GetSubType

## Description

The **GetSubType** method gets the part subtype of this part.

## Parameters

### `pSubType` [out]

Pointer to a GUID variable into which the method writes the subtype GUID for this part.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pSubType* is **NULL**. |

## Remarks

This method typically retrieves one of the KSNODETYPE_*Xxx* GUID values from header file Ksmedia.h, although some custom drivers might provide other GUID values. For more information about KSNODETYPE_*Xxx* GUIDs, see the Windows DDK documentation.

As explained in [IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart), a part can be either a connector or a subunit.

For a part that is a connector, this method retrieves the pin-category GUID that the driver has assigned to the connector. The following are examples of pin-category GUIDs:

* KSNODETYPE_ANALOG_CONNECTOR, if the connector is part of the data path to or from an analog device such as a microphone or speakers.
* KSNODETYPE_SPDIF_INTERFACE, if the connector is part of the data path to or from an S/PDIF port.

For more information, see the discussion of the pin-category property, KSPROPERTY_PIN_CATEGORY, in the Windows DDK documentation.

For a part that is a subunit, this method retrieves a subtype GUID that indicates the stream-processing function that the subunit performs. For example, for a volume-control subunit, the method retrieves GUID value KSNODETYPE_VOLUME.

The following table lists some of the subtype GUIDs that can be retrieved by the **GetSubType** method for a subunit.

| Subtype GUID | Control interface | Required or optional |
| --- | --- | --- |
| KSNODETYPE_3D_EFFECTS | [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig) | Optional |
| KSNODETYPE_AGC | [IAudioAutoGainControl](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol) | Required |
| KSNODETYPE_DAC | [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig) | Optional |
| KSNODETYPE_DEMUX | [IAudioOutputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiooutputselector) | Required |
| KSNODETYPE_DEV_SPECIFIC | [IDeviceSpecificProperty](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty) | Required |
| KSNODETYPE_LOUDNESS | [IAudioLoudness](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioloudness) | Required |
| KSNODETYPE_MUTE | [IAudioMute](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomute) | Required |
| KSNODETYPE_MUX | [IAudioInputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioinputselector) | Required |
| KSNODETYPE_PEAKMETER | [IAudioPeakMeter](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiopeakmeter) | Required |
| KSNODETYPE_PROLOGIC_DECODER | [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig) | Optional |
| KSNODETYPE_TONE | [IAudioBass](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiobass)<br><br>[IAudioMidrange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomidrange)<br><br>[IAudioTreble](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiotreble) | OptionalOptional<br><br>Optional |
| KSNODETYPE_VOLUME | [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig)<br><br>[IAudioVolumeLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiovolumelevel) | OptionalRequired |

In the preceding table, the middle column lists the control interfaces that are supported by subunits of the subtype specified in the left column. The right column indicates whether the subunit's support for a control interface is required or optional. If support is required, an application can rely on a subunit of the specified subtype to support the control interface. If support is optional, a subunit of the specified subtype can, but does not necessarily, support the control interface.

The control interfaces in the preceding table provide convenient access to the properties of subunits. However, some subunits have properties for which no corresponding control interfaces exist. Applications can access these properties through the [IKsControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksproxy/nn-ksproxy-ikscontrol) interface. For more information, see [Using the IKsControl Interface to Access Audio Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-ikscontrol-interface-to-access-audio-properties).

## See also

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)