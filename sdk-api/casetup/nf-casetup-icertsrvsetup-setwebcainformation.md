# ICertSrvSetup::SetWebCAInformation

## Description

The **SetWebCAInformation** method sets the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) information for the Certification Authority Web Enrollment role. You can use this method to enable certificate-related requests to a remote CA through a web interface.

## Parameters

### `bstrCAConfiguration` [in]

A string that contains a valid configuration for the CA. The string must be in the form *ComputerName* or *ComputerName\CAName*, where *ComputerName* is the network name of the CA host computer, and *CAName* is the common name of the CA.

## Remarks

The **SetWebCAInformation** method pings the CA computer to verify that it is available on the network.

Upon success, **SetWebCAInformation** sets the ENUM_SETUPPROP_WEBCAMACHINE and ENUM_SETUPPROP_WEBCANAME properties for the Certification Authority Web Enrollment role configuration.
For more information about setup properties, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)