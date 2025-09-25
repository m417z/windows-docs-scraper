# _WWAN_RADIO_STATE structure

## Description

The WWAN_RADIO_STATE structure represents the hardware-based and software-based radio power states of
the MB device.

## Members

### `HwRadioState`

The hardware radio power state of the device. The MB Service cannot set this state because it is
read-only. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WwanRadioOff | The hardware radio is off. |
| WwanRadioOn | The hardware radio is on, or no switch exists to control power to the hardware radio. |

### `SwRadioState`

The software-based radio power state of the device. The MB Service can get and set this state. The
following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WwanRadioOff | The radio is turned off by Windows. |
| WwanRadioOn | The radio is turned on by Windows. |

## Remarks

Miniport drivers should continue the software-based radio power state across system restart or device
removal and reinsertion. Miniport drivers should store the device software-based radio power state
information and use it to set the device radio power state for each restart or reinsertion of the
device.

The following table defines the relationship between hardware-based and software-based radio power
state settings and their effective result.

| HwRadioState value | SwRadioState value | Overall radio power state |
| --- | --- | --- |
| WwanRadioOff | WwanRadioOff | WwanRadioOff |
| WwanRadioOff | WwanRadioOn | WwanRadioOff |
| WwanRadioOn | WwanRadioOff | WwanRadioOff |
| WwanRadioOn | WwanRadioOn | WwanRadioOn |

The miniport driver should send all applicable status indications such as
NDIS_STATUS_WWAN_CONTEXT_STATE, NDIS_STATUS_WWAN_PACKET_SERVICE, and NDIS_STATUS_WWAN_REGISTER_STATE
whenever the effective radio state changes from
**WwanRadioOn** to
**WwanRadioOff** or from
**WwanRadioOff** to
**WwanRadioOn**.

## See also

[NDIS_WWAN_RADIO_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_radio_state)

[WWAN_RADIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_radio)