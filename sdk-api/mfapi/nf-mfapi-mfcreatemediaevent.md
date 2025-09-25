# MFCreateMediaEvent function

## Description

Creates a media event object.

## Parameters

### `met`

The event type. See [IMFMediaEvent::GetType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-gettype). For a list of event types, see [Media Foundation Events](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-events).

### `guidExtendedType`

The extended type. See [IMFMediaEvent::GetExtendedType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getextendedtype). If the event type does not have an extended type, use the value GUID_NULL.

### `hrStatus`

The event status. See [IMFMediaEvent::GetStatus](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getstatus)

### `pvValue`

The value associated with the event, if any. See [IMFMediaEvent::GetValue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getvalue). This parameter can be **NULL**.

### `ppEvent`

Receives a pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)