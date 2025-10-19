# MsiGetProductInfoExW function

## Description

The **MsiGetProductInfoEx** function returns product information for advertised and installed products. This function can retrieve information

 about an instance of a product that is installed under a user account other than the current user.

The calling process must have administrative privileges for a user who is different from the current user. The **MsiGetProductInfoEx** function cannot query an instance of a product that is advertised under a per-user-unmanaged context for a user account other than the current user.

This function is an extension of the [MsiGetProductInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductinfoa) function.

## Parameters

### `szProductCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product instance that is being queried.

### `szUserSid` [in]

The security identifier (SID) of the account under which the instance of the product that is being queried exists. A **NULL** specifies the current user SID.

| SID | Meaning |
| --- | --- |
| **NULL** | The currently logged-on user. |
| **User SID** | The enumeration for a specific user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string "S-1-5-18" (system) cannot be used to enumerate products installed as per-machine. If *dwContext* is "MSIINSTALLCONTEXT_MACHINE", *szUserSid* must be **NULL**.

### `dwContext` [in]

The installation context of the product instance that is being queried.

| Name | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | Retrieves the product property for the per–user–managed instance of the product. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | Retrieves the product property for the per–user–unmanaged instance of the product. |
| **MSIINSTALLCONTEXT_MACHINE** | Retrieves the product property for the per-machine instance of the product. |

### `szProperty` [in]

Property being queried.

