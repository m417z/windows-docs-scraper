# ICertSrvSetup::SetCADistinguishedName

## Description

The **SetCADistinguishedName** method sets a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) common name and an optional distinguished name suffix.

## Parameters

### `bstrCADN` [in]

A string that contains the name for a CA in the form *CommonName*,*DistinguishedNameSuffix*, where the comma (,) and *DistinguishedNameSuffix* are optional.

The following table describes an example of a distinguished name, including the optional distinguished name suffix, for the computer *MyServer*.

| Value | Meaning |
| --- | --- |
| CN=mydomain-*MyServer*-CA | Common name for the *MyServer* computer that belongs to the *MyDomain* domain. |
| DC=*MyDomain*,DC=*MyCompany*,DC=com | Distinguished name suffix (optional) |
| CN=*MyDomain*-*MyServer*-CA,DC=*MyDomain*,DC=*MyCompany*,DC=com | Distinguished name including the optional suffix |

### `bIgnoreUnicode` [in]

A value that indicates whether to allow Unicode encoding of the name information. A value of **VARIANT_TRUE** enables Unicode encoding.

### `bOverwriteExistingKey` [in]

A value that indicates whether to allow the name in *bstrCADN*, even though a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) with the same name exists on the computer. A value of **VARIANT_TRUE** enables the method to overwrite the existing key.

### `bOverwriteExistingCAInDS` [in]

A value that indicates whether to allow the name in *bstrCADN*, even though a CA with the same distinguished name exists in the directory service. A value of **VARIANT_TRUE** enables the method to overwrite the existing directory service entry.

## Remarks

Upon success, the **SetCADistinguishedName** method changes the **ENUM_SETUPPROP_CANAME** and **ENUM_SETUPPROP_CADSSUFFIX** property values to reflect the *bstrCADN* name. For more information about setup properties, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

Upon failure, the **SetCADistinguishedName** method might set additional error information in the [CAErrorId](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetup-get_caerrorid) and [CAErrorString](https://learn.microsoft.com/windows/desktop/api/casetup/nf-casetup-icertsrvsetup-get_caerrorstring) properties.

If an existing key and its associated certificate are being used to configure the CA, this method must not be called. If an existing key is being used to configure the CA, without using the associated certificate, the common name in *bstrCADN* must match the [sanitized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) **ContainerName** of the key.

If *bstrCADN* includes UTF8 encoding, set the appropriate flag in CAPolicy.inf and place it in the %windir%.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)