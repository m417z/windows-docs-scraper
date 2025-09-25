# IMFClock::GetClockCharacteristics

## Description

Retrieves the characteristics of the clock.

## Parameters

### `pdwCharacteristics` [out]

Receives a bitwise OR of values from the [MFCLOCK_CHARACTERISTICS_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfclock_characteristics_flags) enumeration indicating the characteristics of the clock.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock)