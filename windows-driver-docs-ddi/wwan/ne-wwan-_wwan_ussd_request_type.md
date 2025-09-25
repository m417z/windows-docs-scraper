# _WWAN_USSD_REQUEST_TYPE enumeration

## Description

The WWAN_USSD_REQUEST_TYPE enumeration lists the different types of Unstructured Supplementary Service Data (USSD) session requests.

## Constants

### `WwanUssdRequestInitiate`

Indicates a request to create a new USSD session and to transmit the accompanying USSD string.

### `WwanUssdRequestContinue`

Indicates a request to send the accompanying USSD string using the existing USSD session.

### `WwanUssdRequestCancel`

Indicates a request to terminate the existing USSD session.

## Remarks

The USSD protocol only allows a single USSD session at any time. If the miniport driver receives a *WwanUssdRequestInitiate* request to create a new USSD session when one already exists, the miniport driver must fail the request and specify *WwanUssdEventOtherLocalClient* as the reason.

When responding to a *WwanUssdRequestCancel* request, miniport drivers must return *WwanUssdEventTerminated* as the reason even if no session existed (which may happen during a concurrent release of the session from the network and the local client). The content of the accompanying USSD string must be ignored for WwanUssdRequestCancel requests and the string length should be set to zero to indicate that there is no accompanying USSD string.