# WS_POLICY_PROPERTY_ID enumeration

## Description

Identifies each policy property and its associated
value.

## Constants

### `WS_POLICY_PROPERTY_STATE:1`

This property is used with [WsGetPolicyProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetpolicyproperty).
It is of type [WS_POLICY_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_policy_state).

The current state of the policy object.

### `WS_POLICY_PROPERTY_MAX_ALTERNATIVES:2`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) when
specifying [WS_METADATA_PROPERTY_POLICY_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id) as part of the [WS_METADATA_PROPERTY*](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) parameter. It is of type **ULONG**.

This property controls the maximum number of alternatives
allowed for a given [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) object.

When a policy is processed, the amount of memory allocated
and CPU consumed is proportional to the number of policy
alternatives present in the policy, not to the actual size
of the policy. Even a small policy may contain a large number
of alternatives due to the expansion of different permutations
of assertions. Setting this property to a large
value may lead to excessive processing or memory consumption.

The default value is 32.

### `WS_POLICY_PROPERTY_MAX_DEPTH:3`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) when
specifying [WS_METADATA_PROPERTY_POLICY_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id).
It is of type **ULONG**.

This property controls the maximum depth of any policy that is
read and processed. The maximum depth of a policy is defined as the maximum
number of levels of nested container elements (**Policy**, **All**, **ExactlyOne**)
when considering the policy and any policies that it references.

A small amount of stack space is consumed for each level of
policy that is processed. Setting this value to a large
value may lead to stack overflow for a policy that is
deeply nested or contains a cyclic reference.

The default value is 32.

### `WS_POLICY_PROPERTY_MAX_EXTENSIONS:4`

This property is used with [WsCreateMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemetadata) when
specifying [WS_METADATA_PROPERTY_POLICY_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id).
It is of type **ULONG**.

This property controls the maximum number of policy extensions
(unknown assertions) allowed for a given [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) object.
Policy extensions can be retrieved by supplying [WS_POLICY_EXTENSION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_policy_extension)
array in [WS_POLICY_CONSTRAINTS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_policy_constraints) structure when using the
[WsMatchPolicyAlternative](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmatchpolicyalternative) API.

The default value is 8.

When a policy is processed, the amount of memory allocated
and CPU consumed is proportional to the number of policy
alternatives present in the policy, not to the actual size
of the policy. Even a small policy may contain a large number
of alternatives due to the expansion of different permutations
of assertions. Setting this property to a large
value may lead to excessive processing or memory consumption.