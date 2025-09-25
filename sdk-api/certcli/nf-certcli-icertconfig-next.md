# ICertConfig::Next

## Description

The **Next** method retrieves the index of the next available Certificate Services server configuration in the configuration point. This method was first defined in the [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig) interface.

## Parameters

### `pIndex` [out]

A pointer to a **Long** variable that will contain the index of the enumerated configuration, or –1 if there are no more configurations to enumerate.

## Return value

### C++

If the method succeeds, the method returns S_OK, and the *pIndex* parameter contains the index of the enumerated configuration. If there are no more configurations to enumerate, the return value is S_FALSE, and the *pIndex* parameter points to a value of –1.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a value that specifies the index of the next available Certificate Services server configuration in the configuration point. If no more configurations are available, the method returns a value of –1.

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertConfig2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2)

[Reset](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-reset)