# IMFMediaSource::GetCharacteristics

## Description

Retrieves the characteristics of the media source.

## Parameters

### `pdwCharacteristics` [out]

Receives a bitwise **OR** of zero or more flags from the [MFMEDIASOURCE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfmediasource_characteristics) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

The characteristics of a media source can change at any time. If this happens, the source sends an [MESourceCharacteristicsChanged](https://learn.microsoft.com/windows/desktop/medfound/mesourcecharacteristicschanged) event.

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)