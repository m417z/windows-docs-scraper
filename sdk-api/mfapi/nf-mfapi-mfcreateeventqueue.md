# MFCreateEventQueue function

## Description

Creates an event queue.

## Parameters

### `ppMediaEventQueue`

Receives a pointer to the [IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue) interface of the event queue. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function creates a helper object that you can use to implement the [IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator) interface.

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)