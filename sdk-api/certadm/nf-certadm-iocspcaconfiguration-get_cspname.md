# IOCSPCAConfiguration::get_CSPName

## Description

The **CSPName** property gets a [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) or [key storage provider](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSP) name. The default implementations of [IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) and [IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection) set this value.

This property is read-only.

## Parameters

## Remarks

The name returned in *pVal* corresponds to the CSP or KSP used for the [SigningCertificate](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfiguration-get_signingcertificate) property.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)