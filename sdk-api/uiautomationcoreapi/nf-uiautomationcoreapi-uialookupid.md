# UiaLookupId function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Gets the integer identifier that can be used in methods that require a PROPERTYID, PATTERNID, CONTROLTYPEID, TEXTATTRIBUTEID, or EVENTID.

## Parameters

### `type` [in]

Type: **[AutomationIdentifierType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-automationidentifiertype)**

A value from the [AutomationIdentifierType](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-automationidentifiertype) enumerated type that specifies the type of identifier to look up.

### `pGuid` [in]

Type: **GUID***

The address of the unique identifier of the property, pattern, control type, text attribute, or event.

## Return value

Type: **int**

Returns an integer identifier.

## See also

**Conceptual**

[GUIDs](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-guids)

[Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids)