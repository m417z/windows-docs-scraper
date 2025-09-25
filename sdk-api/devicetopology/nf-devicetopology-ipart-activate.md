# IPart::Activate

## Description

The **Activate** method activates a function-specific interface on a connector or subunit.

## Parameters

### `dwClsContext` [in]

The execution context in which the code that manages the newly created object will run. The caller can restrict the context by setting this parameter to the bitwise **OR** of one or more **CLSCTX** enumeration values. The client can avoid imposing any context restrictions by specifying CLSCTX_ALL. For more information about **CLSCTX**, see the Windows SDK documentation.

### `refiid` [in]

The interface ID for the requested control function. The client should set this parameter to one of the following **REFIID** values:

IID_IAudioAutoGainControl

IID_IAudioBass

IID_IAudioChannelConfig

IID_IAudioInputSelector

IID_IAudioLoudness

IID_IAudioMidrange

IID_IAudioMute

IID_IAudioOutputSelector

IID_IAudioPeakMeter

IID_IAudioTreble

IID_IAudioVolumeLevel

IID_IDeviceSpecificProperty

IID_IKsFormatSupport

IID_IKsJackDescription

IID_IKsJackDescription2

For more information, see Remarks.

### `ppvObject` [out]

Pointer to a pointer variable into which the method writes the address of the interface that is specified by parameter *refiid*. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **Activate** call fails, **ppObject* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The CLSCTX_INPROC_SERVER bit in *dwClsContext* is zero. |
| **E_POINTER** | Pointer *ppvObject* is **NULL**. |
| **E_NOINTERFACE** | The part object does not support the requested interface. |

## Remarks

The **Activate** method supports the following function-specific control interfaces:

* [IAudioAutoGainControl](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol)
* [IAudioBass](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiobass)
* [IAudioChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig)
* [IAudioInputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioinputselector)
* [IAudioLoudness](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioloudness)
* [IAudioMidrange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomidrange)
* [IAudioMute](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiomute)
* [IAudioOutputSelector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiooutputselector)
* [IAudioPeakMeter](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiopeakmeter)
* [IAudioTreble](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiotreble)
* [IAudioVolumeLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiovolumelevel)
* [IDeviceSpecificProperty](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-idevicespecificproperty)
* [IKsFormatSupport](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksformatsupport)
* [IKsJackDescription](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription)
* [IKsJackDescription2](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksjackdescription2)

To obtain the interface ID of the function-specific control interface of a part, call the part's [IControlInterface::GetIID](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolinterface-getiid) method. To obtain the interface ID of a function-specific control interface type, use the **__uuidof** operator. For example, the interface ID of **IAudioAutoGainControl** is defined as follows:

``` syntax

const IID IID_IAudioAutoGainControl  __uuidof(IAudioAutoGainControl)

```

For more information about the **__uuidof** operator, see the Windows SDK documentation.

## See also

[IControlInterface::GetIID](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolinterface-getiid)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)