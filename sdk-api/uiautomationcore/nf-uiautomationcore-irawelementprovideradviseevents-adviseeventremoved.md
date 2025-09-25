# IRawElementProviderAdviseEvents::AdviseEventRemoved

## Description

Notifies the Microsoft UI Automation provider when a UI Automation client stops listening for a specific event, including a property-changed event.

## Parameters

### `eventId` [in]

Type: **EVENTID**

The identifier of the event being removed. For a list of event IDs, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `propertyIDs` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

A pointer to the identifiers of the properties being removed, or **NULL** if the event listener being removed is not listening for property events.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method enables the provider to reduce overhead by raising only events that are being listened for.

It is important for UI Automation providers to treat the **IRawElementProviderAdviseEvents::AdviseEventRemoved** like the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. As long as [AdviseEventAdded](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementprovideradviseevents-adviseeventadded) has been called more times than **AdviseEventRemoved** for a specific event or property, the provider should continue to raise corresponding events, because some clients are still listening. Alternatively, UI Automation providers can use the [UiaClientsAreListening](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaclientsarelistening) function to determine if at least one client is listening and, if so, raise all appropriate events.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IRawElementProviderAdviseEvents](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovideradviseevents)

**Reference**