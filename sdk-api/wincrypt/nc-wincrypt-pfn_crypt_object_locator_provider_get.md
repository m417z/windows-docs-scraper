# PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET callback function

## Description

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET** callback function retrieves an object. You must implement this function as part of your custom provider. This function is currently called by only the Secure Channel (Schannel) security package.

## Parameters

### `pPluginContext` [in, optional]

Pointer to an optional buffer defined by this provider and returned by the [PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize) function. The buffer is not modified by the caller. Your provider can use the data to help it determine what actions to perform or to maintain additional information.

### `pIdentifier` [in, optional]

Pointer to a [CRYPTOAPI_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that contains the object identifier. This value should always be **NULL** on the first call to this function.

### `dwNameType` [in]

The name format of the *pNameBlob* parameter. Possible values are listed below. The implementation of this function must be able to process **CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE**, which is passed in by Schannel.

#### CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE (1 (0x1))

#### CRYPT_OBJECT_LOCATOR_LAST_RESERVED_NAME_TYPE (32 (0x20))

#### CRYPT_OBJECT_LOCATOR_FIRST_RESERVED_USER_NAME_TYPE (33 (0x21))

#### CRYPT_OBJECT_LOCATOR_LAST_RESERVED_USER_NAME_TYPE (0x0000FFFF)

### `pNameBlob` [in]

Pointer to a [CRYPTOAPI_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that contains the name the calling application is using to uniquely identify the object. Your provider uses this name to locate the requested object. Schannel currently submits a DNS (domain name system) host name encoded in UTF8 with IDN names converted from punycode.

### `ppbContent` [out]

Pointer to a byte array that contains the object to be returned.

### `pcbContent` [out]

The size, in bytes, of the object pointed to by the *ppbContent* parameter.

### `ppwszPassword` [out]

Null-terminated Unicode string that contains the password, if any, used to encrypt the object. If the object is a personal information exchange (PFX) file, a password will typically be used to perform encryption. This value can be **NULL** if no password is required.

### `ppIdentifier` [out]

Address that receives a pointer to an optional identifier that can be used during subsequent calls to this function and for change notifications. For more information, see Remarks. If your provider sets this value to **NULL**, Schannel internally uses the *pNameBlob* parameter value.

## Return value

If the function succeeds, return nonzero (**TRUE**).

If the function fails, return zero (**FALSE**) and specify an appropriate error in the [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function. Most errors are passed through Schannel unaltered but this behavior is not guaranteed. Some errors may be mapped to other errors.

If an object cannot be returned for a given DNS name (*pNameBlob*) or identifier (*pIdentifier*), return **FALSE** and specify **CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND** in the [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function.

## Remarks

The **PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET** callback function is currently called by only the Secure Channel (Schannel) security package. You can return an object that encapsulates one of the following:

* A personal information exchange (PFX) byte array
* A certificate store.
* A generic BLOB. This is not currently supported by Schannel.

When this function is first called, Schannel submits a DNS host name in the *pNameBlob* argument to specify the host for which the object is intended. Your provider must process the name (match wild cards, build a file path, and so on) to determine what object to find.

Because many host names can be mapped to one object, your provider can use the *ppIdentifier* parameter to return an internally defined identifier that can be used in subsequent calls by the cryptography API (CAPI) functions to the provider. The provider can then use the identifier to assist in finding the appropriate object.

## See also

[CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_object_locator_provider_table)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_initialize)

[PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_crypt_object_locator_provider_release)