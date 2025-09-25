# IOCSPCAConfiguration::put_CAConfig

## Description

The **CAConfig** property gets or sets a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) name with which a signing certificate must be signed.

The **CAConfig** property contains a CA name. This name lets an Online Certificate Status Protocol (OCSP) signing-certificate renewal request specify the issuing CA. The new signing certificate must be signed with this CA.

This property supports responses to status requests for a certificate that has been replaced but is still valid.

This property is read/write.

## Parameters

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)