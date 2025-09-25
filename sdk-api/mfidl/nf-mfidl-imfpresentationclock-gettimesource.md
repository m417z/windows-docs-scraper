# IMFPresentationClock::GetTimeSource

## Description

Retrieves the clock's presentation time source.

## Parameters

### `ppTimeSource` [out]

Receives a pointer to the time source's [IMFPresentationTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationtimesource) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | No time source was set on this clock. |

## See also

[IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)