# IWSDXMLContext::AddNameToNamespace

## Description

Creates an object that represents a name in a namespace in an XML context. If the name already exists in the namespace, no new name will be added, and the name object for the existing name will be returned.

## Parameters

### `pszUri` [in]

The URI of the XML namespace in which this name will be created. If this namespace does not already exist in the XML context, a new namespace structure will be generated automatically.

### `pszName` [in]

The name to add to the namespace specified by *pszUri*.

### `ppName` [out]

A [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure for the newly created name. You must deallocate *ppName* by calling [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory). This parameter is optional.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pszUri* is **NULL** or the length in characters of the URI string exceeds WSD_MAX_TEXT_LENGTH (8192). *pszName* is **NULL** or the length in characters of the name string exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## Remarks

**AddNameToNamespace** can be used when creating XML elements for extensible sections. Extensible sections are represented by the **any** element in a schema. The returned [WSDXML_NAME](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_name) structure pointed to by *ppName* can be used to specify the name associated with the extension content. When building a [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that represents extension content, use the returned **WSDXML_NAME** structure for the element's **Name** member.

## See also

[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)