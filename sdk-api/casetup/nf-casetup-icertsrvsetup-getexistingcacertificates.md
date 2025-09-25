# ICertSrvSetup::GetExistingCACertificates

## Description

The **GetExistingCACertificates** method gets the collection of **CertSrvSetupKeyInformation** objects that represent valid [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificates currently installed on the computer. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `ppVal` [out]

The address of a pointer to an [ICertSrvSetupKeyInformationCollection](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformationcollection) interface that can be used to access information for the set of valid CA certificates installed in the "LocalMachine" store.

## Remarks

The **CertSrvSetupKeyInformationCollection** object contains valid certificates. A certificate is considered valid if it satisfies the following criteria:

* Contains an AT_SIGNATURE key that matches the key in the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) container.
* Is self-signed or has basic constraints for a CA.
* Passes chain validation but might have an offline revocation error.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)