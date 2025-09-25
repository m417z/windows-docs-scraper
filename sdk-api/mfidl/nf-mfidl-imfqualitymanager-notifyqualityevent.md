# IMFQualityManager::NotifyQualityEvent

## Description

Called when a pipeline component sends an [MEQualityNotify](https://learn.microsoft.com/windows/desktop/medfound/mequalitynotify) event.

## Parameters

### `pObject` [in]

Pointer to the **IUnknown** interface of the object that sent the event. The object is either a Media Foundation transform (MFT) or a stream sink.

### `pEvent` [in]

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of the event.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFQualityManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualitymanager)