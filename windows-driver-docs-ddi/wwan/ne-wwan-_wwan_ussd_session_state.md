# _WWAN_USSD_SESSION_STATE enumeration

## Description

The WWAN_USSD_SESSION_STATE enumeration lists the different types of USSD session states.

## Constants

### `WwanUssdSessionStateNew`

The USSD string is the first message of a USSD session.

### `WwanUssdSessionStateExisting`

The USSD string is not the first message of a USSD session.

## Remarks

Miniport drivers use the WWAN_USSD_SESSION_STATE enumeration to indicate whether a USSD string is the first message of a USSD session. Miniport drivers must use *WwanUssdSessionStateNew* for the first message of a network-initiated USSD session. Miniport drivers should use *WwanUssdSessionStateExisting* in all other cases.