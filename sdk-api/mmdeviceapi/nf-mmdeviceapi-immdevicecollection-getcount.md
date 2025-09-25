# IMMDeviceCollection::GetCount

## Description

The **GetCount** method retrieves a count of the devices in the device collection.

## Parameters

### `pcDevices` [out]

Pointer to a **UINT** variable into which the method writes the number of devices in the device collection.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pcDevices* is **NULL**. |

## Remarks

For a code example that calls the **GetCount** method, see [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties).

## See also

[IMMDeviceCollection Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevicecollection)