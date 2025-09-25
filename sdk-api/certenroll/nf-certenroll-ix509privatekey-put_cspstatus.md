# IX509PrivateKey::put_CspStatus

## Description

The **CspStatus** property specifies or retrieves an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object that contains information about the cryptographic provider and algorithm pair associated with the private key. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

The [Algorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_algorithm) and [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername) properties are automatically set when you call the **CspStatus** property. The **CspStatus** property is typically set during the enrollment process. That is, when a request template specifies multiple provider/algorithm pairs, the enrollment code sets the **CspStatus** property to the first enabled [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object and tries to create a private key. If a key cannot be created, the enrollment code sets this property to the next enabled **ICspStatus** object and tries again.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)