# MSCEPSetupProperty enumeration

## Description

The **MSCEPSetupProperty** enumeration specifies a property type for setup and configuration of a Microsoft [Simple Certificate Enrollment Protocol](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SCEP) role using [IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup).

## Constants

### `ENUM_CEPSETUPPROP_USELOCALSYSTEM:0`

A **VT_BOOL** value that specifies whether the Microsoft SCEP ISAPI Extension runs as the local system user or under a separate user account. For remote CA or standalone CA configurations, by default this is set to **VARIANT_FALSE**. For a local enterprise CA configuration, by default this is set to **VARIANT_TRUE**.

### `ENUM_CEPSETUPPROP_USECHALLENGE:1`

A **VT_BOOL** value that specifies whether to require an SCEP challenge phrase to enroll. By default, setup sets this to **TRUE**.

### `ENUM_CEPSETUPPROP_RANAME_CN:2`

A **VT_BSTR** value that specifies the common name for Microsoft SCEP registration authority (RA) certificate name information. By default, the common name format is *MachineName*"-RA", where *MachineName* is the local machine name.

### `ENUM_CEPSETUPPROP_RANAME_EMAIL:3`

A **VT_BSTR** value that specifies an optional email address to be added in Microsoft SCEP RA certificate name information.

### `ENUM_CEPSETUPPROP_RANAME_COMPANY:4`

A **VT_BSTR** value that specifies an optional company name to be added in Microsoft SCEP RA certificate name information.

### `ENUM_CEPSETUPPROP_RANAME_DEPT:5`

A **VT_BSTR** value that specifies an optional department name to be added in Microsoft SCEP RA certificate name information.

### `ENUM_CEPSETUPPROP_RANAME_CITY:6`

A **VT_BSTR** value that specifies an optional city name to be added in Microsoft SCEP RA certificate name information.

### `ENUM_CEPSETUPPROP_RANAME_STATE:7`

A **VT_BSTR** value that specifies an optional state name to be added in Microsoft SCEP RA certificate name information.

### `ENUM_CEPSETUPPROP_RANAME_COUNTRY:8`

A **VT_BSTR** value that specifies the country or region name to be added in Microsoft SCEP RA certificate name information. By default, setup uses the country or region setting for the local computer.

### `ENUM_CEPSETUPPROP_SIGNINGKEYINFORMATION:9`

A **VT_IDISPATCH** value that is made up of an [ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation) object used to create a Microsoft SCEP signing certificate. Setup creates a signing certificate based on an "EnrollmentAgentOffline" template.

### `ENUM_CEPSETUPPROP_EXCHANGEKEYINFORMATION:10`

A **VT_IDISPATCH** value that is made up of an [ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation) object used to create a Microsoft SCEP key exchange certificate. Setup creates a key exchange certificate based on a "CEPEncryption" template.

### `ENUM_CEPSETUPPROP_CAINFORMATION:11`

A **VT_BSTR** value that specifies the Certification Authority (CA) information. By default, setup uses the local CA. If a local CA is present, you should not set this property.

### `ENUM_CEPSETUPPROP_MSCEPURL:12`

A **VT_BSTR** value that specifies the URL for use by routers to connect and send certificate requests using SCEP. By default, setup uses http://*MachineName*/certsrv/mscep/mscep.dll, where *MachineName* is the local machine name. This is a read-only property.

### `ENUM_CEPSETUPPROP_CHALLENGEURL:13`

A **VT_BSTR** value that specifies the URL for use by router administrators to connect and obtain a challenge phrase. By default, setup uses http://*MachineName*/certsrv/mscep/, where *MachineName* is the local machine name. This is a read-only property.