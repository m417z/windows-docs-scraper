# IMFTimecodeTranslate::EndConvertHNSToTimecode

## Description

Completes an asynchronous request to convert time in 100-nanosecond units to Society of Motion Picture and Television Engineers (SMPTE) time code.

## Parameters

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `pPropVarTimecode` [out]

A pointer to a **PROPVARIANT** that receives the converted time. The **vt** member of the **PROPVARIANT** structure is set to VT_I8. The **hVal.QuadPart** member contains the converted time in binary coded decimal (BCD) form. See Remarks.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method after the [IMFTimecodeTranslate::BeginConvertHNSToTimecode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimecodetranslate-beginconverthnstotimecode) method completes asynchronously.

The value of *pPropVarTimecode* is a 64-bit unsigned value typed as a **LONGLONG**. The upper **DWORD** contains the range. (A *range* is a continuous series of time codes.) The lower **DWORD** contains the time code in the form of a hexadecimal number *0xhhmmssff*, where each 2-byte sequence is read as a decimal value.

```cpp
HRESULT ParseTimeCode(
    const PROPVARIANT& var,
    DWORD *pdwRange,
    DWORD *pdwFrames,
    DWORD *pdwSeconds,
    DWORD *pdwMinutes,
    DWORD *pdwHours
    )
{
    if (var.vt != VT_I8)
    {
        return E_INVALIDARG;
    }

    ULONGLONG ullTimeCode = (ULONGLONG)var.hVal.QuadPart;
    DWORD dwTimecode = (DWORD)(ullTimeCode & 0xFFFFFFFF);

    *pdwRange   = (DWORD)(ullTimeCode >> 32);
    *pdwFrames  =     dwTimecode & 0x0000000F;
    *pdwFrames  += (( dwTimecode & 0x000000F0) >> 4 )  * 10;
    *pdwSeconds =   ( dwTimecode & 0x00000F00) >> 8;
    *pdwSeconds += (( dwTimecode & 0x0000F000) >> 12 ) * 10;
    *pdwMinutes =   ( dwTimecode & 0x000F0000) >> 16;
    *pdwMinutes += (( dwTimecode & 0x00F00000) >> 20 ) * 10;
    *pdwHours   =   ( dwTimecode & 0x0F000000) >> 24;
    *pdwHours   += (( dwTimecode & 0xF0000000) >> 28 ) * 10;

    return S_OK;
}

```

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFTimecodeTranslate](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimecodetranslate)