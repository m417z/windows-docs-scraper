# IDiscRecorder::GetRecorderProperties

## Description

Retrieves a pointer to an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface.

## Parameters

### `ppPropStg` [out]

Pointer to an
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface to the property set with all current properties defined.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Properties are not retained after IMAPI is closed. A property set format is convenient for IMAPI because it stores an ID/TYPE/VALUE combination, as well as ID/NAME associations. Each combination is a single property, and IMAPI uses these properties for various values that are unique to specific recorders. For example, most recorders would support a WriteSpeed property.

The caller can then modify properties by calling
[SetRecorderProperties](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscrecorder-setrecorderproperties). Current properties include the following:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)