The property to be retrieved. The properties in the following table can only be retrieved from applications that are already installed. All required properties are guaranteed to be available, but other properties are available only if the property is set. For more information, see
[Required Properties](https://learn.microsoft.com/windows/desktop/Msi/required-properties) and [Properties](https://learn.microsoft.com/windows/desktop/Msi/properties).

| Property | Meaning |
| --- | --- |
| **INSTALLPROPERTY_PRODUCTSTATE** | The state of the product returned in string form as "1" for advertised and "5" for installed. |
| **INSTALLPROPERTY_HELPLINK** | The support link. For more information, see the [ARPHELPLINK](https://learn.microsoft.com/windows/desktop/Msi/arphelplink) property. |
| **INSTALLPROPERTY_HELPTELEPHONE** | The support telephone. For more information, see the [ARPHELPTELEPHONE](https://learn.microsoft.com/windows/desktop/Msi/arphelptelephone) property. |
| **INSTALLPROPERTY_INSTALLDATE** | The last time this product received service. The value of this property is replaced each time a patch is applied or removed from the product or the /v [Command-Line Option](https://learn.microsoft.com/windows/desktop/Msi/command-line-options) is used to repair the product. If the product has received no repairs or patches this property contains the time this product was installed on this computer. |
| **INSTALLPROPERTY_INSTALLEDLANGUAGE** | Installed language.<br><br>**[Windows Installer 4.5 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-5):** Not supported. |
| **INSTALLPROPERTY_INSTALLEDPRODUCTNAME** | The installed product name. For more information, see the [ProductName](https://learn.microsoft.com/windows/desktop/Msi/productname) property. |
| **INSTALLPROPERTY_INSTALLLOCATION** | The installation location. For more information, see the [ARPINSTALLLOCATION](https://learn.microsoft.com/windows/desktop/Msi/arpinstalllocation) property. |
| **INSTALLPROPERTY_INSTALLSOURCE** | The installation source. For more information, see the [SourceDir](https://learn.microsoft.com/windows/desktop/Msi/sourcedir) property. |
| **INSTALLPROPERTY_LOCALPACKAGE** | The local cached package. |
| **INSTALLPROPERTY_PUBLISHER** | The publisher. For more information, see the [Manufacturer](https://learn.microsoft.com/windows/desktop/Msi/manufacturer) property. |
| **INSTALLPROPERTY_URLINFOABOUT** | URL information. For more information, see the [ARPURLINFOABOUT](https://learn.microsoft.com/windows/desktop/Msi/arpurlinfoabout) property. |
| **INSTALLPROPERTY_URLUPDATEINFO** | The URL update information. For more information, see the [ARPURLUPDATEINFO](https://learn.microsoft.com/windows/desktop/Msi/arpurlupdateinfo) property. |
| **INSTALLPROPERTY_VERSIONMINOR** | The minor product version that is derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| **INSTALLPROPERTY_VERSIONMAJOR** | The major product version that is derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| **INSTALLPROPERTY_VERSIONSTRING** | The product version. For more information, see the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |

To retrieve the product ID, registered owner, or registered company from applications that are installed, set *szProperty* to one of the following text string values.

| Value | Description |
| --- | --- |
| ProductID | The product identifier. For more information, see the [ProductID](https://learn.microsoft.com/windows/desktop/Msi/productid) property. |
| RegCompany | The company that is registered to use the product. |
| RegOwner | The owner who is registered to use the product. |

To retrieve the instance type of the product, set *szProperty* to the following value. This property is available for advertised or installed products.

| Value | Description |
| --- | --- |
| InstanceType | A missing value or a value of 0 (zero) indicates a normal product installation. A value of one (1) indicates a product installed using a multiple instance transform and the [MSINEWINSTANCE](https://learn.microsoft.com/windows/desktop/Msi/msinewinstance) property. For more information, see [Installing Multiple Instances of Products and Patches](https://learn.microsoft.com/windows/desktop/Msi/installing-multiple-instances-of-products-and-patches). |

The properties in the following table can be retrieved from applications that are advertised or installed. These properties cannot be retrieved for product instances that are installed under a per-user-unmanaged context for user accounts other than current user account.

| Property | Description |
| --- | --- |
| **INSTALLPROPERTY_TRANSFORMS** | Transforms. |
| **INSTALLPROPERTY_LANGUAGE** | Product language. |
| **INSTALLPROPERTY_PRODUCTNAME** | Human readable product name. For more information, see the [ProductName](https://learn.microsoft.com/windows/desktop/Msi/productname) property. |
| **INSTALLPROPERTY_ASSIGNMENTTYPE** | Equals 0 (zero) if the product is advertised or installed per-user. <br><br>Equals one (1) if the product is advertised or installed per-computer for all users. |
| **INSTALLPROPERTY_PACKAGECODE** | Identifier of the package that a product is installed from. For more information, see the [Package Codes](https://learn.microsoft.com/windows/desktop/Msi/package-codes) property. |
| **INSTALLPROPERTY_VERSION** | Product version derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| **INSTALLPROPERTY_PRODUCTICON** | Primary icon for the package. For more information, see the [ARPPRODUCTICON](https://learn.microsoft.com/windows/desktop/Msi/arpproducticon) property. |
| **INSTALLPROPERTY_PACKAGENAME** | Name of the original installation package. |
| **INSTALLPROPERTY_AUTHORIZED_LUA_APP** | A value of one (1) indicates a product that can be serviced by non-administrators using [User Account Control (UAC) Patching](https://learn.microsoft.com/windows/desktop/Msi/user-account-control--uac--patching). A missing value or a value of 0 (zero) indicates that least-privilege patching is not enabled. Available in Windows Installer 3.0 or later. |

### `szValue` [out, optional]

A pointer to a buffer that receives the property value. This buffer should be large enough to contain the information. If the buffer is too small, the function returns **ERROR_MORE_DATA** and sets **pcchValue* to the number of **TCHAR** in the value, not including the terminating NULL character.

If *lpValue* is set to **NULL** and *pcchValue* is set to a valid pointer, the function returns **ERROR_SUCCESS** and sets **pcchValue* to the number of **TCHAR** in the value, not including the terminating NULL character. The function can then be called again to retrieve the value, with *lpValue* buffer large enough to contain **pcchValue* + 1 characters.

If *lpValue* and *pcchValue* are both set to **NULL**, the function returns **ERROR_SUCCESS** if the value exists, without retrieving the value.

### `pcchValue` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *lpValue* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *lpValue* is also **NULL**. Otherwise, the function returns **ERROR_INVALID_PARAMETER**.

## Return value

The **MsiGetProductInfoEx** function returns the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling process must have administrative privileges to get information for a product installed for a user other than the current user. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product is unadvertised or uninstalled. |
| **ERROR_UNKNOWN_PROPERTY** | The property is unrecognized. <br><br>**Note** The [MsiGetProductInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductinfoa) function returns **ERROR_UNKNOWN_PROPERTY** if the application being queried is advertised and not installed. |
| **ERROR_FUNCTION_FAILED** | An unexpected internal failure. |

## Remarks

When the
**MsiGetProductInfoEx** function returns, the *pcchValue* parameter contains the length of the string that is stored in the buffer. The count returned does not include the terminating null character. If the buffer is not big enough,
**MsiGetProductInfoEx** returns **ERROR_MORE_DATA**, and
the *pcchValue* parameter contains the size of the string, in **TCHAR**, without counting the null character.

The **MsiGetProductInfoEx** function (**INSTALLPROPERTY_LOCALPACKAGE**) returns a path to the cached package. The cached package is for internal use only. Maintenance mode installations must be invoked through the
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea),
[MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta), or
[MsiConfigureProductEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproductexa) functions.

The [MsiGetProductInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductinfoa) function returns **ERROR_UNKNOWN_PROPERTY** if the application being queried is advertised and not installed. For example, if the application is advertised and not installed, a query for **INSTALLPROPERTY_INSTALLLOCATION** returns an error of **ERROR_UNKNOWN_PROPERTY**.

> [!NOTE]
> The msi.h header defines MsiGetProductInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ARPHELPLINK](https://learn.microsoft.com/windows/desktop/Msi/arphelplink)

[ARPHELPTELEPHONE](https://learn.microsoft.com/windows/desktop/Msi/arphelptelephone)

[ARPINSTALLLOCATION](https://learn.microsoft.com/windows/desktop/Msi/arpinstalllocation)

[ARPPRODUCTICON](https://learn.microsoft.com/windows/desktop/Msi/arpproducticon)

[ARPURLINFOABOUT](https://learn.microsoft.com/windows/desktop/Msi/arpurlinfoabout)

[ARPURLUPDATEINFO](https://learn.microsoft.com/windows/desktop/Msi/arpurlupdateinfo)

[Manufacturer](https://learn.microsoft.com/windows/desktop/Msi/manufacturer)

[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea)

[MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta)

[MsiConfigureProductEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproductexa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[Package Codes](https://learn.microsoft.com/windows/desktop/Msi/package-codes)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[ProductID](https://learn.microsoft.com/windows/desktop/Msi/productid)

[ProductName](https://learn.microsoft.com/windows/desktop/Msi/productname)

[ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion)

[Properties](https://learn.microsoft.com/windows/desktop/Msi/properties)

[Required Properties](https://learn.microsoft.com/windows/desktop/Msi/required-properties)

[SourceDir](https://learn.microsoft.com/windows/desktop/Msi/sourcedir)

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)