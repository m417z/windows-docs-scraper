# IMFMediaEvent::GetExtendedType

## Description

Retrieves the extended type of the event.

## Parameters

### `pguidExtendedType` [out]

Receives a **GUID** that identifies the extended type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To define a custom event, create a new extended-type GUID and send an [MEExtendedType](https://learn.microsoft.com/windows/desktop/medfound/meextendedtype) event with that GUID.

Some standard Media Foundation events also use the extended type to differentiate between types of event data.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)