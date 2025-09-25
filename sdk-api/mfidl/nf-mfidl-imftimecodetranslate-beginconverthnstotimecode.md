# IMFTimecodeTranslate::BeginConvertHNSToTimecode

## Description

Starts an asynchronous call to convert time in 100-nanosecond units to Society of Motion Picture and Television Engineers (SMPTE) time code.

## Parameters

### `hnsTime` [in]

The time to convert, in 100-nanosecond units.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MF_E_SHUTDOWN** | The object's **Shutdown** method was called. |
| **MF_E_BYTESTREAM_NOT_SEEKABLE** | The byte stream is not seekable. The time code cannot be read from the end of the byte stream. |

## Remarks

When the asynchronous method completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application must call [IMFTimecodeTranslate::EndConvertHNSToTimecode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimecodetranslate-endconverthnstotimecode) to complete the asynchronous request.

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFTimecodeTranslate](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimecodetranslate)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)