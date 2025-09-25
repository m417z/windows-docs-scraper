# WsMatchPolicyAlternative function

## Description

Verifies that a Policy Alternative is compatible
with the specified Policy Constraint. If the alternative is compatible the constraint structures are populated with Policy information.

**Note** See Remarks on this page for information on the constraint structures.

## Parameters

### `policy` [in]

A pointer to a [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) object containing the alternative.

**Note** Each [WS_METADATA_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_endpoint) that is returned from [WsGetMetadataEndpoints](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmetadataendpoints) contains a policy object.

### `alternativeIndex` [in]

Specifies the zero-based index that identifies the alternative to use within the policy object. The number of alternatives present in the policy object can be obtained using [WsGetPolicyAlternativeCount](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetpolicyalternativecount).

### `policyConstraints` [in]

A pointer to the constraints that specify policies to match along with the fields to populate if the function returns NOERROR.

**Note** If a property constraint is not specified the default constraint value for that particular property is used.

See [WS_POLICY_CONSTRAINTS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_policy_constraints) for more information.

### `matchRequired` [in]

Indicates whether a match is required or not.

**Note** If the value is **FALSE** a match is not required, and in conjunction with a non-matching policy alternative, the function returns S_FALSE.

If the value of this parameter is **TRUE** a match is required, and if the policy does not match, the function returns an error.

### `heap` [in]

A pointer to a [Heap](https://learn.microsoft.com/windows/desktop/wsw/heap) object used to store any data requiring allocation beyond the specified constraint.

**Note** For example pointer types within the constraint "out" fields is allocated using this Heap.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_FORMAT** | The policy alternative does not meet the specified constraints and matchRequired was set to **TRUE**.<br><br>The policy or other metadata was in an invalid format. |
| **S_FALSE** | The policy alternative does not meet the specified constraints and matchRequired was set to **FALSE**. |
| **S_OK** | The policy alternative meets the specific constraints. The **out** fields of the constraints structures have been filled with values from the policy. |

## Remarks

Each of these data types contain a struct field called "out".

* [WS_CHANNEL_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_channel_property_constraint)
* [WS_SECURITY_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_property_constraint)
* [WS_SECURITY_BINDING_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_security_binding_property_constraint)
* [WS_SSL_TRANSPORT_SECURITY_BINDING_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_ssl_transport_security_binding_constraint)

The content of the **out** field of these structures is populated by this function if the call returns NOERROR.

**Note** If the function call fails the content **out** may have been partially set and only some allocations may have been made from the specified heap object. The content of the **out** field must not be examined unless the function returns NOERROR.

The policy object may delay some processing until this function is called. If the processing fails the policy object is set to **WS_POLICY_STATE_FAULTED**.