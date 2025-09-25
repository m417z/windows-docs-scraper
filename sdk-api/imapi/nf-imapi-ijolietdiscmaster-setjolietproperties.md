# IJolietDiscMaster::SetJolietProperties

## Description

Sets the Joliet properties.

## Parameters

### `pPropStg` [in]

Pointer to the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface that the Joliet interface can use to retrieve new settings on various properties.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Applications should query for a property set using
[GetJolietProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-getjolietproperties), modify only those settings of interest, and then call
**SetJolietProperties** to change all values simultaneously.

Some properties are read-only. Both read-only properties and unsupported properties are ignored without generating an error (see IMAPI_S_PROPERTIESIGNORED). For example, someone could submit a property set to this interface and attempt to change the ClearlyNeverHeardOfBefore property. Because ClearlyNeverHeardOfBefore is an unknown value, the property is ignored and the method succeeds.

After calling
**SetJolietProperties**, an application should verify property settings by calling
[GetJolietProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-getjolietproperties).

## See also

[IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)