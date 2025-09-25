# IMFTimer::SetTimer

## Description

Sets a timer that invokes a callback at the specified time.

## Parameters

### `dwFlags` [in]

Bitwise OR of zero or more flags from the [MFTIMER_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mftimer_flags) enumeration.

### `llClockTime` [in]

The time at which the timer should fire, in units of the clock's frequency. The time is either absolute or relative to the current time, depending on the value of *dwFlags*.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface. The callback's [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called at the time specified in the *llClockTime* parameter.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

### `ppunkKey` [out]

Receives a pointer to the **IUnknown** interface of a cancellation object. The caller must release the interface. To cancel the timer, pass this pointer to the [IMFTimer::CancelTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftimer-canceltimer) method. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The clock was shut down. |
| **MF_S_CLOCK_STOPPED** | The method succeeded, but the clock is stopped. |

## Remarks

If the clock is stopped, the method returns MF_S_CLOCK_STOPPED. The callback will not be invoked until the clock is started.

## See also

[IMFTimer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftimer)