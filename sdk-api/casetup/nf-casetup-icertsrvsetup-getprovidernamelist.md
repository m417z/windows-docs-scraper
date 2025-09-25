# ICertSrvSetup::GetProviderNameList

## Description

The **GetProviderNameList** method gets the list of [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) that provide asymmetric key signature algorithms on the computer. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_BSTR** types, where each string represents the name of a CSP.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)