# IMFOutputTrustAuthority::SetPolicy

## Description

Sets one or more policy objects on the output trust authority (OTA).

## Parameters

### `ppPolicy` [in]

The address of an array of [IMFOutputPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputpolicy) pointers.

### `nPolicy` [in]

The number of elements in the *ppPolicy* array.

### `ppbTicket` [out]

Receives either a pointer to a buffer allocated by the OTA, or the value **NULL**. If this parameter receives a non-**NULL** value, the caller must release the buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

**Note** Currently this parameter is reserved. An OTA should set the pointer to **NULL**.

### `pcbTicket` [out]

Receives the size of the *ppbTicket* buffer, in bytes. If *ppbTicket* receives the value **NULL**, *pcbTicket* receives the value zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_S_WAIT_FOR_POLICY_SET** | The policy was negotiated successfully, but the OTA will enforce it asynchronously. |
| **MF_E_POLICY_UNSUPPORTED** | The OTA does not support the requirements of this policy. |

## Remarks

If the method returns **MF_S_WAIT_FOR_POLICY_SET**, the OTA sends an [MEPolicySet](https://learn.microsoft.com/windows/desktop/medfound/mepolicyset) event when it enforces the policy.

## See also

[IMFOutputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputtrustauthority)