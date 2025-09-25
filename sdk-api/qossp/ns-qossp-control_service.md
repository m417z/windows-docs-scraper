# CONTROL_SERVICE structure

## Description

The **CONTROL_SERVICE** structure contains supported RSVP service types.

## Members

### `Length`

Length of the entire structure, in bytes.

### `Service`

The supported service type. Must be one of the following:

| Value | Meaning |
| --- | --- |
| **SERVICETYPE_NOTRAFFIC** | No data is being sent in this direction. |
| **SERVICETYPE_BESTEFFORT** | Best Effort service. |
| **SERVICETYPE_CONTROLLEDLOAD** | Controlled Load service. |
| **SERVICETYPE_GUARANTEED** | Guaranteed service. |
| **SERVICETYPE_NETWORK_UNAVAILABLE** | This service type is used to notify the user that the network is unavailable. |
| **SERVICETYPE_GENERAL_INFORMATION** | This service type corresponds to General Parameters, as defined by IntServ (the Integrated Services Working Group in the IETF). |
| **SERVICETYPE_NOCHANGE** | This specifies that the flow specification contains no changes from the previous specification. |
| **SERVICETYPE_NONCONFORMING** | Specifies non-conforming traffic. |
| **SERVICETYPE_NETWORK_CONTROL** | Specifies network control traffic. |
| **SERVICETYPE_QUALITATIVE** | Qualitative service. |

### `Overrides`

Specifies overrides to service specifications, expressed in the form of an [AD_GENERAL_PARAMS](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-ad_general_params) structure.

### `Guaranteed`

Specifies guaranteed service, and provides service parameters in the form of an **AD_GUARANTEED** structure.

### `ParamBuffer`

Describes the buffer used, in the form of a [PARAM_BUFFER](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-param_buffer) structure.

## Remarks

The **Length** value can be added to the pointer to the structure to obtain the pointer to the next **CONTROL_SERVICE** structure in the list, until the **NumberOfServices** member of the [RSVP_ADSPEC](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_adspec) structure is exhausted.

## See also

[PARAM_BUFFER](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-param_buffer)

[RSVP_ADSPEC](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_adspec)