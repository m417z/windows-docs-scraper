# TELEPHONY_CALLSTATE enumeration

## Description

The **TELEPHONY_CALLSTATE** enumeration defines constants that specify the state of a phone call.

## Constants

### `TELEPHONY_CALLSTATE_DISABLED`

Specifies that the phone call is disabled.

### `TELEPHONY_CALLSTATE_ENABLED`

Specifies that the phone call is enabled. This constant is set in a number of situations. For example, it will be set by the audio driver when the provider change operation is **TELEPHONY_PROVIDERCHANGEOP_END** and when **TELEPHONY_CALLCONTROLOP_ENABLE** is received.

### `TELEPHONY_CALLSTATE_HOLD`

Specifies that the phone call is on hold.

### `TELEPHONY_CALLSTATE_PROVIDERTRANSITION`

Specifies that the phone call is disabled. This constant is set by the audio driver when the provider change operation is **TELEPHONY_PROVIDERCHANGEOP_BEGIN**.

## See also

[KSTELEPHONY_CALLINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_tagkstelephony_callinfo)

[TELEPHONY_PROVIDERCHANGEOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-telephony_providerchangeop)