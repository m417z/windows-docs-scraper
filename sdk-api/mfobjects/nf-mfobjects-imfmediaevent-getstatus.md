# IMFMediaEvent::GetStatus

## Description

Retrieves an **HRESULT** that specifies the event status.

## Parameters

### `phrStatus` [out]

Receives the event status. If the operation that generated the event was successful, the value is a success code. A failure code means that an error condition triggered the event.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)