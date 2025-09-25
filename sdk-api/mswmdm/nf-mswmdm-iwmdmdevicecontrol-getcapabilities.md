# IWMDMDeviceControl::GetCapabilities

## Description

The **GetCapabilities** method retrieves the device capabilities to determine what operations the device can perform. The capabilities describe the methods of the device control that are supported by the media device.

## Parameters

### `pdwCapabilitiesMask` [out]

Pointer to a **DWORD** specifying the capabilities of the device. The following flags can be returned in this variable.

| Flag | Description |
| --- | --- |
| WMDM_DEVICECAP_CANPLAY | The media device can play MP3 audio. |
| WMDM_DEVICECAP_CANSTREAMPLAY | The media device can play streaming audio directly from the host computer. |
| WMDM_DEVICECAP_CANRECORD | The media device can record audio. |
| WMDM_DEVICECAP_CANSTREAMRECORD | The media device can record streaming audio directly to the host computer. |
| WMDM_DEVICECAP_CANPAUSE | The media device can pause during play or record operations. |
| WMDM_DEVICECAP_CANRESUME | The media device can resume an operation that was paused. |
| WMDM_DEVICECAP_CANSTOP | The media device can stop playing before the end of a file. |
| WMDM_DEVICECAP_CANSEEK | The media device can seek to a position other than the beginning of a file. |
| WMDM_DEVICECAP_HASSECURECLOCK | The media device has a secure clock. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pdwCapabilitiesMask* parameter is an invalid or **NULL** pointer. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Currently, not many devices report their capabilities correctly.

#### Examples

The following C++ code retrieves the device capabilities.

```cpp

// Examine the device capabilities.
// Use some of these to enable or disable the application's
// user interface elements.
CComQIPtr<IWMDMDeviceControl> pDeviceControl(pIWMDMDevice);
if (pDeviceControl != NULL)
{
    DWORD caps = 0;
    hr = pDeviceControl->GetCapabilities(&caps);
    if (caps & WMDM_DEVICECAP_CANPLAY)
    {
        // TODO: Display a message indicating that the media device can play MP3 audio.
    }
    if (caps & WMDM_DEVICECAP_CANSTREAMPLAY)
    {
        // TODO: Display a message that the device can play audio directly from the host computer.
    }
    if (caps & WMDM_DEVICECAP_CANRECORD)
    {
        // TODO: Display a message that the device can record audio.
    }
    if (caps & WMDM_DEVICECAP_CANSTREAMRECORD)
    {
        // TODO: Display a message that the media device can record
        // streaming audio directly to the host computer.
    }
    if (caps & WMDM_DEVICECAP_CANPAUSE)
    {
        // TODO: Display a message that the device can pause during play or record operations.
    }
    if (caps & WMDM_DEVICECAP_CANRESUME)
    {
        // TODO: Display a message that the device can resume an operation that was paused.
    }
    if (caps & WMDM_DEVICECAP_CANSTOP)
    {
        // TODO: Display a message that the device can stop playing before the end of a file.
    }
    if (caps & WMDM_DEVICECAP_CANSEEK)
    {
        // TODO: Display a message that the device can seek to a position
        // other than the beginning of the file.
    }
    if (caps & WMDM_DEVICECAP_HASSECURECLOCK)
    {
        // TODO: Display a message indicating that the device has a secure clock.
    }
}

```

## See also

[IWMDMDeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevicecontrol)

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)