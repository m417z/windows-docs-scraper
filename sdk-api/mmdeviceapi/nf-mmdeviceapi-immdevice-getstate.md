# IMMDevice::GetState

## Description

The **GetState** method retrieves the current device state.

## Parameters

### `pdwState` [out]

Pointer to a **DWORD** variable into which the method writes the current state of the device. The device-state value is one of the following [DEVICE_STATE_XXX](https://learn.microsoft.com/windows/desktop/CoreAudio/device-state-xxx-constants) constants:

DEVICE_STATE_ACTIVE

DEVICE_STATE_DISABLED

DEVICE_STATE_NOTPRESENT

DEVICE_STATE_UNPLUGGED

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pdwState* is **NULL**. |

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)