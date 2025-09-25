# IMFInputTrustAuthority::BindAccess

## Description

Notifies the input trust authority (ITA) that a requested action is about to be performed.

## Parameters

### `pParam` [in]

Pointer to an [MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mfinputtrustauthority_access_params) structure that contains parameters for the **BindAccess** action.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, the Media Session calls [IMFInputTrustAuthority::RequestAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfinputtrustauthority-requestaccess) to request an action. The **BindAccess** method notifies the ITA that the action is definitely about to occur, so that the ITA can update its internal state as needed. If the method returns a failure code, the Media Session cancels the action.

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)