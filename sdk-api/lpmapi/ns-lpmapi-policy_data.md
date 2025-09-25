# POLICY_DATA structure

## Description

The
**POLICY_DATA** structure contains policy data for RSVP messages.

## Members

### `PolicyObjHdr`

Policy object header, in the form of an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `usPeOffset`

Offset to the beginning of Policy Elements from the beginning of Policy Data.

### `usReserved`

Reserved. Do not use.

## See also

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)