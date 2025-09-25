# IWSDXMLContext::SetTypes

## Description

Associates custom message types with the XML context object.

This method should only be called by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator), and should not be called directly by a WSDAPI client. Instead, the code generator will provide wrappers that access this method properly.

## Parameters

### `pTypes` [in]

An array of [WSDXML_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_type) structures that represent the set of messages for the [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

### `dwTypesCount` [in]

The number of types in the *pTypes* array.

### `bLayerNumber` [in]

The layer number associated with the [generated service code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pTypes* is **NULL** or *bLayerNumber* is greater than or equal to WSD_XMLCONTEXT_NUM_LAYERS (16). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)