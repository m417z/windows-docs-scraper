# ISdoDictionaryOld::GetAttributeID

## Description

The
**GetAttributeID** method retrieves the ID for the specified attribute.

## Parameters

### `bstrAttributeName` [in]

Specifies the name of the attribute. This name is either the Lightweight Directory Access Protocol (LDAP) name, or the display name for the attribute.

### `pId` [out]

Pointer to an
[ATTRIBUTEID](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid) that receives the ID of the specified attribute.

## Return value

If the method succeeds the return value is **S_OK**.

If the method does not find the attribute, the return value is **DISP_E_MEMBERNOTFOUND**.

If the method fails, the return value is one of the following error codes.

## See also

[ATTRIBUTEID](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-attributeid)

[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)