# WsGetPolicyAlternativeCount function

## Description

Retrieves the number of alternatives available in the policy object.
The alternative count can be used to loop through each alternative using
[WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative).

**Note** The policy object may delay some processing until this function is called. If the
processing fails, then the policy object will be set to
**WS_POLICY_STATE_FAULTED** state.

## Parameters

### `policy` [in]

A pointer to the [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) object from which to count alternatives.

### `count` [out]

A pointer to the number value of alternatives. This may be 0.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

Note that each alternative is not guaranteed to be unique within the policy
(there may be duplicates).