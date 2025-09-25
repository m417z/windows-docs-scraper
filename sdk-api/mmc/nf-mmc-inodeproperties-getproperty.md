# INodeProperties::GetProperty

## Description

The
**GetProperty** method retrieves text-only property values for a node. Your implementation of the **INodeProperties::GetProperty** method is called when an application based on the
[MMC 2.0 Automation Object Model](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmc-2-0-automation-object-model) retrieves the
[Node.Property](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/node-property) property.

## Parameters

### `pDataObject` [in]

A pointer to the snap-in data object.

### `szPropertyName` [in]

The name of the property retrieved.

### `pbstrProperty` [out]

Text value for the property.

## Return value

The snap-in returns **S_OK** if it provides the property value when this method is called. If the snap-in returns **S_FALSE**, then the data object is queried for the property value.

## Remarks

The Extended View extension uses two properties: CCF_DESCRIPTION and CCF_HTML_DETAILS. As an alternative to supplying values for these properties using the data object to query the
[CCF_DESCRIPTION](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-description) and
[CCF_HTML_DETAILS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-html-details) clipboard formats, a snap-in can use **INodeProperties::GetProperty** to return the property values to the Extended View. This alternative is beneficial in situations where a snap-in's data object does not provide the desired information.

In addition to providing CCF_DESCRIPTION and CCF_HTML_DETAILS property values, a snap-in can use
INodeProperties to provide values for other text-based properties (for example, with a new view extension).

For more information and a code example for **INodeProperties::GetProperty**, see
[Using the Extended View Extension - Implementation Details](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-extended-view-extension-implementation-details).

## See also

[CCF_DESCRIPTION](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-description)

[CCF_HTML_DETAILS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-html-details)

[Node](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/node-object)

[Node.Property](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/node-property)

[Using the Extended View Extension](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-extended-view-extension)

[Using the Extended View Extension - Implementation Details](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-extended-view-extension-implementation-details)