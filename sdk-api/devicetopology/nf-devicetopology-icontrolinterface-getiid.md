# IControlInterface::GetIID

## Description

The **GetIID** method gets the interface ID of the function-specific control interface of the part.

## Parameters

### `pIID` [out]

Pointer to a GUID variable into which the method writes the interface ID of the function-specific control interface of the part. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pIID* is **NULL**. |

## Remarks

An object that represents a part (connector or subunit) has two control interfaces. The first is a generic control interface, [IControlInterface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolinterface), which has methods that are common to all types of controls. The second is a function-specific control interface that has methods that apply to a particular type of control. The **GetIID** method gets the interface ID of the second control interface. The client can supply this interface ID to the [IPart::Activate](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-activate) method to create an instance of the part's function-specific interface.

The method gets one of the function-specific interface IDs shown in the following table.

| Interface ID | Interface name |
| --- | --- |
| IID_IAudioAutoGainControl | [IAudioAutoGainControl](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol) |
| IID_IAudioBass | [IAudioBass](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiobass) |
| IID_IAudioChannelConfig | [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig) |
| IID_IAudioInputSelector | [IAudioInputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioinputselector) |
| IID_IAudioLoudness | [IAudioLoudness](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioloudness) |
| IID_IAudioMidrange | [IAudioMidrange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomidrange) |
| IID_IAudioMute | [IAudioMute](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomute) |
| IID_IAudioOutputSelector | [IAudioOutputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiooutputselector) |
| IID_IAudioPeakMeter | [IAudioPeakMeter](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiopeakmeter) |
| IID_IAudioTreble | [IAudioTreble](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiotreble) |
| IID_IAudioVolumeLevel | [IAudioVolumeLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiovolumelevel) |
| IID_IDeviceSpecificProperty | [IDeviceSpecificProperty](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty) |
| IID_IKsFormatSupport | [IKsFormatSupport](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksformatsupport) |
| IID_IKsJackDescription | [IKsJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription) |

To obtain the interface ID of an interface, use the **__uuidof** operator. For example, the interface ID of the **IAudioAutoGainControl** interface is defined as follows:

``` syntax

const IID IID_IAudioAutoGainControl  __uuidof(IAudioAutoGainControl)

```

For more information about the **__uuidof** operator, see the Windows SDK documentation.

## See also

[IControlInterface Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolinterface)