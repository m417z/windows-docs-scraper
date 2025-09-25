# TcAddFlow function

## Description

The
**TcAddFlow** function adds a new flow on the specified interface. Note that the successful addition of a flow does not necessarily indicate a change in the way traffic is handled; traffic handling changes are effected by attaching a filter to the added flow, using the
[TcAddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddfilter) function.

Traffic control clients that have registered an **AddFlowComplete** handler (a mechanism for allowing traffic control to call the
[ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler) callback function in order to alert clients of completed flow additions) can expect a return value of ERROR_SIGNAL_PENDING. For more information, see
[Traffic Control Objects](https://learn.microsoft.com/previous-versions/windows/desktop/qos/traffic-control-objects).

## Parameters

### `IfcHandle` [in]

Handle associated with the interface on which the flow is to be added. This handle is obtained by a previous call to the
[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea) function.

### `ClFlowCtx` [in]

Client provided–flow context handle. Used subsequently by traffic control when referring to the added flow.

### `Flags` [in]

Reserved for future use. Must be set to zero.

### `pGenericFlow` [in]

Pointer to a description of the flow being installed.

### `pFlowHandle` [out]

Pointer to a location into which traffic control will return the flow handle. This flow handle should be used in subsequent calls to traffic control to refer to the installed flow.

## Return value

There are many reasons why a request to add a flow might be rejected. Error codes returned by traffic control from calls to
**TcAddFlow** are provided to aid in determining the reason for rejection.

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_SIGNAL_PENDING** | The function is being executed asynchronously; the client will be called back through the client-exposed [ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler) function when the flow has been added or when the process has been completed. |
| **ERROR_INVALID_HANDLE** | The interface handle is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_INVALID_SERVICE_TYPE** | An unspecified or bad **INTSERV** service type has been provided. |
| **ERROR_INVALID_TOKEN_RATE** | An unspecified or bad TOKENRATE value has been provided. |
| **ERROR_INVALID_PEAK_RATE** | The PEAKBANDWIDTH value is invalid. |
| **ERROR_INVALID_SD_MODE** | The SHAPEDISCARDMODE is invalid. |
| **ERROR_INVALID_QOS_PRIORITY** | The priority value is invalid. |
| **ERROR_INVALID_TRAFFIC_CLASS** | The traffic class value is invalid. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are not enough resources to accommodate the requested flow. |
| **ERROR_TC_OBJECT_LENGTH_INVALID** | Bad length specified for the TC objects. |
| **ERROR_INVALID_DIFFSERV_FLOW** | Applies to Diffserv flows. Indicates that the [QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv) object was passed with an invalid parameter. |
| **ERROR_DS_MAPPING_EXISTS** | Applies to Diffserv flows. Indicates that the QOS_DIFFSERV_RULE specified in [TC_GEN_FLOW](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_flow) already applies to an existing flow on the interface. |
| **ERROR_INVALID_SHAPE_RATE** | The [QOS_SHAPING_RATE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_shaping_rate) object was passed with an invalid **ShapingRate** member. |
| **ERROR_INVALID_DS_CLASS** | The QOS_DS_CLASS is invalid. |
| **ERROR_NETWORK_UNREACHABLE** | The network cable is not plugged into the adapter. |

## Remarks

If the
**TcAddFlow** function returns ERROR_SIGNAL_PENDING, the
[ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler) function will be called on a different thread than the thread that called the
**TcAddFlow** function.

Only the addition of a filter will affect traffic control. However, the addition of a flow will cause resources to be committed within traffic control components. This enables traffic control to prepare for handling traffic on the added flow.

Traffic control may delete a flow for various reasons, including the inability to accommodate the flow due to bandwidth restrictions, and adjusted policy requirements. Clients are notified of deleted flows through the
[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler) callback function, with the TC_NOTIFY_FLOW_CLOSE event.

**Note** Use of the
**TcAddFlow** function requires administrative privilege.

## See also

[ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler)

[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler)

[TC_GEN_FLOW](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_flow)

[TcAddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddfilter)

[TcOpenInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcopeninterfacea)