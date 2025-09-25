# IMMDeviceEnumerator::EnumAudioEndpoints

## Description

The **EnumAudioEndpoints** method generates a collection of audio endpoint devices that meet the specified criteria.

## Parameters

### `dataFlow` [in]

The data-flow direction for the endpoint devices in the collection. The caller should set this parameter to one of the following [EDataFlow](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-edataflow) enumeration values:

eRender

eCapture

eAll

If the caller specifies eAll, the method includes both rendering and capture endpoints in the collection.

### `dwStateMask` [in]

The state or states of the endpoints that are to be included in the collection. The caller should set this parameter to the bitwise OR of one or more of the following [DEVICE_STATE_XXX](https://learn.microsoft.com/windows/desktop/CoreAudio/device-state-xxx-constants) constants:

DEVICE_STATE_ACTIVE

DEVICE_STATE_DISABLED

DEVICE_STATE_NOTPRESENT

DEVICE_STATE_UNPLUGGED

For example, if the caller sets the *dwStateMask* parameter to DEVICE_STATE_ACTIVE | DEVICE_STATE_UNPLUGGED, the method includes endpoints that are either active or unplugged from their jacks, but excludes endpoints that are on audio adapters that have been disabled or are not present. To include all endpoints, regardless of state, set *dwStateMask* = DEVICE_STATEMASK_ALL.

### `ppDevices` [out]

Pointer to a pointer variable into which the method writes the address of the [IMMDeviceCollection](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevicecollection) interface of the device-collection object. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **EnumAudioEndpoints** call fails, **ppDevices* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppDevices* is **NULL**. |
| **E_INVALIDARG** | Parameter *dataFlow* or *dwStateMask* is out of range. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

For example, the following call enumerates all audio-rendering endpoint devices that are currently active (present and not disabled):

```cpp

  hr = pDevEnum->EnumAudioEndpoints(
                   eRender, DEVICE_STATE_ACTIVE,
                   &pEndpoints);

```

In the preceding code fragment, variable *hr* is of type **HRESULT**, *pDevEnum* is a pointer to an **IMMDeviceEnumerator** interface, and *pEndpoints* is a pointer to an **IMMDeviceCollection** interface.

#### Examples

For a code example that calls the **EnumAudioEndpoints** method, see [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties).

## See also

[IMMDeviceCollection Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevicecollection)

[IMMDeviceEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)