# APPX_PACKAGE_SETTINGS structure

## Description

Represents package settings used to create a package.

## Members

### `forceZip32`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the package is created as Zip32; **FALSE** if the package is created as Zip64. The default is Zip64.

### `hashMethod`

Type: ****IUri*****

The hash algorithm URI to use for the block map of the package.

## Remarks

Set **forceZip32** to **TRUE** to maintain compatibility with older ZIP tools.

The possible values for **hashMethod** are:

* http://www.w3.org/2001/04/xmlenc#sha256
* http://www.w3.org/2001/04/xmldsig-more#sha384
* http://www.w3.org/2001/04/xmlenc#sha512

## See also

[IAppxFactory::CreatePackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxfactory-createpackagewriter)