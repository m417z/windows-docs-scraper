# IDiscRecorder::SetRecorderProperties

## Description

Accepts an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) pointer for an object with all the properties that the application wishes to change. Sparse settings are supported. It is recommended, however, to query for a property set using
[GetRecorderProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-getrecorderproperties), modify only those settings of interest, and then call
**SetRecorderProperties** to change all values simultaneously.

## Parameters

### `pPropStg` [in]

Pointer to the
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface that the disc recorder can use to retrieve new settings on various properties.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Some properties are read-only, such as MaxWriteSpeed. Both read-only properties and unsupported properties are ignored without generating an error (see IMAPI_S_PROPERTIESIGNORED). For example, someone could submit a property set to this interface and attempt to change the MaxWriteSpeed and ClearlyNeverHeardOfBefore properties. Since MaxWriteSpeed is read-only and ClearlyNeverHeardOfBefore is an unknown value, both properties are ignored and the method succeeds.

After calling
**SetRecorderProperties**, an application should verify property settings by calling
[GetRecorderProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-getrecorderproperties).

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)