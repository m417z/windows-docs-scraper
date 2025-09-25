# _tagKSTELEPHONY_PROVIDERCHANGE structure

## Description

The **KSTELEPHONY_PROVIDERCHANGE** structure specifies the phone call type and provider change operation to use for the [KSPROPERTY_TELEPHONY_PROVIDERCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-telephony-providerchange) property.

## Members

### `CallType`

Specifies the type of phone call (circuit-switched, LTE packet-switched, or WLAN packet-switched).

### `ProviderChangeOp`

Specifies the change operation requested by the provider (begin, end, or cancel).

## Remarks

The audio stack uses the KSTELEPHONY_PROVIDERCHANGE property to indicate the start and the end of SRVCC to the audio driver. This property communicates the call type (LTE packet-switched, WLAN packet-switched, or circuit-switched) and the provider change operation (begin, end, or cancel) to driver. The call type is ignored when the provider operation is for ending the SRVCC.

When the provider change operation is TELEPHONY_PROVIDERCHANGEOP_BEGIN, the driver updates that provider’s call state to TELEPHONY_CALLSTATE_PROVIDERTRANSITION. When the provider change operation is TELEPHONY_PROVIDERCHANGEOP_END, the driver updates that provider’s call state to TELEPHONY_CALLSTATE_ENABLED. During SRVCC, the driver must continue to use the associated KSNODETYPE_TELEPHONY_BIDI endpoint, and it does not change the jack states of this endpoint. When the provider change operation is TELEPHONY_PROVIDERCHANGEOP_CANCEL, SRVCC is being canceled, and the driver should revert back to a pre-SRVCC call.