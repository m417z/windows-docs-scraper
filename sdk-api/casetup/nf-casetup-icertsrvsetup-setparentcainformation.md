# ICertSrvSetup::SetParentCAInformation

## Description

The **SetParentCAInformation** method sets the parent [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) information for a subordinate CA configuration. This facilitates retrieval and installation of the subordinate certificate directly from the parent CA. The parent CA must be a Microsoft CA.

## Parameters

### `bstrCAConfiguration` [in]

A string that contains a valid configuration for the parent CA. The string must be in the form *ComputerName* or *ComputerName\CAName*, where *ComputerName* is the network name of the parent CA host computer, and *CAName* is the common name of the parent CA.

## Remarks

The **SetParentCAInformation** method pings the parent CA computer to verify that it is available on the network.

Upon success, **SetParentCAInformation** sets the ENUM_SETUPPROP_PARENTCAMACHINE and ENUM_SETUPPROP_PARENTCANAME properties for the subordinate CA configuration.
For more information about setup properties, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)