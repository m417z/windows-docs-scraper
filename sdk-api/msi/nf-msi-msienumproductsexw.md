# MsiEnumProductsExW function

## Description

The **MsiEnumProductsEx** function enumerates through one or all the instances of products that are currently advertised or installed in the specified contexts. This function supersedes [MsiEnumProducts](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumproductsa).

## Parameters

### `szProductCode` [in, optional]

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product to be enumerated. Only instances of products within the scope of the context specified by the *szUserSid* and *dwContext* parameters are enumerated. This parameter can be set to **NULL** to enumerate all products in the specified context.

### `szUserSid` [in]

Null-terminated string that specifies a security identifier (SID) that restricts the context of enumeration. The special SID string s-1-1-0 (Everyone) specifies enumeration across all users in the system. A SID value other than s-1-1-0 is considered a user-SID and restricts enumeration to the current user or any user in the system. This parameter can be set to **NULL** to restrict the enumeration scope to the current user.

| SID type | Meaning |
| --- | --- |
| **NULL** | Specifies the currently logged-on user. |
| **User SID** | Specifies enumeration for a particular user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |
| **s-1-1-0** | Specifies enumeration across all users in the system. |

**Note** The special SID string s-1-5-18 (System) cannot be used to enumerate products or patches installed as per-machine. When *dwContext* is set to MSIINSTALLCONTEXT_MACHINE only, *szUserSid* must be **NULL**.

### `dwContext` [in]

Restricts the enumeration to a context. This parameter can be any one or a combination of the values shown in the following table.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | Enumeration extended to all per–user–managed installations for the users specified by *szUserSid*. An invalid SID returns no items. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | Enumeration extended to all per–user–unmanaged installations for the users specified by *szUserSid*. An invalid SID returns no items. |
| **MSIINSTALLCONTEXT_MACHINE** | Enumeration extended to all per-machine installations. When *dwInstallContext* is set to MSIINSTALLCONTEXT_MACHINE only, the *szUserSID* parameter must be **NULL**. |

### `dwIndex` [in]

 Specifies the index of the product to retrieve. This parameter must be zero for the first call to the **MsiEnumProductsEx** function and then incremented for subsequent calls. The index should be incremented, only if the previous call has returned ERROR_SUCCESS. Because products are not ordered, any new product has an arbitrary index. This means that the function can return products in any order.

### `szInstalledProductCode` [out, optional]

Null-terminated string of **TCHAR** that gives the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product instance being enumerated. This parameter can be **NULL**.

### `pdwInstalledContext` [out, optional]

Returns the context of the product instance being enumerated. The output value can be MSIINSTALLCONTEXT_USERMANAGED, MSIINSTALLCONTEXT_USERUNMANAGED, or MSIINSTALLCONTEXT_MACHINE. This parameter can be **NULL**.

### `szSid` [out, optional]

An output buffer that receives the string SID of the account under which this product instance exists. This buffer returns an empty string for an instance installed in a per-machine context.

This buffer should be large enough to contain the SID. If the buffer is too small, the function returns ERROR_MORE_DATA and sets **pcchSid* to the number of **TCHAR** in the SID, not including the terminating NULL character.

If *szSid* is set to **NULL** and *pcchSid* is set to a valid pointer, the function returns ERROR_SUCCESS and sets **pcchSid* to the number of **TCHAR** in the value, not including the terminating **NULL**. The function can then be called again to retrieve the value, with the *szSid* buffer large enough to contain **pcchSid* + 1 characters.

If *szSid* and *pcchSid* are both set to **NULL**, the function returns ERROR_SUCCESS if the value exists, without retrieving the value.

### `pcchSid` [in, out, optional]

When calling the function, this parameter should be a pointer to a variable that specifies the number of **TCHAR** in the *szSid* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *szSid* is also **NULL**, otherwise the function returns ERROR_INVALID_PARAMETER.

## Return value

The **MsiEnumProductsEx** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | If the scope includes users other than the current user, you need administrator privileges. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no more products to enumerate. |
| **ERROR_SUCCESS** | A product is enumerated. |
| **ERROR_MORE_DATA** | The *szSid* parameter is too small to get the user SID. |
| **ERROR_UNKNOWN_PRODUCT** | The product is not installed on the computer in the specified context. |
| **ERROR_FUNCTION_FAILED** | An unexpected internal failure. |

## Remarks

To enumerate products, an application must initially call the **MsiEnumProductsEx** function with the *iIndex* parameter set to zero. The application must then increment the *iProductIndex* parameter and call **MsiEnumProductsEx** until it returns **ERROR_NO_MORE_ITEMS** and there are no more products to enumerate.

When making multiple calls to **MsiEnumProductsEx** to enumerate all of the products, each call must be made from the same thread.

A user must have administrator privileges to enumerate products across all user accounts or a user account other than the current user account. The enumeration skips products that are advertised only (such as products not installed) in the per-user-unmanaged context when enumerating across all users or a user other than the current user.

Use [MsiGetProductInfoEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductinfoexa) to get the state or other information about each product instance enumerated by **MsiEnumProductsEx**.

> [!NOTE]
> The msi.h header defines MsiEnumProductsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MsiEnumProducts](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumproductsa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Removing Patches](https://learn.microsoft.com/windows/desktop/Msi/removing-patches)