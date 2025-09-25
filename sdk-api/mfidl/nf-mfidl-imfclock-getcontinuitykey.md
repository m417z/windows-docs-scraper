# IMFClock::GetContinuityKey

## Description

Retrieves the clock's continuity key. (Not supported.)

## Parameters

### `pdwContinuityKey` [out]

Receives the continuity key.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Continuity keys are currently not supported in Media Foundation. Clocks must return the value zero in the *pdwContinuityKey* parameter.

## See also

[IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock)