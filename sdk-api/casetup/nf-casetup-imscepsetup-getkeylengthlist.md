# IMSCEPSetup::GetKeyLengthList

## Description

The **GetKeyLengthList** method gets the list of [key lengths](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) supported by the specified [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

## Parameters

### `bExchange` [in]

A value that indicates whether the listed lengths are for an exchange key algorithm. A **VARIANT_TRUE** value indicates exchange key lengths; otherwise, the lengths are for signing keys.

### `bstrProviderName` [in]

A string that contains the name of the CSP.

### `pVal` [out]

A pointer to a **VARIANT** array of **VT_UI4** types that correspond to the key lengths supported by the CSP.

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)