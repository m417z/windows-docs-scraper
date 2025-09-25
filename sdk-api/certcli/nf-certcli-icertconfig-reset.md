# ICertConfig::Reset

## Description

The **Reset** method resets the configuration query [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to point at the Certificate Services server configuration indexed on the specified configuration point. This method was first defined in the [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig) interface.

Each individual configuration indicates a specific Certificate Services server. Some Certificate Services servers may have multiple valid configurations in the configuration database.

## Parameters

### `Index` [in]

Specifies the configuration point used by the configuration query to index a Certificate Services server configuration. The first configuration is index zero.

### `pCount` [out]

A pointer to the number of configurations in the enterprise.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pCount* parameter points to a **Long** that contains the number of configurations in the enterprise.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is the number of configurations in the enterprise.

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertConfig2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2)

[Next](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-next)