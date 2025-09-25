# IMFMediaEventQueue::Shutdown

## Description

Shuts down the event queue.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Call this method when your component shuts down. After this method is called, all [IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue) methods return **MF_E_SHUTDOWN**.

This method removes all of the events from the queue.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEventQueue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventqueue)