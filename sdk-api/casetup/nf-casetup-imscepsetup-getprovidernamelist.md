# IMSCEPSetup::GetProviderNameList

## Description

The **GetProviderNameList** method gets the list of [cryptographic service providers](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSPs) that provide asymmetric key signature and exchange algorithms on the computer.

## Parameters

### `bExchange` [in]

A value that indicates whether the provider names are for exchange key algorithms. A **VARIANT_TRUE** value indicates exchange key providers; otherwise, the providers are for signing keys.

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_BSTR** types, where each string represents the name of a CSP.

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)