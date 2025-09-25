# IMFInputTrustAuthority::GetDecrypter

## Description

Retrieves a decrypter transform.

## Parameters

### `riid` [in]

Interface identifier (IID) of the interface being requested. Currently this value must be IID_IMFTransform, which requests the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.

### `ppv` [out]

Receives a pointer to the interface. The caller must release the interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOINTERFACE** | The decrypter does not support the requested interface. |
| **MF_E_NOT_PROTECTED** | This input trust authority (ITA) does not provide a decrypter. |

## Remarks

The decrypter should be created in a disabled state, where any calls to [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) automatically fail. After the input trust authority (ITA) has verified that it is running inside the protected media path (PMP), the ITA should enable the decrypter.

An ITA is not required to provide a decrypter. If the source content is not encrypted, the method should return MF_E_NOT_PROTECTED. The PMP will then proceed without using a decrypter for that stream.

The ITA must create a new instance of its decrypter for each call to **GetDecrypter**. Do not return multiple references to the same decrypter. They must be separate instances because the Media Session might place them in two different branches of the topology.

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)