# MsiGetProductInfoA function

## Description

The
**MsiGetProductInfo** function returns product information for published and installed products.

## Parameters

### `szProduct` [in]

Specifies the product code for the product.

### `szAttribute` [in]

Specifies the property to be retrieved.

The
[Required Properties](https://learn.microsoft.com/windows/desktop/Msi/required-properties) are guaranteed to be available, but other properties are available only if that property is set. For more information, see [Properties](https://learn.microsoft.com/windows/desktop/Msi/properties). The properties in the following list can be retrieved only from applications that are installed.

| Property | Meaning |
| --- | --- |
| **INSTALLPROPERTY_HELPLINK** | Support link. For more information, see the [ARPHELPLINK](https://learn.microsoft.com/windows/desktop/Msi/arphelplink) property. |
| **INSTALLPROPERTY_HELPTELEPHONE** | Support telephone. For more information, see the [ARPHELPTELEPHONE](https://learn.microsoft.com/windows/desktop/Msi/arphelptelephone) property. |
| **INSTALLPROPERTY_INSTALLDATE** | The last time this product received service. The value of this property is replaced each time a patch is applied or removed from the product or the /v [Command-Line Option](https://learn.microsoft.com/windows/desktop/Msi/command-line-options) is used to repair the product. If the product has received no repairs or patches this property contains the time this product was installed on this computer. |
| **INSTALLPROPERTY_INSTALLEDLANGUAGE** | Installed language.<br><br>**[Windows Installer 4.5 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-5):** Not supported. |
| **INSTALLPROPERTY_INSTALLEDPRODUCTNAME** | Installed product name. For more information, see the [ProductName](https://learn.microsoft.com/windows/desktop/Msi/productname) property. |
| **INSTALLPROPERTY_INSTALLLOCATION** | Installation location. For more information, see the [ARPINSTALLLOCATION](https://learn.microsoft.com/windows/desktop/Msi/arpinstalllocation) property. |
| **INSTALLPROPERTY_INSTALLSOURCE** | Installation source. For more information, see the [SourceDir](https://learn.microsoft.com/windows/desktop/Msi/sourcedir) property. |
| **INSTALLPROPERTY_LOCALPACKAGE** | Local cached package. |
| **INSTALLPROPERTY_PUBLISHER** | Publisher. For more information, see the [Manufacturer](https://learn.microsoft.com/windows/desktop/Msi/manufacturer) property. |
| **INSTALLPROPERTY_URLINFOABOUT** | URL information. For more information, see the [ARPURLINFOABOUT](https://learn.microsoft.com/windows/desktop/Msi/arpurlinfoabout) property. |
| **INSTALLPROPERTY_URLUPDATEINFO** | URL update information. For more information, see the [ARPURLUPDATEINFO](https://learn.microsoft.com/windows/desktop/Msi/arpurlupdateinfo) property. |
| **INSTALLPROPERTY_VERSIONMINOR** | Minor product version derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| **INSTALLPROPERTY_VERSIONMAJOR** | Major product version derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| **INSTALLPROPERTY_VERSIONSTRING** | Product version. For more information, see the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |

To retrieve the product ID, registered owner, or registered company from applications that are installed, set *szProperty* to one of the following text string values.

| Value | Description |
| --- | --- |
| ProductID | The product identifier for the product. For more information, see the [ProductID](https://learn.microsoft.com/windows/desktop/Msi/productid) property. |
| RegCompany | The company registered to use this product. |
| RegOwner | The owner registered to use this product. |

To retrieve the instance type of the product, set *szProperty* to the following value. This property is available for advertised or installed products.

| Value | Description |
| --- | --- |
| InstanceType | A missing value or a value of 0 (zero) indicates a normal product installation. A value of 1 (one) indicates a product installed using a multiple instance transform and the MSINEWINSTANCE property. Available with the installer running Windows Server 2003 or Windows XP with SP1. For more information see, [Installing Multiple Instances of Products and Patches](https://learn.microsoft.com/windows/desktop/Msi/installing-multiple-instances-of-products-and-patches). |

The advertised properties in the following list can be retrieved from applications that are advertised or installed.

| Property | Description |
| --- | --- |
| INSTALLPROPERTY_TRANSFORMS | Transforms. |
| INSTALLPROPERTY_LANGUAGE | Product language. |
| INSTALLPROPERTY_PRODUCTNAME | Human readable product name. For more information, see the [ProductName](https://learn.microsoft.com/windows/desktop/Msi/productname) property. |
| INSTALLPROPERTY_ASSIGNMENTTYPE | Equals 0 (zero) if the product is advertised or installed per-user. <br><br>Equals 1 (one) if the product is advertised or installed per-machine for all users. |
| INSTALLPROPERTY_PACKAGECODE | Identifier of the package this product was installed from. For more information, see [Package Codes](https://learn.microsoft.com/windows/desktop/Msi/package-codes). |
| INSTALLPROPERTY_VERSION | Product version derived from the [ProductVersion](https://learn.microsoft.com/windows/desktop/Msi/productversion) property. |
| INSTALLPROPERTY_PRODUCTICON | Primary icon for the package. For more information, see the [ARPPRODUCTICON](https://learn.microsoft.com/windows/desktop/Msi/arpproducticon) property. |
| INSTALLPROPERTY_PACKAGENAME | Name of the original installation package. |
| INSTALLPROPERTY_AUTHORIZED_LUA_APP | A value of one (1) indicates a product that can be serviced by non-administrators using [User Account Control (UAC) Patching](https://learn.microsoft.com/windows/desktop/Msi/user-account-control--uac--patching). A missing value or a value of 0 (zero) indicates that least-privilege patching is not enabled. Available in Windows Installer 3.0 or later. |

### `lpValueBuf` [out]

Pointer to a buffer that receives the property value. This parameter can be null.

### `pcchValueBuf` [in, out]

 Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpValueBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpValueBuf* is null, *pcchValueBuf* can be null. In this case, the function checks that the property is registered correctly with the product.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product is unadvertised or uninstalled. |
| **ERROR_UNKNOWN_PROPERTY** | The property is unrecognized.<br><br>**Note** The [MsiGetProductInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductinfoa) function returns ERROR_UNKNOWN_PROPERTY if the application being queried is advertised and not installed. |

## Remarks

When the
**MsiGetProductInfo** function returns, the *pcchValueBuf* parameter contains the length of the string stored in the buffer. The count returned does not include the terminating null character. If the buffer is not large enough,
**MsiGetProductInfo** returns ERROR_MORE_DATA and
*pcchValueBuf* contains the size of the string, in characters, without counting the null character.

**MsiGetProductInfo**(INSTALLPROPERTY_LOCALPACKAGE) does not necessarily return a path to the cached package. The cached package is for internal use only. Maintenance mode installations should be invoked through the
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea),
[MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta), or
[MsiConfigureProductEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproductexa) functions.

If you attempt to use **MsiGetProductInfo** to query an advertised product for a property that is only available to installed products, the function returns ERROR_UNKNOWN_PROPERTY. For example, if the application is advertised and not installed, a query for the INSTALLPROPERTY_INSTALLLOCATION property returns an error of ERROR_UNKNOWN_PROPERTY.

> [!NOTE]
> The msi.h header defines MsiGetProductInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Determining Installation Context](https://learn.microsoft.com/windows/desktop/Msi/determining-installation-context)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)