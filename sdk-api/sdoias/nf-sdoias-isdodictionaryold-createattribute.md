# ISdoDictionaryOld::CreateAttribute

## Description

The
**CreateAttribute** method creates a new attribute object and returns an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface to it.

## Parameters

### `Id` [in]

Specifies a value from the enumeration type
[ATTRIBUTEID](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid). This value specifies the type of attribute to create.

### `ppAttributeObject` [out]

Pointer to a pointer to an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer for the created attribute object.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## See also

[ATTRIBUTEID](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid)

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)