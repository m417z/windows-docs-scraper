# IOCSPCAConfiguration::get_CACertificate

## Description

The **CACertificate** property gets an X.509 certificate that has been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) and that is for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). The default implementations of [IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) and [IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection) methods set this value.

This property is read-only.

## Parameters

## Remarks

The *pVal* certificate corresponds to the certificate used in the *varCACert* parameter of the [CreateCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfigurationcollection-createcaconfiguration) method to create the configuration.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)