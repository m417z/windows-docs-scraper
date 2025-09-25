# IMFQualityAdvise2::NotifyQualityEvent

## Description

Forwards an [MEQualityNotify](https://learn.microsoft.com/windows/desktop/medfound/mequalitynotify) event from the media sink.

## Parameters

### `pEvent` [in]

A pointer to the event's [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface.

### `pdwFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [MF_QUALITY_ADVISE_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_quality_advise_flags) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFQualityAdvise2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise2)