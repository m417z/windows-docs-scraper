# IMFInputTrustAuthority::Reset

## Description

Resets the input trust authority (ITA) to its initial state.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When this method is called, the ITA should disable any decrypter that was returned in the [IMFInputTrustAuthority::GetDecrypter](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfinputtrustauthority-getdecrypter) method.

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)