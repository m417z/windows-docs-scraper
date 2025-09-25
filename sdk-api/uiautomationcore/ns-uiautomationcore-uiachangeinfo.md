# UiaChangeInfo structure

## Description

Contains data about a UI Automation change that occurred.

## Members

### `uiaId`

Identifies the type of change info. Possible values are all the values of **Change Identifiers**, [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids), [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids), [Annotation Type Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-annotation-type-identifiers) and [Style Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-style-identifiers).

### `payload`

Information about the type of change that occurred.

### `extraInfo`

Detailed information about the change that occurred.

## Remarks

The provider can call [UiaRaiseChangesEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraisechangesevent) and pass in an array of **UiaChangeInfo** structs to notify clients of a related group of changes. The **payload** and **extraInfo** will vary depending on the **uiaId** populated in the **UiaChangeInfo** struct.

If there are multiple of any of these event types multiple **UiaChangeInfo** structs would be created. Below is a description of what these are for each pair of values.

| UiaId | payload | extraInfo |
| --- | --- | --- |
| **UIA_SummaryChangeId** | VT_BSTR<br><br>A string describing the meaning of the change from an application point of view. | A constant ID value from the provider indicating the meaning of this event. |
| For UIA property changes, identified in the [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids) section. | Type is the type of the property and the value is the new value of the property. |  |
| For text attributes changes, identified in the [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) section, **extraInfo** is not used. | Type is the type of the attribute and the value is the new value of the attribute. |  |
| For annotation changes, identified in the [Annotation Type Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-annotation-type-identifiers) section, **extraInfo** is not used. | VT_BSTR<br><br>For text, the characters from the range to which the annotation applies. |  |
| For style changes, identified in the [Style Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-style-identifiers) section, **extraInfo** is not used. | VT_BSTR<br><br>For text, the characters from the range to which the style applies. |  |