# EC_SUBSCRIPTION_PROPERTY_ID enumeration

## Description

The **EC_SUBSCRIPTION_PROPERTY_ID** enumeration defines values to identify event subscription properties used for subscription configuration.

## Constants

### `EcSubscriptionEnabled:0`

The **Enabled** property of the subscription that is used to enable or disable the subscription or obtain the current status of a subscription. This property is an [EcVarTypeBoolean](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionEventSources`

The **EventSources** property of the subscription that contains a collection of information about the local or remote computers (event sources) that can forward events to the event collector. This property is a handle to an array (an [EcVarObjectArrayPropertyHandle](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value). This value is typically used for collector initiated subscriptions. It can be used for source initiated subscriptions to disable the collection of events from a particular event source.

### `EcSubscriptionEventSourceAddress`

The **EventSourceAddress** property of the subscription that contains the IP address or fully qualified domain name (FQDN) of the local or remote computer (event source) from which the events are collected. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionEventSourceEnabled`

The **EventSourceEnabled** property of the subscription that is used to enable or disable an event source. This property is an [EcVarTypeBoolean](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionEventSourceUserName`

The **EventSourceUserName** property of the subscription that contains the user name, which is used by the remote computer (event source) to authenticate the user. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionEventSourcePassword`

The **EventSourcePassword** property of the subscription that contains the password, which is used by the remote computer (event source) to authenticate the user. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionDescription`

The **Description** property of the subscription that contains a description of the subscription. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionURI`

The **URI** property of the subscription that contains the URI, which is used by WS-Management to connect to a computer. For example, the URI can be `http://schemas.microsoft.com/wbem/wsman/1/logrecord/sel` for hardware events or
it can be `http://schemas.microsoft.com/wbem/wsman/1/windows/EventLog` for events that are published in the event log. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionConfigurationMode`

The **ConfigurationMode** property of the subscription that specifies how events are delivered to the subscription. This property is an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value from the [EC_SUBSCRIPTION_CONFIGURATION_MODE](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_configuration_mode) enumeration.

### `EcSubscriptionExpires`

The **Expires** property of the subscription that contains the date when the subscription will end. The maximum date that can be used is 3000-12-31T23:59:59.999Z. If this property is not defined, the subscription will not expire. This property is an [EcVarTypeDateTime](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionQuery`

The **Query** property of the subscription that contains the query, which is used by the event source for selecting events to forward to the event collector. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionTransportName`

The **TransportName** property of the subscription that specifies the type of transport, which is used to connect to the remote computer (event source). This value can be either HTTP, which is the default, or it can be HTTPS. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionTransportPort`

The **TransportPort** property of the subscription that specifies the port number, which the transport uses to connect to the remote computer (event source). The default port number for HTTP is 80 and the default port number for HTTPS is 443. This property is an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionDeliveryMode`

The **DeliveryMode** property of the subscription that specifies whether events are delivered to the subscription with either a push or pull model. This property is an [EC_SUBSCRIPTION_DELIVERY_MODE](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_delivery_mode) enumeration value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionDeliveryMaxItems`

The **DeliveryMaxItems** property of the subscription that specifies the maximum number of events that can be batched when forwarded from the event sources. When the **EcSubscriptionDeliveryMode** property is set to **EcDeliveryModePush**, this property determines the number of events that are included in a batch sent from the event source. When the **EcSubscriptionDeliveryMode** property is set to **EcDeliveryModePull**, this property determines the maximum number of items that will forwarded from an event source for each request. This property is an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionDeliveryMaxLatencyTime`

The **DeliveryMaxLatencyTime** property of the subscription that specifies how long, in milliseconds, the event source should wait before sending events (even if it did not collect enough events to reach the maximum number of items). This value is used when the **EcSubscriptionDeliveryMode** property is set to **EcDeliveryModePush**. This property is an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionHeartbeatInterval`

The **HeartbeatInterval** property of the subscription that defines the heartbeat time interval, in milliseconds, which is observed between the sent heartbeat messages. When the **EcSubscriptionDeliveryMode** property is set to **EcDeliveryModePush**, the event collector uses this property to determine the availability of the event source. When the **EcSubscriptionDeliveryMode** property is set to **EcDeliveryModePull**, the event collector uses this property to determine the interval between queries to the event source. This property is an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionLocale`

The **Locale** property of the subscription that specifies the locale (for example, en-us) of the events. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionContentFormat`

The **ContentFormat** property of the subscription that specifies the format in which the event content should be delivered. This property is an [EC_SUBSCRIPTION_CONTENT_FORMAT](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_content_format) enumeration value.

### `EcSubscriptionLogFile`

The **LogFile** property of the subscription that specifies the log file where the events collected from the event sources will be stored. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionPublisherName`

The **PublisherName** property of the subscription that contains the name of publisher that the event collector computer will raise events to the local log as. This is used when you want to collect events in a log other than the ForwardedEvents log. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionCredentialsType`

The **CredentialsType** property of the subscription that specifies the type of credentials used in the event subscription. This property is an [EC_SUBSCRIPTION_CREDENTIALS_TYPE](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_subscription_credentials_type) enumeration value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionCommonUserName`

The **CommonUserName** property of the subscription that contains the common user name, which is used by the local and remote computers to authenticate the user. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionCommonPassword`

The **CommonPassword** property of the subscription that contains the common password, which is used by the local and remote computers to authenticate the user. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value. This property cannot be used for source initiated subscriptions.

### `EcSubscriptionHostName`

The **HostName** property of the subscription that specifies the fully qualified domain name (FQDN) of the local computer. This property is used by an event source to forward events and is used in scenarios that involve multihomed servers that may have multiple FQDNs. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value and must only be used for a push subscription.

### `EcSubscriptionReadExistingEvents`

The **ReadExistingEvents** property of the subscription that determines whether to collect existing events or not. This property is an [EcVarTypeBoolean](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionDialect`

The **Dialect** property of the subscription that specifies the dialect of the query string. For example, the dialect for SQL based filters would be SQL, and the dialect for WMI based filters would be WQL. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionType`

The **Type** property of the subscription that defines whether the subscription is initiated by an event source or collector. This property is a **EC_SUBSCRPTION_TYPE** value.

### `EcSubscriptionAllowedIssuerCAs`

The **AllowedIssuerCAs** property of the subscription that contains the certificate authorities (CAs) allowed if the subscription uses certificate-based authentication. This is used for source initiated subscriptions. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionAllowedSubjects`

The **AllowedSubjects** property of the subscription that contains the subjects that are allowed for the subscription. This is used for source initiated subscriptions. The subject specifies names, such as domain names, for all the event source computers that are allowed in the subscription. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionDeniedSubjects`

The **DeniedSubjects** property of the subscription that contains the subjects that are not allowed for the subscription. This is used for source initiated subscriptions. The subject specifies names, such as domain names, for all the event source computers that are not allowed in the subscription. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionAllowedSourceDomainComputers`

The **AllowedSourceDomainComputers** property of the subscription that contains the source computers that are allowed to send events to the collector computer defined by an SDDL string. This property is an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionPropertyIdEND`