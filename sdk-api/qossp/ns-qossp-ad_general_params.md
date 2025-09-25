# AD_GENERAL_PARAMS structure

## Description

The **AD_GENERAL_PARAMS** structure contains the General Characterization Parameters contained in the RSVP Adspec object.

## Members

### `IntServAwareHopCount`

Number of hops that conform to Integrated Services (INTSERV) requirements.

### `PathBandwidthEstimate`

Minimum bandwidth available from sender to receiver.

### `MinimumLatency`

Sum of the minimum latency of the packet forwarding process in routers, in milliseconds. Can be set to INDETERMINATE_LATENCY.

### `PathMTU`

Maximum Transmission Unit (MTU) for the end-to-end path between sender and receiver that will not incur packet fragmentation.

### `Flags`

Flags associated with the parameters. The following flag is supported:

| Value | Meaning |
| --- | --- |
| **AD_FLAG_BREAK_BIT** | Indicates the existence of a network element in the data path that does not support QOS control services. When set in a specific service override, indicates QOS service was not supported on at least one hop. |

## See also

[RSVP_ADSPEC](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_adspec)