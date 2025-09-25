# IIdentityProvider::GetIdentityEnum

## Description

The **GetIdentityEnum** method retrieves an [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) interface pointer that can be used to enumerate identities.

## Parameters

### `eIdentityType` [in]

A value of the [IDENTITY_TYPE](https://learn.microsoft.com/windows/win32/api/identitycommon/ne-identitycommon-identity_type) enumeration that indicates the type of identities to enumerate.

### `pFilterkey` [in, optional]

A pointer to a property key that specifies a property. If the value of this parameter is not **NULL**, only identities that support the property specified by this parameter are enumerated.

### `pFilterPropVarValue` [in, optional]

A pointer to a property value. If the values of this parameter and the *pFilterkey* parameter are not **NULL**, only identities that have the property value specified by this parameter are enumerated.

### `ppIdentityEnum` [out]

A pointer to an [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) interface pointer that can be used to enumerate identities.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iidentityprovider)