# EapHostPeerSetResponseAttributes function

## Description

Provides updated EAP authentication attributes to EAPHost.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `pAttribs` [in]

A pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure that contains an array of new EAP authentication response attributes to set for the supplicant on EAPHost.

### `pEapOutput` [out]

A pointer to an [EapHostPeerResponseAction](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) enumeration value that specifies the action code for the next step the supplicant must take as a response.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## Remarks

To progress to the next step in the state machine after a call to [EapHostPeerGetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresponseattributes), the supplicant must call **EapHostPeerSetResponseAttributes**. The supplicant must do so to pass a valid [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) structure, even if the supplicant cannot use the attributes
returned from **EapHostPeerGetResponseAttributes**.

The following example shows a **EapHostPeerSetResponseAttributes** call that is made solely to progress to the next state in the state machine.

``` syntax
EapHostPeerGetResponseAttributes(session_id, &eapAttributes, ppEapError);

// overwrite attributes returned by EapHostPeerGetResponseAttributes
EapAttributes eapAttributes={0,NULL};

// progress to the next state in the state machine
EapHostPeerSetResponseAttributes(session_id, &eapAttributes, pEapOutput, ppEapError);
```

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerGetResponseAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresponseattributes)