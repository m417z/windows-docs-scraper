# EC_SUBSCRIPTION_TYPE enumeration

## Description

The **EC_SUBSCRIPTION_TYPE** enumeration specifies the type of subscription to use (a source initiated or collector initiated subscription).

## Constants

### `EcSubscriptionTypeSourceInitiated:0`

Allows you to define an event subscription on an event collector computer without defining the event source computers. Multiple remote event source computers can then be set up (using a group policy setting) to forward events to the event collector computer. For more information, see [Setting up a Source Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/setting-up-a-source-initiated-subscription). This subscription type is useful when you do not know or you do not want to specify all the event sources computers that will forward events.

### `EcSubscriptionTypeCollectorInitiated:1`

The computer that receives forwarded events from event sources (other computers that the events were published on) initiates the subscription. You specify all the event sources at the time the subscription is created.