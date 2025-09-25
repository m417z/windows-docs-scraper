# ISdo::PutProperty

## Description

The
**PutProperty** method sets the value of the specified property.

## Parameters

### `Id` [in]

Specifies the ID of an existing property.

### `pValue` [in]

Pointer to a
[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) that contains the value for that property.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

After you have set values using **ISdo::PutProperty**, call
[ISdo::Apply](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-apply) to write the changes to persistent storage.

The method fails if the property is READ_ONLY or if the value is invalid.

## See also

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdo::Apply](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdo-apply)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)