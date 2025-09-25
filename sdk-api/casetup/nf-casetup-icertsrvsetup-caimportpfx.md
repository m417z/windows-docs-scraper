# ICertSrvSetup::CAImportPFX

## Description

The **CAImportPFX** method imports a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate and its associated [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) into the local computer store. This method does not change the state of the **CCertSrvSetup** object.

## Parameters

### `bstrFileName` [in]

A string that contains the name of a PFX file used to import a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `bstrPasswd` [in]

A string that contains a password for the PFX file.

### `bOverwriteExistingKey` [in]

A value that indicates whether to overwrite an existing key of the same name.

### `ppVal` [out]

The address of a pointer to an [ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation) interface that can be used to set properties of the imported private key.

## Remarks

The **CAImportPFX** method uses the input parameters to decrypt and decode a PFX file and then installs the key and [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) in the local computer store. If the certificate satisfies the following criteria and after installation of the key, the method returns an [ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation) object to the caller.

* Contains an AT_SIGNATURE key that matches the key in the private key container.
* Is self-signed or has basic constraints for a CA.
* Passes chain validation but might have an offline revocation error.

If the PFX file contains multiple certificates and keys, **CAImportPFX** installs all of the certificates and keys; however, the returned [ICertSrvSetupKeyInformation](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetupkeyinformation) object only contains properties of the last CA certificate in the file. When the caller finishes using the **ICertSrvSetupKeyInformation** object, the caller must release it by using the [Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)