# MBN_PIN_INFO structure

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PIN_INFO** structure represents the current PIN state of the device. It indicates if some PIN is expected by the device and the PIN type expected. Optionally, it also conveys remaining allowed attempts to enter a valid PIN. This structure can be obtained by either calling the [GetPinState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinstate) method of [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) or supplied as an input parameter to the [OnEnterComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinevents-onentercomplete) method of [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents).

## Members

### `pinState`

An [MBN_PIN_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_pin_state) value that indicates the current PIN state of the device.

### `pinType`

An [MBN_PIN_TYPE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_pin_type) value that indicates the type of PIN expected. This field is valid only when **pinState** is either **MBN_PIN_STATE_ENTER** or **MBN_PIN_STATE_UNBLOCK**.

### `attemptsRemaining`

Contains the number of attempts remaining to enter the valid PIN. This information is not available on some devices. If it is not available, then it is set to **MBN_ATTEMPTS_REMAINING_UNKNOWN**.