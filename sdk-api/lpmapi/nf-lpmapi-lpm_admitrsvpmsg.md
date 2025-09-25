# LPM_AdmitRsvpMsg function

## Description

The
*LPM_AdmitRsvpMsg* function is called by the PCM to pass RSVP messages to the LPM for policy based–admission control decisions. Results from calling
*LPM_AdmitRsvpMsg* can be passed back to the PCM either synchronously or asynchronously by setting the return value appropriately. Asynchronous results should be returned by calling the
[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult) function.

## Parameters

### `PcmReqHandle` [in]

Unique handle that identifies this request from all other requests. LPMs must pass this handle to the PCM when returning results asynchronously for an individual request by calling
[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult). The *PcmReqHandle* parameter becomes invalid once results are returned, requiring each request to get its own unique *PcmReqHandle* from the PCM.

### `pRecvdIntf` [in]

Pointer to the interface on which the message was received. The received interface IP address is supplied as the RSVP HOP object, and the Logical Interface Handle is set to the SNMP Index. Note that interface index numbers can change with the addition and deletion of interfaces, due to the Plug and Play features of Windows 2000.

### `pRsvpMsgObjs` [in]

Objects received from RSVP. The SBM unpacks received RSVP messages into individual objects and converts the contents of such RSVP objects into host order, and supplies them in the **RSVP_MSG_OBJS** structure, which is defined in Lpmapi.h. The following objects are supplied.

### `RcvdRsvpMsgLength` [in]

Length of the received RSVP message, in bytes.

| Value | Meaning |
| --- | --- |
| **RsvpMsgType** | RSVP message type, as defined by the RSVP protocol. |
| **RsvpSession** | Pointer to the RSVP session, as defined by the RSVP protocol. Note that contents are in host order. |
| **RsvpFromHop** | Pointer to the hop from which the RSVP message was received. Note that contents are in host order. |
| **RsvpScope** | Pointer to the RSVP scope object. |
| **RsvpStyle** | Pointer to the RSVP reservation style, as defined by the RSVP protocol. Note that contents are in host order. |
| **FlowDescListCount** | Number of flow descriptors. |
| **FlowDescList** | Array of flow descriptor pointers. |
| **PolicyDataCount** | Number of policy data objects. |
| **PolicyDataObjects** | Array of policy data object pointers. Note that only the RSVP object header and the policy options are converted to host order, but policy element headers as well as contents are left in network order; the PCM cannot convert the latter to host order, because the PCM cannot parse policy elements. Note that the Microsoft-provided LPM, Msidlpm.dll, does reorder policy element content into host order. |
| **ErrorSpec** | Pointer to the received RSVP ERROR_SPEC object. |

### `RcvdRsvpMsg` [in]

RSVP message, in network order.

### `pulPcmActionFlags` [out]

Flags used to specify an action requested of the PCM. The LPM can currently set this parameter to FORCE_IMMEDIATE_REFRESH to request an immediate refresh of the message being admitted. An LPM can set this flag if a change in policy data is detected that it wants to forward immediately. Before sending, the SBM asks the LPM to supply policy information for the outgoing refresh message.

Note that LPMs do not need to set this flag when a new PATH message is being accepted; SBMs automatically send the new PATH message toward receivers.

### `pPolicyDecisions` [out]

Pointer to policy decisions. An LPM must allocate this buffer using the memory allocator supplied in the
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) function call; the SBM frees the buffer after acting on *pPolicyDecisions*. The PCM looks at *pPolicyDecisions* only when the function returns LPM_RESULT_READY. Synchronous policy decisions must be returned for each flow in *FlowDescList*, and the number of entries in the *pPolicyDecisions* array must be equal to *FlowDescListCount*. Each policy decision consists of the values shown in the following table.

| Value | Meaning |
| --- | --- |
| **LpmPriorityValue** | Pointer to a buffer to receive the LPM Priority Value from the LPM. Note that the PCM will only look at this parameter if the return value of *LPM_AdmitRsvpMsg* is set to LPM_RESULT_READY. If the LPM is returning results synchronously, this parameter must be set to a valid priority value. See [Local Policy Module](https://learn.microsoft.com/previous-versions/windows/desktop/qos/local-policy-module) for more information. |
| **PolicyErrorCode** | Pointer to a policy error code. If the request is being rejected synchronously, LPMs must provide a nonzero value for this parameter; the SBM will copy this value, in combination with *PolicyErrorValue*, into the RSVP error object when sending PATHERR or RESVERR messages (as the result of policy based–admission control failure, to provide a reason for rejecting the request). |
| **PolicyErrorValue** | Pointer to a policy error value. If the request is being rejected synchronously, LPMs must provide a nonzero value for this parameter; the SBM will copy this value, in combination with *PolicyErrorCode*, into the RSVP error object when sending PATHERR or RESVERR messages (as the result of policy based–admission control failure, to provide a reason for rejecting the request). |

Since an LPM's return POLICY_DECISION is an array, an LPM can accept a subset of flows in *FlowDescList* and reject the rest of them, if appropriate. For example, since FF style RESV messages can contain multiple flows, when an LPM rejects some flows and accepts others, the SBM generates a separate RESVERR message for each rejected flow; before sending the RESVERR message, PCM calls each LPM to supply policy data objects for each outgoing RESVERR message.

### `Reserved` [out]

Reserved for future use.

## Return value

This function returns ULONG.

## Remarks

The Subnet Bandwidth Manager (SBM) forwards RSVP PATH, RESV, PATHERR, RESVERR, PATH_TEAR, and RESV_TEAR messages to the PCM. If a request passes LPM policy–based admission (in which case the success status is passed up through the PCM to the SBM), the SBM performs resource based–admission control as part of its RSVP processing; if resource based–admission control fails, the SBM will instruct the PCM to instruct each LPM to delete its state through the
[LPM_CommitResv](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_commitresv) function. In such circumstances, the SBM (and not the LPMs) will create the requisite RSVP error message.

## See also

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)

[cbAdmitResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbadmitresult)

[cbGetRsvpObjects](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nc-lpmapi-cbgetrsvpobjects)