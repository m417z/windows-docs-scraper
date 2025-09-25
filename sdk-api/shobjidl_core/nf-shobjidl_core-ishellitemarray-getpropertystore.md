# IShellItemArray::GetPropertyStore

## Description

Gets a property store.

## Parameters

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

One of the [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) constants.

### `riid` [in]

Type: **REFIID**

The IID of the object type to retrieve.

### `ppv` [out]

Type: **void****

When this method returns, contains interface pointer requested in riid. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used to obtain a read-only property store that aggregates properties gathered from all the items in the shell item array.

If there is more than one item in the shell item array, then the resulting property store will aggregate the values from each item according to a set of rules determined by each property. Values read from the property store will be coerced to a canonical form prior to aggregation as discussed at [CoerceToCanonicalValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-coercetocanonicalvalue). The output from a call to [IPropertyStore::GetValue](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761473(v=vs.85)) is computed as follows:

* Single valued properties follow the rule specified by the [aggregation type](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) string in the property description schema.
* + If the aggregation type is "DateRange" and the property type is a filetime, returns a VT_VECTOR | VT_FILETIME of two values, or a VT_FILETIME value if the values were identical.
  + If the aggregation type is "First", returns the first non-empty value.
  + If the aggregation type is "Sum", returns the sum.
  + If the aggregation type is "Average", returns the average of all non-empty values.
  + If the aggregation type is "Minimum", returns the minimum value.
  + If the aggregation type is "Union" and the property type is a string, returns a VT_VECTOR | VT_LPWSTR containing the union of values. The order of the values is unspecified.
  + If the aggregation type is unspecified, incompatible, or "Default", either returns a single value if it is identical for all items in the array, or a special value used to indicate that the values differ between some of the items. The special value is a VT_VECTOR | VT_LPWSTR containing two strings: "Multiple" and "Values". Calling applications should check for this special value by checking for VT_VECTOR | VT_LPWSTR if [GetTypeFlags](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-gettypeflags) indicates the property is single-valued.
* Multi-valued string properties return an intersection of their strings. The order is unspecified.

Calls to [IsPropertyWritable](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorecapabilities-ispropertywritable) will return S_FALSE only if all the items have property handlers that implement [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities) and all the property stores indicate they do not support writing the property.

Calling applications may achieve other aggregation behaviors by accessing the individual shell items and their property stores directly. See [IPropertyStore::GetCount](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761472(v=vs.85)), [IPropertyStore::GetAt](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761471(v=vs.85)), and [GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore).

Writing to an array of shell items is supported via the [IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation) API.