# RSVP_POLICY_INFO structure

## Description

The **RSVP_POLICY_INFO** structure stores undefined policy elements retrieved from RSVP.

## Members

### `ObjectHdr`

QOS object header that specifies the size and length of the QOS object.

### `NumPolicyElement`

Number of policy elements in **PolicyElement**.

### `PolicyElement`

List of policy elements received, in the form of a [RSVP_POLICY](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_policy) structure.

## See also

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)

[RSVP_POLICY](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_policy)