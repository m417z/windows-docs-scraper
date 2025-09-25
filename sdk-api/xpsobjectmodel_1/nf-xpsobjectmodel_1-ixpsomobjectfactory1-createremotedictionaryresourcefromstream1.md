# IXpsOMObjectFactory1::CreateRemoteDictionaryResourceFromStream1

## Description

Loads the remote resource dictionary markup into an unrooted IXpsOMRemoteDictionaryResource interface. The dictionary referenced by the dictionaryMarkupStream parameter can contain markup from either the OpenXPS or the MSXPS namespace.

## Parameters

### `dictionaryMarkupStream`

[in] The IStream interface that contains the remote resource dictionary markup.

### `partUri`

[in] The IOpcPartUri interface that contains the part name to be assigned to this resource.

### `resources`

The IXpsOMPartResources interface for the part resources of the dictionary resource objects that have streams.

### `dictionaryResource`

[in] A pointer to the new IXpsOMRemoteDictionaryResource interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see XPS Document Errors.

S_OK: The method succeeded.

XPS_E_INVALID_CONTENT_TYPE: An image resource type does not match the namespaces used in the markup. For example, if one of the elements in resources may be JpegXR but namespaces follow the MSXPS specification.

E_POINTER: dictionaryMarkupStream, dictionaryPartUri, resources, or dictionaryResource is **NULL**.

XPS_E_NO_CUSTOM_OBJECTS: resource does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported.

## Remarks

Use this method to create a remote dictionary from a stream whose contents could be of type XPS_DOCUMENT_TYPE_ XPS or XPS_DOCUMENT_TYPE_ OPENXPS. CreateRemoteDictionaryResourceFromStream, released in Windows 7, only reads streams of type XPS_DOCUMENT_TYPE_ XPS.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)