# ISdo::GetProperty

## Description

The
**GetProperty** method retrieves the value of the specified property.

## Parameters

### `Id` [in]

Specifies the ID of an existing property.

### `pValue` [out]

Pointer to a
[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that contains the value of the property.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## See also

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdo::SetProperty](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-putproperty)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)