# RSVP_ADSPEC structure

## Description

[The RSVP_ADSPEC QOS object is not supported except on Windows 2000. RSVP signaling is not supported except on Windows 2000.]

The QOS object
**RSVP_ADSPEC** provides a means by which information describing network devices along the data path between sender and receiver, pertaining to RSVP functionality and available services, is provided or retrieved.

## Members

### `ObjectHdr`

The QOS object
**QOS_OBJECT_HDR**.

### `GeneralParams`

An [AD_GENERAL_PARAMS](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-ad_general_params) structure that provides general characterization parameters for the flow. Information includes RSVP-enabled hop count, bandwidth and latency estimates, and the path's MTU.

### `NumberOfServices`

Provides a count of the number of services available.

### `Services`

A [CONTROL_SERVICE](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-control_service) array, its element count based on **NumberOfServices**, which provides information about the services available along the data path between the sender and receiver of a given flow.

## See also

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)