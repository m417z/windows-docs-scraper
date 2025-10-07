# GetTSAudioEndpointEnumeratorForSession callback function

Returns a reference to an audio endpoint enumerator for the specified session ID. Consumers of this audio endpoint enumerator, such as MMDevAPI.dll, call this function to retrieve an audio endpoint enumerator in a Remote Desktop Services session.

## Parameters

*SessionId* \[in\]

The identifier of the Remote Desktop Services session.

*ppEndpointEnumerator* \[out\]

The address of a pointer to an [**IMMDeviceEnumerator**](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator) interface.

## Return value

If the method succeeds, it returns **S\_OK**.

## Remarks

This function is not defined in a header file. You should implement and export this function in your custom endpoint enumerator and use the signature shown in the syntax block earlier in this topic.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008 R2<br> |

## See also

[Implementing a Custom Audio Endpoint Enumerator](https://learn.microsoft.com/windows/win32/termserv/implementing-an-audio-endpoint-enumerator)

[**IMMDeviceEnumerator**](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)

