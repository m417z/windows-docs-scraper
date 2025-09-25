# IX509CertificateRequestPkcs10::put_KeyContainerNamePrefix

## Description

The **KeyContainerNamePrefix** property specifies or retrieves a prefix used to create the container name for a new private key.

This property is read/write.

## Parameters

## Remarks

Each CryptoAPI [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) or Cryptography API: Next Generation (CNG) key provider maintains a key container for the private key. To retrieve the name of a key container for an existing key, use the [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername) property of the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) object.

A prefix can contain any string limited to the maximum length of the key container name and to legal container name characters. For example, if you do not call the [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername) property to specify a key container name, one is automatically created when the private key is created, and the prefix to the container name will be the string "lp". For another example, if you are creating a test harness and want to differentiate key containers by the programs that generated them, you can use the name of the executable as the prefix.

You must set this property before calling the [Encode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequest-encode) method, and you must initialize the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) object before calling this property. For more information, see any of the following methods:

* [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializedecode)
* [InitializeFromCertificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromcertificate)
* [InitializeFromPrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromprivatekey)
* [InitializeFromPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefrompublickey)
* [InitializeFromTemplateName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-initializefromtemplatename)

## See also

[IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)