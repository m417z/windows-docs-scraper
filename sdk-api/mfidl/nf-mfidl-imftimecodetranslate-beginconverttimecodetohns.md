# IMFTimecodeTranslate::BeginConvertTimecodeToHNS

## Description

Starts an asynchronous call to convert Society of Motion Picture and Television Engineers (SMPTE) time code to 100-nanosecond units.

## Parameters

### `pPropVarTimecode` [in]

Time in SMPTE time code to convert. The **vt** member of the **PROPVARIANT** structure is set to **VT_I8**. The **hVal.QuadPart** member contains the time in binary coded decimal (BCD) form. See Remarks.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `punkState` [in]

PPointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pPropVarTimecode* is not **VT_I8**. |
| **MF_E_SHUTDOWN** | The object's **Shutdown** method was called. |
| **MF_E_BYTESTREAM_NOT_SEEKABLE** | The byte stream is not seekable. The time code cannot be read from the end of the byte stream. |

## Remarks

When the asynchronous method completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application must call [IMFTimecodeTranslate::EndConvertTimecodeToHNS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimecodetranslate-endconverttimecodetohns) to complete the asynchronous request.

The value of *pPropVarTimecode* is a 64-bit unsigned value typed as a **LONGLONG**. The upper **DWORD** contains the range. (A *range* is a continuous series of time codes.) The lower **DWORD** contains the time code in the form of a hexadecimal number *0xhhmmssff*, where each 2-byte sequence is read as a decimal value.

```cpp
void CreateTimeCode(
    DWORD dwFrames,
    DWORD dwSeconds,
    DWORD dwMinutes,
    DWORD dwHours,
    DWORD dwRange,
    PROPVARIANT *pvar
    )
{
    ULONGLONG ullTimecode = ((ULONGLONG)dwRange) << 32;

    ullTimecode +=   dwFrames  % 10;
    ullTimecode += (( (ULONGLONG)dwFrames )  / 10) << 4;
    ullTimecode += (( (ULONGLONG)dwSeconds ) % 10) << 8;
    ullTimecode += (( (ULONGLONG)dwSeconds ) / 10) << 12;
    ullTimecode += (( (ULONGLONG)dwMinutes ) % 10) << 16;
    ullTimecode += (( (ULONGLONG)dwMinutes ) / 10) << 20;
    ullTimecode += (( (ULONGLONG)dwHours )   % 10) << 24;
    ullTimecode += (( (ULONGLONG)dwHours )   / 10) << 28;

    pvar->vt = VT_I8;
    pvar->hVal.QuadPart = (LONGLONG)ullTimecode;
}

```

## See also

[Calling Asynchronous Methods](https://learn.microsoft.com/windows/desktop/medfound/calling-asynchronous-methods)

[IMFTimecodeTranslate](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimecodetranslate)