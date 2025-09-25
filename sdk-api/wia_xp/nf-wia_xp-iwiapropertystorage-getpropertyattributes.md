# IWiaPropertyStorage::GetPropertyAttributes

## Description

The **IWiaPropertyStorage::GetPropertyAttributes** method retrieves access rights and legal value information for a specified set of properties.

## Parameters

### `cpspec` [in]

Type: **ULONG**

Specifies the number of property attributes to query.

### `rgpspec` [in]

Type: **[PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec)[]**

Specifies an array of [Device Information Property Constants](https://learn.microsoft.com/windows/desktop/wia/-wia-wiadeviceinfoprop). Each constant in the array selects a property to query.

### `rgflags` [out]

Type: **ULONG[]**

An array that receives a [property attribute descriptor](https://learn.microsoft.com/windows/desktop/wia/-wia-property-attributes) for each property specified in the *rgpspec* array. Each element in the array is one or more descriptor values combined with a bitwise **OR** operation.

### `rgpropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)[]**

An array that receives a [property attribute descriptor](https://learn.microsoft.com/windows/desktop/wia/-wia-property-attributes) for each property specified in the *pPROPSPEC* array. For more information, see [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

## Return value

Type: **HRESULT**

This method returns one of the following values or a standard COM error code:

| Return Value | Meaning |
| --- | --- |
| S_OK | This method succeeded. |
| S_FALSE | The specified property names do not exist. No attributes were retrieved. |
| STG_E_ACCESSDENIED | The application does not have access to the property stream or the stream may already be open. |
| STG_E_INSUFFICIENTMEMORY | There is not enough memory to complete the operation. |
| ERROR_NOT_SUPPORTED | The property type is not supported. |
| STG_E_INVALIDPARAMETER | One or more parameters are invalid. One or more of the [PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec) structures contain invalid data. |
| STG_E_INVALIDPOINTER | One or more of the pointers passed to this method are invalid. |
| ERROR_NO_UNICODE_TRANSLATION | A translation from Unicode to ANSI or ANSI to Unicode failed. |

## Remarks

This method retrieves both property access rights and valid property values. Access rights report whether the property is readable, writable, or both. Valid property values are specified as a range of values, a list of values, or a group of flag values. For more information, see [Property Attributes](https://learn.microsoft.com/windows/desktop/wia/-wia-property-attributes).

If the property access rights flag has the **WIA_PROP_NONE** bit set, no legal value information is available for this property. Read only properties and properties with a binary data type are examples of properties that would have the **WIA_PROP_NONE** bit set.

If the property has a range of valid values, they can be determined through the *rgpropvar* parameter upon completion of this method. The *ppvValidValues* parameter specifies an array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures.

For example, if the property range is specified as VT_VECTOR | VT_UI4, range information can be retrieved through the structure member

*rgpropvar*[*n*].caul.pElems[*range_specifier*]

where *n* is the index number of the property that is inspected and *range_specifier* is one of the following:

| Range Specifier | Meaning |
| --- | --- |
| WIA_RANGE_MAX | Maximum value to which the property may be set. |
| WIA_RANGE_MIN | Minimum value to which the property may be set. |
| WIA_RANGE_NOM | Normal or default property value. |
| WIA_RANGE_STEP | Increment or decrement between property values. |

If the property has a list of valid values, applications determine them through the *ppvValidValues* parameter upon completion of this method.

For example, if the property range is specified as VT_VECTOR | VT_UI4, the list of valid property values can be retrieved through the structure member

rgpropspecValues[*n*].caul.pElems[*list_specifier*]

where *n* is the index number of the property that is inspected and *list_specifier* is one of the following:

| Range Specifier | Meaning |
| --- | --- |
| WIA_LIST_COUNT | Total number of list elements excluding the nominal value. |
| WIA_LIST_NOM | Nominal value for the property. |
| WIA_LIST_VALUES | The index number of the first value. |

Programs also use the *ppvValidValues* parameter to retrieve valid flag values. For instance, if the property flags are specified as VT_UI4, valid flag values can be determined through the structure member

rgpropspec[*n*].caul.pElems[*flag_specifier*]

where *n* is the index number of the property that is inspected, and *flag_specifier*  is one of the following:

| Range Specifier | Meaning |
| --- | --- |
| WIA_FLAG_NOM | The nominal value for the property. |
| WIA_FLAG_NUM_ELEMS | Total number of list elements excluding the nominal value. |
| WIA_FLAG_VALUES | All values with all valid flag bits set. |

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage)