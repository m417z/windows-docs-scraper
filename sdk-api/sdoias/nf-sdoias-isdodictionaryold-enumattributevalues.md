# ISdoDictionaryOld::EnumAttributeValues

## Description

The
**EnumAttributeValues** method retrieves the values for an enumerable attribute.

## Parameters

### `Id` [in]

Specifies the ID of the attribute.

### `pValueIds` [out]

On successful return points to a
[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) of value IDs for the enumerable attribute. If the attribute is not enumerable, points to a
[VT_EMPTY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) variant.

### `pValuesDesc` [out]

On successful return points to a
[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) of value descriptions for the enumerable attribute. If the attribute is not enumerable, points to a
[VT_EMPTY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) variant.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

The return value is S_OK even if the attribute is not enumerable.

## See also

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)