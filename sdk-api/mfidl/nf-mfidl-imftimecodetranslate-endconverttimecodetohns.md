# IMFTimecodeTranslate::EndConvertTimecodeToHNS

## Description

Completes an asynchronous request to convert time in Society of Motion Picture and Television Engineers (SMPTE) time code to 100-nanosecond units.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `phnsTime` [out]

Receives the converted time.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after the [IMFTimecodeTranslate::BeginConvertTimecodeToHNS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimecodetranslate-beginconverttimecodetohns) method completes asynchronously.

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFTimecodeTranslate](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimecodetranslate)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)