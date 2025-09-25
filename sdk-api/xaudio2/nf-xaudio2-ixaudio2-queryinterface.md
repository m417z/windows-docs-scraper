# IXAudio2::QueryInterface

## Description

Queries for a given COM interface on the XAudio2 object.

## Parameters

### `riid` [in]

The REFIID that identifies the interface to query for.

### `ppvInterface` [out]

Address of a pointer that receives the interface.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

Only IID_IUnknown and IID_IXAudio2 are provided by XAudio2.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)