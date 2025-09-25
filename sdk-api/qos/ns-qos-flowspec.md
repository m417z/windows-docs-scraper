# FLOWSPEC structure

## Description

The
**FLOWSPEC** structure provides quality of service parameters to the
[RSVP SP](https://learn.microsoft.com/previous-versions/windows/desktop/qos/rsvp-service-provider). This allows QOS-aware applications to invoke, modify, or remove QOS settings for a given flow. Some members of
**FLOWSPEC** can be set to default values. See Remarks for more information.

## Members

### `TokenRate`

Specifies the permitted rate at which data can be transmitted over the life of the flow. The **TokenRate** member is similar to other token bucket models seen in such WAN technologies as Frame Relay, in which the token is analogous to a credit. If such tokens are not used immediately, they accrue to allow data transmission up to a certain periodic limit (**PeakBandwidth**, in the case of Windows 2000 quality of service). Accrual of credits is limited, however, to a specified amount (**TokenBucketSize**). Limiting total credits (tokens) avoids situations where, for example, flows that are inactive for some time flood the available bandwidth with their large amount of accrued tokens. Because flows may accrue transmission credits over time (at their **TokenRate** value) only up to the maximum of their **TokenBucketSize**, and because they are limited in burst transmissions to their **PeakBandwidth**, traffic control and network-device resource integrity are maintained.
[Traffic control](https://learn.microsoft.com/previous-versions/windows/desktop/qos/understanding-traffic-control) is maintained because flows cannot send too much data at once, and network-device resource integrity is maintained because such devices are spared high traffic bursts.

With this model, applications can transmit data only when sufficient credits are available. If sufficient credits are not available, the application must either wait or discard the traffic (based on the value of
[QOS_SD_MODE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_sd_mode)). Therefore, it is important that applications base their **TokenRate** requests on reasonable expectations for transmission requirements. For example, in video applications, **TokenRate** is typically set to the average bit rate from peak to peak.

If **TokenRate** is set to QOS_NOT_SPECIFIED on the receiver only, the maximum transmission unit (MTU) is used for **TokenRate**, and limits on the transmission rate (the token bucket model) will not be put into effect. Thus, **TokenRate** is expressed in bytes per second.

The **TokenRate** member cannot be set to zero. Nor can it be set as a default (that is, set to QOS_NOT_SPECIFIED) in a sending
**FLOWSPEC**.

### `TokenBucketSize`

The maximum amount of credits a given direction of a flow can accrue, regardless of time, in bytes. In video applications, **TokenBucketSize** will likely be the largest average frame size. In constant rate applications, **TokenBucketSize** should be set to allow for small variations.

### `PeakBandwidth`

The upper limit on time-based transmission permission for a given flow, in bytes per second. The **PeakBandwidth** member restricts flows that may have accrued a significant amount of transmission credits, or tokens from overburdening network resources with one-time or cyclical data bursts, by enforcing a per-second data transmission ceiling. Some intermediate systems can take advantage of this information, resulting in more efficient resource allocation.

### `Latency`

Maximum acceptable delay between transmission of a bit by the sender and its receipt by one or more intended receivers, in microseconds. The precise interpretation of this number depends on the level of guarantee specified in the QOS request.

### `DelayVariation`

Difference between the maximum and minimum possible delay a packet will experience, in microseconds. Applications use **DelayVariation** to determine the amount of buffer space needed at the receiving end of the flow. This buffer space information can be used to restore the original data transmission pattern.

### `ServiceType`

Specifies the level of service to negotiate for the flow. The **ServiceType** member can be one of the following defined service types.

| Value | Meaning |
| --- | --- |
| **SERVICETYPE_NOTRAFFIC** | Indicates that no traffic will be transmitted in the specified direction. On duplex-capable media, this value signals underlying software to set up unidirectional connections only. This service type is not valid for the TC API. |
| **SERVICETYPE_BESTEFFORT** | Results in no action taken by the RSVP SP. Traffic control does create a BESTEFFORT flow, however, and traffic on the flow will be handled by traffic control similarly to other BESTEFFORT traffic. |
| **SERVICETYPE_CONTROLLEDLOAD** | Provides an end-to-end QOS that closely approximates transmission quality provided by best-effort service, as expected under unloaded conditions from the associated network components along the data path. <br><br>Applications that use SERVICETYPE_CONTROLLEDLOAD may therefore assume the following:<br><br>* The network will deliver a very high percentage of transmitted packets to its intended receivers. In other words, packet loss will closely approximate the basic packet error rate of the transmission medium.<br>* Transmission delay for a very high percentage of the delivered packets will not greatly exceed the minimum transit delay experienced by any successfully delivered packet. |
| **SERVICETYPE_GUARANTEED** | Guarantees that datagrams will arrive within the guaranteed delivery time and will not be discarded due to queue overflows, provided the flow's traffic stays within its specified traffic parameters. This service is intended for applications that need a firm guarantee that a datagram will arrive no later than a certain time after it was transmitted by its source. |
| **SERVICETYPE_QUALITATIVE** | Indicates that the application requires better than BESTEFFORT transmission, but cannot quantify its transmission requirements. Applications that use SERVICETYPE_QUALITATIVE can supply an application identifier policy object. The application identification policy object enables policy servers on the network to identify the application, and accordingly, assign an appropriate quality of service to the request. For more information on application identification, consult the IETF Internet Draft draft-ietf-rap-rsvp-appid-00.txt, or the Microsoft white paper on Application Identification. Traffic control treats flows of this type with the same priority as BESTEFFORT traffic on the local computer. However, application programmers can get boosted priority for such flows by modifying the Layer 2 settings on the associated flow using the [QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class) QOS object. |
| **SERVICETYPE_NETWORK_UNAVAILBLE** | Used to notify network changes. |
| **SERVICETYPE_NETWORK_CONTROL** | Used only for transmission of control packets (such as RSVP signaling messages). This **ServiceType** has the highest priority. |
| **SERVICETYPE_GENERAL_INFORMATION** | Specifies that all service types are supported for a flow. Can be used on sender side only. |
| **SERVICETYPE_NOCHANGE** | Indicates that the quality of service in the transmission using this **ServiceType** value is not changed. SERVICETYPE_NOCHANGE can be used when requesting a change in the quality of service for one direction only, or when requesting a change only within the ProviderSpecific parameters of a QOS specification, and not in the **SendingFlowspec** or **ReceivingFlowspec**. |
| **SERVICETYPE_NONCONFORMING** | Used to indicate nonconforming traffic. |
| **SERVICE_NO_TRAFFIC_CONTROL** | Indicates that traffic control should not be invoked in the specified direction. |
| **SERVICE_NO_QOS_SIGNALING** | Suppresses RSVP signaling in the specified direction. |

The following list identifies the relative priority of **ServiceType** settings:

SERVICETYPE_NETWORK_CONTROL

SERVICETYPE_GUARANTEED

SERVICETYPE_CONTROLLED_LOAD

SERVICETYPE_BESTEFFORT

SERVICETYPE_QUALITATIVE

Non-conforming traffic

For a simple example, if a given network device were resource-bounded and had to choose among transmitting a packet from one of the above **ServiceType** settings, it would first send a packet of SERVICETYPE_NETWORKCONTROL, and if there were no packets of that **ServiceType** requiring transmission it would send a packet of **ServiceType** SERVICETYPE_GUARANTEED, and so on.

### `MaxSduSize`

Specifies the maximum packet size permitted or used in the traffic flow, in bytes.

### `MinimumPolicedSize`

Specifies the minimum packet size for which the requested quality of service will be provided, in bytes. Packets smaller than this size are treated by traffic control as **MinimumPolicedSize**. When using the **FLOWSPEC** structure in association with RSVP, the value of **MinimumPolicedSize** cannot be zero; however, if you are using the **FLOWSPEC** structure specifically with the TC API, you can set **MinimumPolicedSize** to zero.

## Remarks

Many members of the
**FLOWSPEC** structure can be set to default values by setting the member to QOS_NOT_SPECIFIED. Note that the members that can be set to default values differ depending on whether the
**FLOWSPEC** is a receiving
**FLOWSPEC** or a sending
**FLOWSPEC**.

There are a handful of considerations you should keep in mind when using
**FLOWSPEC** with traffic control:

* **TokenRate** can be QOS_NOT_SPECIFIED for SERVICETYPE_NETWORKCONTROL, SERVICETYPE_QUALITATIVE, and SERVICETYPE_BESTEFFORT. **TokenRate** must be valid for all other **ServiceType** values.
* If **PeakBandwidth** is specified, it must be greater than or equal to **TokenRate**.

Many settings can be defaulted in a receiving
**FLOWSPEC** except **ServiceType**, with the following considerations:

* For a Controlled Load Service receiver, the default values are derived from the sender **TSPEC**.
* For a Guaranteed Service receiver, **ServiceType** and **TokenRate** must be specified.

The following list specifies the values that are applied when a receiving
**FLOWSPEC** sets the corresponding values to default:

When the value of the **ServiceType** is set to SERVICETYPE_GUARANTEED, the following also applies:

* The RATE value in **RSPEC** is set to the value of *TokenRate*.
* The DELAYSLACKTERM value in **RSPEC** is set to *DelayVariation*, which is set to zero if *DelayVariation* is set to QOS_NOT_SPECIFIED.
* For receivers requesting SERVICETYPE_GUARANTEED, the receiving *TokenRate* must be specified. This contrasts with a SERVICETYPE_CONTROLLEDLOAD receiver, for which *TokenRate* may be set to QOS_NOT_SPECIFIED.

In a sending
**FLOWSPEC**, everything can be defaulted except **ServiceType** and **TokenRate**. The following list specifies the values that are applied when a sending
**FLOWSPEC** sets the corresponding values to default:

**Traffic Control:** The following **ServiceType**s are invalid when specifically working with Traffic Control. If you are unsure whether you are working directly with Traffic Control (and thereby need to be concerned about whether the following **ServiceType**s are applicable in your situation), you probably are not:

SERVICE_NO_TRAFFIC_CONTROL

SERVICE_NO_QOS_SIGNALING

SERVICETYPE_GENERAL_INFORMATION

SERVICETYPE_NETWORK_UNAVAILABLE

SERVICETYPE_NOCHANGE

SERVICETYPE_NOTRAFFIC

## See also

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)