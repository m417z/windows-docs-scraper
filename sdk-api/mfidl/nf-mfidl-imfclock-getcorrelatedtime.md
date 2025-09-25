# IMFClock::GetCorrelatedTime

## Description

Retrieves the last clock time that was correlated with system time.

## Parameters

### `dwReserved` [in]

Reserved, must be zero.

### `pllClockTime` [out]

Receives the last known clock time, in units of the clock's frequency.

### `phnsSystemTime` [out]

Receives the system time that corresponds to the clock time returned in *pllClockTime*, in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | The clock does not have a time source. |

## Remarks

At some fixed interval, a clock correlates its internal clock ticks with the system time. (The system time is the time returned by the high-resolution performance counter.) This method returns:

* The most recent clock time that was correlated with system time.
* The system time when the correlation was performed.

The clock time is returned in the *pllClockTime* parameter and is expressed in units of the clock's frequency. If the clock's [IMFClock::GetClockCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getclockcharacteristics) method returns the **MFCLOCK_CHARACTERISTICS_FLAG_FREQUENCY_10MHZ** flag, the clock's frequency is 10 MHz (each clock tick is 100 nanoseconds). Otherwise, you can get the clock's frequency by calling [IMFClock::GetProperties](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getproperties). The frequency is given in the **qwClockFrequency** member of the [MFCLOCK_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfclock_properties) structure returned by that method.

The system time is returned in the *phnsSystemTime* parameter, and is always expressed in 100-nanosecond units.

To find out how often the clock correlates its clock time with the system time, call [GetProperties](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclock-getproperties). The correlation interval is given in the **qwCorrelationRate** member of the [MFCLOCK_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfclock_properties) structure. If **qwCorrelationRate** is zero, it means the clock performs the correlation whenever **GetCorrelatedTime** is called. Otherwise, you can calculate the current clock time by extrapolating from the last correlated time.

Some clocks support rate changes through the [IMFRateControl](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfratecontrol) interface. If so, the clock time advances at a speed of frequency × current rate. If a clock does not expose the **IMFRateControl** interface, the rate is always 1.0.

For the presentation clock, the clock time is the presentation time, and is always relative to the starting time specified in [IMFPresentationClock::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start). You can also get the presentation time by calling [IMFPresentationClock::GetTime](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-gettime).

## See also

[IMFClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclock)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)