# IMFClock::GetState

## Description

Retrieves the current state of the clock.

## Parameters

### `dwReserved` [in]

Reserved, must be zero.

### `peClockState` [out]

Receives the clock state, as a member of the [MFCLOCK_STATE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfclock_state) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock)