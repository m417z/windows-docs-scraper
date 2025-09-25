# RSVP_MSG_OBJS structure

## Description

The
**RSVP_MSG_OBJS** structure contains RSVP message objects.

## Members

### `RsvpMsgType`

RSVP message type.

### `pRsvpSession`

Pointer to an [RSVP_SESSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvp_session) object containing an RSVP session object.

### `pRsvpFromHop`

Pointer to an [RSVP_HOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvp_hop) structure indicating the hop from which the message has come.

### `pRsvpToHop`

Pointer to an [RSVP_HOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvp_hop) structure indicating the hop to which the message shall be sent.

### `pResvStyle`

Reservation style, expressed as a [RESV_STYLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-resv_style) structure.

### `pRsvpScope`

Scope of the reservation message.

### `FlowDescCount`

Number of flow descriptors in the message.

### `pFlowDescs`

Pointer to the first [FLOW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-flow_desc) structure in the message.

### `PdObjectCount`

Number of policy data objects in the message.

### `ppPdObjects`

Pointer to the first [POLICY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-policy_data) structure in the message.

### `pErrorSpec`

Pointer to an [ERROR_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-error_spec) structure containing an error message.

### `pAdspec`

Pointer to an [ADSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-adspec) structure containing an Adspec message.

## See also

[ADSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-adspec)

[ERROR_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-error_spec)

[FLOW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-flow_desc)

[POLICY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-policy_data)

[RESV_STYLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-resv_style)

[RSVP_HOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvp_hop)

[RSVP_SESSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvp_session)