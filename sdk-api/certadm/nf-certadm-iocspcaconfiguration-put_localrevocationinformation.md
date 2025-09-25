# IOCSPCAConfiguration::put_LocalRevocationInformation

## Description

 The **LocalRevocationInformation** property gets or sets the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) of the local machine. This list provides additional revocation information, or supersedes information from the revocation provider configured by [ProviderCLSID](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfiguration-get_providerclsid).

This property is read/write.

## Parameters

## Remarks

The CRL used for the **LocalRevocationInformation** property can be signed or not signed. There is no signature verification for the CRL.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)