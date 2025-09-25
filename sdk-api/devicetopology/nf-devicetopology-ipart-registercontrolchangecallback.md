# IPart::RegisterControlChangeCallback

## Description

The **RegisterControlChangeCallback** method registers the [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interface, which the client implements to receive notifications of status changes in this part.

## Parameters

### `riid` [in]

The function-specific control interface that is to be monitored for control changes. For more information, see Remarks.

### `pNotify` [in]

Pointer to the client's [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interface. If the method succeeds, it calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the client's **IControlChangeNotify** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *riid* is not a valid control-interface identifier. |
| **E_POINTER** | Pointer *pNotify* is **NULL**. |

## Remarks

Set parameter *riid* to one of the following GUID values:

* IID_IAudioAutoGainControl
* IID_IAudioBass
* IID_IAudioChannelConfig
* IID_IAudioInputSelector
* IID_IAudioLoudness
* IID_IAudioMidrange
* IID_IAudioMute
* IID_IAudioOutputSelector
* IID_IAudioPeakMeter
* IID_IAudioTreble
* IID_IAudioVolumeLevel
* IID_IDeviceSpecificProperty
* IID_IKsFormatSupport
* IID_IKsJackDescription

To obtain the interface ID of the function-specific control interface for a part, call the part's [IControlInterface::GetIID](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolinterface-getiid) method. To obtain the interface ID of a function-specific control interface type, use the **__uuidof** operator. For example, the interface ID of [IAudioAutoGainControl](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudioautogaincontrol) is defined as follows:

``` syntax

const IID IID_IAudioAutoGainControl  __uuidof(IAudioAutoGainControl)

```

For more information about the **__uuidof** operator, see the Windows SDK documentation.

Before the client releases its final reference to the [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interface, it should call the [IPart::UnregisterControlChangeCallback](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-unregistercontrolchangecallback) method to unregister the interface. Otherwise, the application leaks the resources held by the **IControlChangeNotify** and [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) objects. Note that **RegisterControlChangeCallback** calls the client's [IControlChangeNotify::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method, and **UnregisterControlChangeCallback** calls the [IControlChangeNotify::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the client errs by releasing its reference to the **IControlChangeNotify** interface before calling **UnregisterControlChangeCallback**, the **IPart** object never releases its reference to the **IControlChangeNotify** interface. For example, a poorly designed **IControlChangeNotify** implementation might call **UnregisterControlChangeCallback** from the destructor for the **IControlChangeNotify** object. In this case, the client will not call **UnregisterControlChangeCallback** until the **IPart** object releases its reference to the **IControlChangeNotify** interface, and the **IPart** object will not release its reference to the **IControlChangeNotify** interface until the client calls **UnregisterControlChangeCallback**. For more information about the **AddRef** and **Release** methods, see the discussion of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface in the Windows SDK documentation.

## See also

[IControlChangeNotify Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify)

[IControlInterface::GetIID](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolinterface-getiid)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[IPart::UnregisterControlChangeCallback](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-unregistercontrolchangecallback)