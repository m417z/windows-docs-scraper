# IAudioEndpoint::GetFrameFormat

## Description

The **GetFrameFormat** method retrieves the format of the audio endpoint.

## Parameters

### `ppFormat` [out]

Receives a pointer to a **WAVEFORMATEX** structure that contains the format information for the device that the audio endpoint represents. The implementation must allocate memory for the structure by using **CoTaskMemAlloc**. The caller must free the buffer by using **CoTaskMemFree**. For information about [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree), see the Windows SDK documentation.

## Return value

If the method succeeds, it returns **S_OK**.

## Remarks

This method must not be called from a real-time processing thread.

The Remote Desktop Services AudioEndpoint API is for use in Remote Desktop scenarios; it is not for client applications.

## See also

[IAudioEndpoint](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpoint)