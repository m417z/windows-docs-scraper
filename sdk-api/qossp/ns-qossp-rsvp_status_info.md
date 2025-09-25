# RSVP_STATUS_INFO structure

## Description

The QOS object
**RSVP_STATUS_INFO** provides information regarding the status of RSVP for a given flow, including event notifications associated with monitoring FD_QOS events, as well as error information.
**RSVP_STATUS_INFO** is useful for storing RSVP-specific status and error information.

## Members

### `ObjectHdr`

The QOS object
**QOS_OBJECT_HDR**.

### `StatusCode`

Status information. See Winsock2.h for more information.

### `ExtendedStatus1`

Mechanism for storing or returning provider-specific status information. The *ExtendedStatus1* parameter is used for storing a higher-level, or generalized error code, and is augmented by finer-grained error information provided in ExtendedStatus2.

### `ExtendedStatus2`

Additional mechanism for storing or returning provider-specific status information. Provides finer-grained error information compared to the generalized error information provided in *ExtendedStatus1*.

## Remarks

When applications register their interest in FD_QOS events (see
[QOS Events](https://learn.microsoft.com/previous-versions/aa374065(v=vs.80))), event and error information is associated with the event in the form of the
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure that is associated with the event. For more detailed information associated with that event, applications can investigate the **RSVP_STATUS_INFO** object that is provided in
[the ProviderSpecific buffer](https://learn.microsoft.com/previous-versions/aa374467(v=vs.80)) of the event-associated
**QOS** structure.

## See also

[ProviderSpecific Buffer](https://learn.microsoft.com/previous-versions/aa374467(v=vs.80))

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)