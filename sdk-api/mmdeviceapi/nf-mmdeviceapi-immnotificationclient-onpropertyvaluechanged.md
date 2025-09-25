# IMMNotificationClient::OnPropertyValueChanged

## Description

The **OnPropertyValueChanged** method indicates that the value of a property belonging to an audio endpoint device has changed.

## Parameters

### `pwstrDeviceId` [in]

Pointer to the [endpoint ID string](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-id-strings) that identifies the audio endpoint device. This parameter points to a null-terminated, wide-character string that contains the endpoint ID. The string remains valid for the duration of the call.

### `key` [in]

A [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that specifies the property. The structure contains the property-set GUID and an index identifying a property within the set. The structure is passed by value. It remains valid for the duration of the call. For more information about **PROPERTYKEY**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

A call to the [IPropertyStore::SetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761475(v=vs.85)) method that successfully changes the value of a property of an audio endpoint device generates a call to **OnPropertyValueChanged**. For more information about **IPropertyStore::SetValue**, see the Windows SDK documentation.

A client can use the *key* parameter to retrieve the new property value. For a code example that uses a property key to retrieve a property value from the property store of an endpoint device, see [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties).

For a code example that implements the **OnPropertyValueChanged** method, see [Device Events](https://learn.microsoft.com/windows/desktop/CoreAudio/device-events).

## See also

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)