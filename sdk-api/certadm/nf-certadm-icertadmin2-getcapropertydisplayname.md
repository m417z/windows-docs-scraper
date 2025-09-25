# ICertAdmin2::GetCAPropertyDisplayName

## Description

The **GetCAPropertyDisplayName** method retrieves the property display name for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) property. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **GetCAPropertyDisplayName** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `PropId` [in]

Specifies the property identifier. For information about this parameter, see the table in
[ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty).

### `pstrDisplayName` [out]

A pointer to the string representing the property's display name.

It is the responsibility of the caller to free the **BSTR** when done by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates the method was successful.

### VB

A string that represents the property's display name.