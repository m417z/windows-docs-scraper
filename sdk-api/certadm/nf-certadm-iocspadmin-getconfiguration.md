# IOCSPAdmin::GetConfiguration

## Description

The **GetConfiguration** method connects to an Online Certificate Status Protocol (OCSP) responder server and initializes an **OCSPAdmin** object with the configuration information from the server.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `bForce` [in]

|  |  |
| --- | --- |
| **C++** | **VARIANT_TRUE** if the caller wants to read the responder configuration from the server's registry when a running instance of the OCSP responder service cannot be found; otherwise, **VARIANT_FALSE**. |
| **VB** | **True** if the caller wants to read the responder configuration from the server's registry when a running instance of the OCSP responder service cannot be found; otherwise, **False**. |

## Return value

### VB

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

If the method returns **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)**, the configuration is already initialized.

If the method returns **E_INVALIDARG**, the *pVal* parameter was set to **NULL**.

## Remarks

The following table lists the effects of the *bForce* parameter value on the method call.

| OCSP responder service on the target server | *bForce* is **VARIANT_TRUE** | *bForce* is **VARIANT_FALSE** |
| --- | --- | --- |
| Running | Retrieve configuration from the service. | Retrieve configuration from the service. |
| Stopped | Attempt to retrieve configuration from the server registry. If this attempt fails, return an error. | Return an error. |

The following table lists the effects of the *bForce* parameter value on the method call.

| OCSP responder service on the target server | *bForce* is **True** | *bForce* is **False** |
| --- | --- | --- |
| Running | Retrieve configuration from the service. | Retrieve configuration from the service. |
| Stopped | Attempt to retrieve configuration from the server registry. If this attempt fails, return an error. | Return an error. |

This method attempts to read the configuration from a running instance of an OCSP responder service, but that might not be possible if the service is not running or is in an inaccessible state. The caller can instruct the method to read the configuration from the server's registry if a running instance cannot be found.

The method fails if you try to call it more than once for a given **OCSPAdmin** object. Each instance of **OCSPAdmin** corresponds to one responder server. To connect to another server in an array of OCSP responder servers, create a new instance of an **OCSPAdmin** object.

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)