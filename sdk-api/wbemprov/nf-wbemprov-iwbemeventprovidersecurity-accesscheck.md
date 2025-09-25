# IWbemEventProviderSecurity::AccessCheck

## Description

The
**AccessCheck** method is implemented by an event provider and called by Windows Management Instrumentation (WMI) when a consumer subscribes to an event specified in *wszQuery*. A consumer that has access permission for an event can subscribe to that event. A consumer that does not have access permission for an event cannot subscribe to that event. For more information, see [Writing an Event Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/writing-an-event-provider) and [Securing WMI Events](https://learn.microsoft.com/windows/desktop/WmiSdk/securing-wmi-events).

For a temporary consumer, WMI sets the [PSID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) supplied in the *pSid* parameter to **NULL** and the call is made by impersonating the consumer.
For a permanent consumer, WMI sets the PSID with the security identifier (SID) of the user who created the subscription.

## Parameters

### `wszQueryLanguage` [in]

Language of the following query filter, which is "WQL".

### `wszQuery` [in]

Text of the event query filter, which is registered by a logical consumer.

### `lSidLength` [in]

Integer that contains the security identifier (SID) length, or 0 (zero) if the subscription builder token is available.

### `pSid` [in]

Pointer to the constant byte integer type that contains the SID, or **NULL** if the subscription builder's token is available.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained in an **HRESULT**.

## See also

[IWbemEventProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventprovider)

[IWbemEventProviderSecurity](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventprovidersecurity)

[SELECT Statement for Event Queries](https://learn.microsoft.com/windows/desktop/WmiSdk/select-statement-for-event-queries)

[Securing WMI Events](https://learn.microsoft.com/windows/desktop/WmiSdk/securing-wmi-events)