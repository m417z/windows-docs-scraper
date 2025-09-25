# IJolietDiscMaster::GetJolietProperties

## Description

Retrieves a pointer to an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface that contains the Joliet properties.

## Parameters

### `ppPropStg` [out]

Address of a pointer to an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface for the Joliet property set with all current properties defined.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Properties are not retained after IMAPI is closed. A property set is convenient for IMAPI because it stores an ID/TYPE/VALUE combination, as well as ID/NAME associations. Each combination is a single property, and IMAPI uses these properties as values that are unique to the Joliet interface. For example, the Joliet interface supports a VolumeName property.

The caller can modify these properties by calling
[SetJolietProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-setjolietproperties). Current properties include the following.

## See also

[IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)