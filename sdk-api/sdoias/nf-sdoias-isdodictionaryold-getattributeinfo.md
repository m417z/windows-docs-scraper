# ISdoDictionaryOld::GetAttributeInfo

## Description

The **GetAttributeInfo**
retrieves information for the specified attribute.

## Parameters

### `Id` [in]

Specifies the ID for the attribute.

### `pInfoIDs` [in]

Pointer to an array of information IDs. This pointer cannot be **NULL**.

### `pInfoValues` [out]

Pointer to a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) of
information values.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Although Server Data Objects (SDO) exposes this method, you do not need it in order to use SDO. The use of
this method is discouraged.

## See also

[ATTRIBUTEINFO](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeinfo)

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)

[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray)

[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)