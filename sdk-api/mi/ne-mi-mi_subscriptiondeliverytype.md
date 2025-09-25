# MI_SubscriptionDeliveryType enumeration

## Description

Differentiates between a push or pull subscription delivery type. This is not supported when using the DCOM protocol.

## Constants

### `MI_SubscriptionDeliveryType_Pull:1`

Pull delivery is required for subscriptions. Pulling the indications from the server is more firewall friendly. However, it can also be slower than the push delivery type.

### `MI_SubscriptionDeliveryType_Push:2`

Push delivery is required for subscriptions. Push indicates that the server will connect to the client to deliver the event when one is available. This requires the firewall on the correct ports to work and security contexts need to managed carefully.