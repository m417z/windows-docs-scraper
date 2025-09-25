# RSVP_POLICY structure

## Description

The **RSVP_POLICY** structure stores one or more undefined policy elements.

## Members

### `Len`

Size of the entire element object, in bytes.

### `Type`

Type of RSVP policy element in **Info**.

### `Info`

Policy data, expressed in UCHARs.

## Remarks

RSVP transports the data contained in an **RSVP_POLICY** structure on behalf of the Policy Control component.

## See also

[RSVP_POLICY_INFO](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_policy_info)