# IWSDXMLContext::SetNamespaces

## Description

Associates custom namespaces with the XML context object.

This method should only be called by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator), and should not be called directly by a WSDAPI client. Instead, the code generator will provide wrappers that access this method properly.

## Parameters

### `pNamespaces` [in]

An array of [WSDXML_NAMESPACE](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_namespace) structures.

### `wNamespacesCount` [in]

The number of namespaces in the *pNamespaces* array.

### `bLayerNumber` [in]

The layer number associated with the [generated service code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pNamespaces* is **NULL** or *bLayerNumber* is greater than or equal to WSD_XMLCONTEXT_NUM_LAYERS (16). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## See also

[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)