# IRawElementProviderSimple3::GetMetadataValue

## Description

Gets metadata from the UI Automation element that indicates how the information should be interpreted. For example, should the string "1/4" be interpreted as a fraction or a date?

## Parameters

### `targetId` [in]

The ID of the property to retrieve.

### `metadataId` [in]

Specifies the type of metadata to retrieve.

### `returnVal` [out, retval]

The metadata.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## See also

[IRawElementProviderSimple3](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple3)

[SayAsInterpretAs](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-sayasinterpretas)