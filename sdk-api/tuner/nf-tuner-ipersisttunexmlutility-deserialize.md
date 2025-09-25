# IPersistTuneXmlUtility::Deserialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Constructs and returns an object that initializes itself by using the XML node passed as a **VARIANT** parameter to the method. The returned object exposes its **IUnknown** interface so that other objects can query it.

## Parameters

### `varValue` [in]

XML node used to construct and initialize the object. This parameter can be either a **BSTR** object or an **IXMLDOMNode** object.

### `ppObject` [out, retval]

Pointer to the **IUnknown** interface of the object being deserialized.
This method allocates memory to hold the deserialized object and returns the pointer in this parameter. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPersistTuneXmlUtility](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ipersisttunexmlutility)