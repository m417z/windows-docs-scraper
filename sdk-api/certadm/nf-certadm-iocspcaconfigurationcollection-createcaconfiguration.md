# IOCSPCAConfigurationCollection::CreateCAConfiguration

## Description

The **CreateCAConfiguration** method creates a new [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration and adds it to the configuration set.

## Parameters

### `bstrIdentifier` [in]

A string that contains a name for the new [IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration) object.

### `varCACert` [in]

An X.509 CA certificate.

### `ppVal` [out]

The address of a pointer to an [IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration) interface for the newly created object.

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

An
[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)
interface for the newly created object.

## See also

[IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection)