# TELEPHONY_PROVIDERCHANGEOP enumeration

## Description

The **TELEPHONY_PROVIDERCHANGEOP** enumeration defines constants that specify the requested provider change operation.

## Constants

### `TELEPHONY_PROVIDERCHANGEOP_END`

Specifies that the provider change operation has ended. The audio driver will update the call state to **TELEPHONY_CALLSTATE_ENABLED** in response to this value.

### `TELEPHONY_PROVIDERCHANGEOP_BEGIN`

Specifies that the provider change operation has begun. The audio driver will update the call state to **TELEPHONY_CALLSTATE_PROVIDERTRANSITION** in response to this value.

### `TELEPHONY_PROVIDERCHANGEOP_CANCEL`

Specifies that single-radio voice call continuity (SRVCC) is being canceled, and that the audio driver should revert back to the pre-SRVCC state. The audio driver will update the provider call state to TELEPHONY_CALLSTATE_ENABLED in response to this value.

## See also

[KSPROPERTY_TELEPHONY_PROVIDERCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-telephony-providerchange)

[TELEPHONY_CALLSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-telephony_callstate)