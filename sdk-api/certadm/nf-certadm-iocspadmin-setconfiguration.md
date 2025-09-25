# IOCSPAdmin::SetConfiguration

## Description

The **SetConfiguration** method updates a responder service with configuration changes.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-service name.

### `bForce` [in]

|  |  |
| --- | --- |
| **C++** | **VARIANT_TRUE** if the method should update the responder service registry when the service is offline or unavailable; otherwise, **VARIANT_FALSE**. If the service is offline or unavailable and the *bForce* parameter is **VARIANT_TRUE**, **SetConfiguration** updates the responder service registry directly. |
| **VB** | **True** if the method should update the responder service registry when the service is offline or unavailable; otherwise, **False**. If the service is offline or unavailable and the *bForce* parameter is **True**, **SetConfiguration** updates the responder service registry directly. |

## Return value

### VB

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

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

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)