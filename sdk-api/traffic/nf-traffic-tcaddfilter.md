# TcAddFilter function

## Description

The
**TcAddFilter** function associates a new filter with an existing flow that allows packets matching the filter to be directed to the associated flow.

Filters include a pattern and a mask. The pattern specifies particular parameter values, while the mask specifies which parameters and parameter subfields apply to a given filter. When a pattern/mask combination is applied to a set of packets, matching packets are directed to the flow to which the corresponding filter is associated.

Traffic control returns a handle to the newly added filter, in the pFilterHandle parameter, by which clients can refer to the added filter. Pending flows, such as those processing a
[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) or
[TcModifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcmodifyflow) request for which a callback routine has not been completed, cannot have filters associated to them; only flows that have been completed and are stable can apply associated filters.

The relationship between filters and flows is many to one. Multiple filters can be applied to a single flow; however, a filter can only apply to one flow. For example, flow A can have filters X, Y and Z applied to it, but as long as flow A is active, filters X, Y and Z cannot apply to any other flows.

## Parameters

### `FlowHandle` [in]

Handle for the flow, as received from a previous call to the
[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow) function.

### `pGenericFilter` [in]

Pointer to a description of the filter to be installed.

### `pFilterHandle` [out]

Pointer to a buffer where traffic control returns the filter handle. This filter handle is used by the client in subsequent calls to refer to the added filter.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | The flow handle is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_INVALID_ADDRESS_TYPE** | An invalid address type has been provided. |
| **ERROR_DUPLICATE_FILTER** | An identical filter exists on a flow on this interface.<br><br>**Note** In Windows Vista, this code will not be returned. |
| **ERROR_FILTER_CONFLICT** | A conflicting filter exists on a flow on this interface.<br><br>**Note** In Windows Vista, this code will not be returned. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system is out of memory. |
| **ERROR_NOT READY** | The flow is either being installed, modified, or deleted, and is not in a state that accepts filters. |

## Remarks

Filters can be of different types. They are typically used to filter packets belonging to different network layers. Filter types installed on an interface generally correspond to the address types of the network layer addresses associated with the interface. The address type should be specified in the filter structure.

Filters may be rejected for various reasons, including possible conflicts with the requested filter as well as filters already associated with the flow. Error codes specific to traffic control are provided to help the user diagnose the reason behind a rejection to the
**TcAddFilter** function.

**Note** Use of the
**TcAddFilter** function requires administrative privilege.

In Windows Vista, overlapping and identical filters can be created. In these situations, the more specific filter takes precedence.

## See also

[TcAddFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddflow)