# TcModifyFlow function

## Description

The
**TcModifyFlow** function modifies an existing flow. When calling
**TcModifyFlow**, new *Flowspec* parameters and any traffic control objects should be filled.

Traffic control clients that have registered a ModifyFlowComplete handler (a mechanism for allowing traffic control to call the
[ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler) callback function in order to alert clients of completed flow modifications) can expect a return value of ERROR_SIGNAL_PENDING.

## Parameters

### `FlowHandle` [in]

Handle for the flow, as received from a previous call to the
[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) function.

### `pGenericFlow` [in]

Pointer to a description of the flow modifications.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_SIGNAL_PENDING** | The function is being executed asynchronously; the client will be called back through the client-exposed [ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler) function when the flow has been added, or when the process has been completed. |
| **ERROR_INVALID_HANDLE** | The interface handle is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_NOT_READY** | Action performed on the flow by a previous function call to the [TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow), [TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow), or [TcDeleteFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcdeleteflow) has not yet completed. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_INVALID_SERVICE_TYPE** | An unspecified or bad intserv service type has been provided. |
| **ERROR_INVALID_TOKEN_RATE** | An unspecified or bad *TokenRate* value has been provided. |
| **ERROR_INVALID_PEAK_RATE** | The *PeakBandwidth* value is invalid. |
| **ERROR_INVALID_SD_MODE** | The *ShapeDiscardMode* is invalid. |
| **ERROR_INVALID_QOS_PRIORITY** | The priority value is invalid. |
| **ERROR_INVALID_TRAFFIC_CLASS** | The traffic class value is invalid. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are not enough resources to accommodate the requested flow. |
| **ERROR_TC_OBJECT_LENGTH_INVALID** | Bad length specified for the TC objects. |
| **ERROR_INVALID_DIFFSERV_FLOW** | Applies to Diffserv flows. Indicates that the [QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv) object was passed with an invalid parameter. |
| **ERROR_DS_MAPPING_EXISTS** | Applies to Diffserv flows. Indicates that the [QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule) specified in [TC_GEN_FLOW](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-tc_gen_flow) already applies to an existing flow on the interface. |
| **ERROR_INVALID_SHAPE_RATE** | The [QOS_SHAPING_RATE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_shaping_rate) was passed with an invalid ShapeRate. |
| **ERROR_INVALID_DS_CLASS** | [QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class) is invalid. |
| **ERROR_NETWORK_UNREACHABLE** | The network cable is not plugged into the adapter. |

## Remarks

If the
**TcModifyFlow** function returns ERROR_SIGNAL_PENDING, the
[ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler) function will be called on a different thread than the thread that called the
**TcModifyFlow** function.

**Note** Use of the
**TcModifyFlow** function requires administrative privilege.

## See also

[ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler)

[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow)

[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows)