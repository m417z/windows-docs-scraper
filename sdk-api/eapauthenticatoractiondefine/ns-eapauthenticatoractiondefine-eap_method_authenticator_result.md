# EAP_METHOD_AUTHENTICATOR_RESULT structure

## Description

Contains authentication results returned by an EAP authenticator method.

## Members

### `fIsSuccess`

If **TRUE**, the supplicant was successfully authenticated; if **FALSE**, it was not.

### `dwFailureReason`

Contains a reason code if the supplicant could not be authenticated. Reason codes are generally expected to originate from winerror.h.

### `pAuthAttribs`

A pointer to an [EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains the EAP attributes returned by the authentication session.

## See also

[EAPHost Authenticator Method Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-structures)