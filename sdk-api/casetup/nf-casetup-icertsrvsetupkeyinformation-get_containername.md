# ICertSrvSetupKeyInformation::get_ContainerName

## Description

The **ContainerName** property gets or sets the name used by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to generate, store, or access the key.

This property is read/write.

## Parameters

## Remarks

If the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) already exists, this name must match the name used by the CSP to access the key.

## See also

[ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation)