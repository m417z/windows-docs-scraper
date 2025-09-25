# EC_SUBSCRIPTION_CREDENTIALS_TYPE enumeration

## Description

The **EC_SUBSCRIPTION_CREDENTIALS_TYPE** enumeration specifies the type of credentials to use when communicating with event sources.

## Constants

### `EcSubscriptionCredDefault:0`

Negotiate with event sources to specify a proper authentication type without specifying a username and password for the subscription credentials.

### `EcSubscriptionCredNegotiate`

WinRM will negotiate with event sources to specify a proper authentication type for the subscription credentials.

### `EcSubscriptionCredDigest`

Use digest authentication for the subscription credentials.

### `EcSubscriptionCredBasic`

Send a username and password to use as credentials for the subscription.

### `EcSubscriptionCredLocalMachine`

Use the local computer's domain account credentials to create a subscription instead of using user credentials for the subscription. This has the advantage of not having to manage user accounts and password expiration to simplify long lasting subscription management.