# IWSDSignatureProperty::IsMessageSignatureTrusted

## Description

Specifies if a message signature is trusted.

## Parameters

### `pbSignatureTrusted` [out]

A pointer to a boolean that specifies if a message signature is trusted.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## Remarks

A message is trusted if the signing certificate is among one of the certificates or in the certificate store passed down by the calling application in the [WSDCreateDiscoveryProvider2](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-wsdcreatediscoveryprovider2) call.

## See also

[IWSDSignatureProperty](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsignatureproperty)