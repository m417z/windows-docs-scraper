# ICertRequest2::GetCAPropertyFlags

## Description

The **GetCAPropertyFlags** method retrieves the property flags for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) property.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form *ComputerName***\\***CAName*, where *ComputerName* is the network name of the Certificate Services server, and *CAName* is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

### `PropId` [in]

Specifies the property identifier. For information about this parameter, see the table in
[ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty).

### `pPropFlags` [out, retval]

A pointer to a **LONG** value that represents the property flags.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Long** that represents the property flags.

## Remarks

The **GetCAPropertyFlags** method's functionality is similar to that of the [ICertAdmin2::GetCAPropertyFlags](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcapropertyflags) method.

In the ICertAdmin2 method, the CA enforces that the caller has CA read access, which is usually only granted to CA officers and CA administrators.

By contrast, in the ICertRequest2 and ICertRequest3 implementations of the method, the CA does not require any access rights by default. Only Distributed Component Object Model (DCOM) [access control lists](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACLs) are enforced; for a domain-joined CA, the DCOM ACLs allow Everyone access to the CAs. Everyone does not include Anonymous.
The CA's request interface can be locked down by using the registry configuration to enforce that the caller has enroll access.

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest2)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)