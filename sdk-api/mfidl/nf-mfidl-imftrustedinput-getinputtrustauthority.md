# IMFTrustedInput::GetInputTrustAuthority

## Description

Retrieves the input trust authority (ITA) for a specified stream. If the specified stream is not protected, this method must return MF_E_NOT_PROTECTED.

## Parameters

### `dwStreamID` [in]

The stream identifier for which the ITA is being requested.

### `riid` [in]

The interface identifier (IID) of the interface being requested. Currently the only supported value is IID_IMFInputTrustAuthority.

### `ppunkObject` [out]

Receives a pointer to the ITA's **IUnknown** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOINTERFACE** | The ITA does not expose the requested interface. |
| **MF_E_NOT_PROTECTED** | The specified stream is not protected. |

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)

[IMFTrustedInput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedinput)