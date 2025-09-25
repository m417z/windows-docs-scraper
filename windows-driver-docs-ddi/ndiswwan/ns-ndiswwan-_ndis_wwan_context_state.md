# _NDIS_WWAN_CONTEXT_STATE structure

## Description

The NDIS_WWAN_CONTEXT_STATE structure represents the Packet Data Protocol (PDP) context state of the
MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_CONTEXT_STATE structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Windows 8 miniport drivers should set this to NDIS_WWAN_CONTEXT_STATE_REVISION_2. Windows 7 miniport drivers should set this to NDIS_WWAN_CONTEXT_STATE_REVISION_1. |
| Size | sizeof(NDIS_WWAN_CONTEXT_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of context activation or deactivation operation. The following table shows the possible
values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Context activation or deactivation succeeded. |
| WWAN_STATUS_FAILURE | The operation failed. Miniport drivers can return this value if the context has already been activated. |
| WWAN_STATUS_PIN_REQUIRED | The operation failed because the device requires a PIN. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |
| WWAN_STATUS_SIM_NOT_INSERTED | The operation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |

Miniport drivers can return the following error codes (in addition to those previously described)
only in the event of a failed set PDP activation operation.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_RADIO_POWER_OFF | The operation failed because the radio is currently turned off. This error code should be returned only in response to a OID_WWAN_CONNECT *set* request. If the radio state is off then the miniport driver should respond to OID_WWAN_CONNECT *query* requests with WWAN_STATUS_SUCCESS and specify the current context state as **WwanActivationStateDeactivated**. |
| WWAN_STATUS_SERVICE_NOT_ACTIVATED | The operation failed because either the subscription has expired, or the device does not allow PDP activation. |
| WWAN_STATUS_PROVIDER_NOT_VISIBLE | The operation failed because the service provider is not currently visible. |
| WWAN_STATUS_MAX_ACTIVATED_CONTEXTS | The operation failed because the maximum number of activated contexts has been reached. |
| WWAN_STATUS_INVALID_ACCESS_STRING | The operation failed because the access string is invalid. |
| WWAN_STATUS_INVALID_USER_NAME_PWD | The operation failed because the user name and/or password supplied are invalid. Network specific error code may be available in **uNwError** . |
| WWAN_STATUS_PACKET_SVC_DETACHED | The operation failed because packet service is detached. |
| WWAN_STATUS_NOT_REGISTERED | The operation failed because the device is not in the registered state to perform PDP activation. |
| WWAN_STATUS_VOICE_CALL_IN_PROGRESS | The operation failed and cannot proceed with PDP activation because a voice call is currently in progress. This value applies only to devices with voice class is set to **WwanVoiceClassSeparateVoiceData**. |
| WWAN_STATUS_CONTEXT_NOT_ACTIVATED | The operation failed because the context identified by **ConnectionId** is not the currently activated context. |

### `ContextState`

A formatted
[WWAN_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_state) object that
represents the Packet Data Protocol (PDP) context state of the device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_CONTEXT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_state)