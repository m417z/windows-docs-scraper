# CASetupProperty enumeration

## Description

The **CASetupProperty** enumeration specifies a property type for setup and configuration of a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) role when using the [ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup) interface.

## Constants

### `ENUM_SETUPPROP_INVALID:-1`

A value that specifies a property type that is not valid.

### `ENUM_SETUPPROP_CATYPE:0`

A **VT_I4** value that specifies a value of the [ENUM_CATYPES](https://learn.microsoft.com/windows/desktop/api/certsrv/ne-certsrv-enum_catypes) enumeration.

If the computer is not joined to a domain, or the caller

is not an Enterprise or Domain administrator but is a local administrator, the default value is **ENUM_STANDALONE_ROOTCA**. If the computer is joined to a domain, the caller is an Enterprise or Domain administrator, and an enterprise root CA already exists, the default is **ENUM_ENTERPRISE_SUBCA**, or if no enterprise root CA exists, the default value is **ENUM_ENTERPRISE_ROOTCA**.

### `ENUM_SETUPPROP_CAKEYINFORMATION:1`

A **VT_DISPATCH** value, in the form of a **CCertSrvSetupKeyInformation** object, that specifies the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) information used for a CA certificate. By default, setup generates a new key

with a 2048-bit key length for root and subordinate CAs using "Microsoft

Strong Cryptographic Provider."

### `ENUM_SETUPPROP_INTERACTIVE:2`

A **VT_BOOL** value that indicates whether the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) is allowed to interact with the desktop. The default is false.

### `ENUM_SETUPPROP_CANAME:3`

A **VT_BSTR** value that contains the common name for the CA. By default, the common

name is *DomainName*-*LocalComputerName*-*CAName*.

### `ENUM_SETUPPROP_CADSSUFFIX:4`

A **VT_BSTR** value that contains the distinguished name suffix for a CA name.

### `ENUM_SETUPPROP_VALIDITYPERIOD:5`

A **VT_I4** value that specifies the number of units in the validity period as specified by the **ENUM_SETUPPROP_VALIDITYPERIODUNIT** property type. For a subordinate CA, the validity period is determined by the parent CA.

### `ENUM_SETUPPROP_VALIDITYPERIODUNIT:6`

A **VT_I4** value that specifies a value of the [ENUM_PERIOD](https://learn.microsoft.com/windows/desktop/api/celib/ne-celib-enum_period) enumeration that indicates the time units of the validity period. For a subordinate CA, the validity period time unit is determined by the parent CA.

### `ENUM_SETUPPROP_EXPIRATIONDATE:7`

A **VT_BSTR** value that specifies the expected expiration date of the root CA certificate based on the current time, validity period, and validity period unit. For a subordinate CA, the expiration date is

determined by its parent CA.

### `ENUM_SETUPPROP_PRESERVEDATABASE:8`

A **VT_BOOL** value that specifies whether to preserve an existing database. This is relevant under the following conditions:

* A CA

  was previously installed (and later uninstalled) on this computer.
* An existing key (and its associated certificate) is being used for installation.
* A database exists in the given database directory.

### `ENUM_SETUPPROP_DATABASEDIRECTORY:9`

A **VT_BSTR** value that specifies the path of the directory where CA database files are stored after installation. The default path is %SystemRoot%\System32\Certlog\.

### `ENUM_SETUPPROP_LOGDIRECTORY:10`

A **VT_BSTR** value that specifies the path of the directory where CA database log files are stored after installation. The default path is %SystemRoot%\System32\Certlog\.

### `ENUM_SETUPPROP_SHAREDFOLDER:11`

This value is not used and is reserved for future use.

### `ENUM_SETUPPROP_PARENTCAMACHINE:12`

A **VT_BSTR** value that specifies the name of the computer that is hosting the parent CA. This value is only applicable if a subordinate CA is being installed. There is no default value.

### `ENUM_SETUPPROP_PARENTCANAME:13`

A **VT_BSTR** value that specifies the name of the parent CA. This value is only applicable if a subordinate CA is being installed. There is no default value.

### `ENUM_SETUPPROP_REQUESTFILE:14`

A **VT_BSTR** value that specifies the file path to use to save a subordinate CA request, so that it can be submitted later to the parent CA. The default value is %SystemDrive%\\*DNSMachineName*_*CAName*.req.

### `ENUM_SETUPPROP_WEBCAMACHINE:15`

A **VT_BSTR** value that specifies the name of the computer that is hosting the CA. This value is only applicable if support for the Certification Authority Web Enrollment role is being installed. There is no default value.

### `ENUM_SETUPPROP_WEBCANAME:16`

A **VT_BSTR** value that specifies the name of the CA. This value is only applicable if support for the Certification Authority Web Enrollment role is being installed. There is no default value.