# WS_POLICY_CONSTRAINTS structure

## Description

Specifies policy constraints for a channel.

## Members

### `channelBinding`

Which channel binding is required. The
following values are supported:

* [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)
* [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding)

### `channelPropertyConstraints`

An array of channel property constraints which override the default
set of constraints. The constraints specified here, combined
with the default set of constraints limits the set of policies
that will be matched.

If a channel property constraint is not specified for a given property,
then a default constraint value will be used.
See [WS_CHANNEL_PROPERTY_CONSTRAINT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_channel_property_constraint) for the
supported set of properties and their default values.

### `channelPropertyConstraintCount`

The number of elements specified in the **channelPropertyConstraints** array.

If this value is 0, then the channelPropertyConstraints array may be **NULL**.

### `securityConstraints`

Constraints on the type of security that may be used.

Setting this field to **NULL** indicates a constraint of no security.

### `policyExtensions`

### `policyExtensionCount`