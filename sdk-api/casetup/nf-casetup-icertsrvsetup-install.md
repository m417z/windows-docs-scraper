# ICertSrvSetup::Install

## Description

The **Install** method installs a role as configured in the **CCertSrvSetup** object.

## Remarks

The [InitializeDefaults](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetup-initializedefaults) method must be called before calling this or any other method on a **CCertSrvSetup** object.

Unless the key already exists, the **Install** method creates a key for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate. If the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) requires interaction, it prompts the user.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)