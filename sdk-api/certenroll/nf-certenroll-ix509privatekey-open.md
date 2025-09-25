# IX509PrivateKey::Open

## Description

The **Open** method opens an existing [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If successful, this method sets the [Opened](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_opened) property. You must call either the **Open** or [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create) methods before calling the [Export](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-export) method or [ExportPublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-exportpublickey) method.

You cannot set the following properties after calling the **Open** or [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create) methods. If you wish to specify them, you must do so before calling either of these methods.

* [Algorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_algorithm)
* [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername)
* [ContainerNamePrefix](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containernameprefix)
* [CspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_cspinformations)
* [CspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_cspstatus)
* [Description](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_description)
* [Existing](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_existing)
* [ExportPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_exportpolicy)
* [FriendlyName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_friendlyname)
* [KeyProtection](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyprotection)
* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [KeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyusage)
* [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp)
* [Length](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_length)
* [MachineContext](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_machinecontext)
* [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername)
* [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype)
* [Pin](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-put_pin)
* [ReaderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_readername)
* [Silent](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_silent)
* [UIContextMessage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_uicontextmessage)

The following properties can be set regardless of whether the key is open:

* [Certificate](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_certificate)
* [ParentWindow](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_parentwindow)
* [SecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_securitydescriptor)

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)