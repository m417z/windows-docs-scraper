# EC_SUBSCRIPTION_CONFIGURATION_MODE enumeration

## Description

The **EC_SUBSCRIPTION_CONFIGURATION_MODE** enumeration specifies different configuration modes that change the default settings for a subscription. Each configuration mode is used to define default settings for a different scenario, and sets the subscription delivery mode and default property values.

## Constants

### `EcConfigurationModeNormal:0`

This mode is used when an administrator needs the events to be delivered reliably and for the subscription to work with minimal configuration, and when network usage is not a concern. This mode sets the default subscription delivery mode to pull subscriptions.

### `EcConfigurationModeCustom`

This subscription mode allows custom values for the DeliveryMode property, the DeliveryMaxItems property, the DeliveryMaxLatencyTime, and the HeartBeatInterval property.

### `EcConfigurationModeMinLatency`

This mode is used for alerts and critical events because it configures the subscription to send events as soon as they occur with minimal delay. This mode sets the default subscription delivery mode to push subscriptions.

### `EcConfigurationModeMinBandwidth`

This mode is used when network activity is controllable, and when network usage is expensive. This mode sets the default subscription delivery mode to push subscriptions.

## Remarks

The settings for each configuration mode can be found in the Event Collector registry located at:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         Windows
            CurrentVersion
               EventCollector
                  ConfigurationModes
```

For more information about the subscription delivery mode and properties see, [EC_SUBSCRIPTION_DELIVERY_MODE](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_delivery_mode) and [EC_SUBSCRIPTION_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_property_id).