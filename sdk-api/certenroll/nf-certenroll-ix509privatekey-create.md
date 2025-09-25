# IX509PrivateKey::Create

## Description

The **Create** method creates an asymmetric [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| **HRESULT_FROM_WIN32(ERROR_BUSY)** | The CSP handle is not **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_FILE_EXISTS)** | The key already exists. |

## Remarks

If you do not set the [CspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_cspstatus), the [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername), or [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype) properties, this method uses the default provider, key size, and [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) values when creating the key. On a new operating system installation, for example, Microsoft Enhanced Cryptographic Provider v1.0 is the default provider.

If you do not set the [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername) property, this method automatically generates a name. The generated name includes a GUID and, if the [ContainerNamePrefix](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containernameprefix) property is not set, a prefix of "lp-". If the provider is a smart card provider, the generated name will not exceed the [MaxKeyContainerNameLength](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_maxkeycontainernamelength) value specified by the provider. If the generated name initially exceeds this value, it is truncated to forty characters.

You cannot set the following properties after calling the **Create** or [Open](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-open) methods. If you wish to specify them, you must do so before calling either of these methods.

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

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)