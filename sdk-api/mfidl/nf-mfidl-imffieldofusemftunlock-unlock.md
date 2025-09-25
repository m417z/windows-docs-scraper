# IMFFieldOfUseMFTUnlock::Unlock

## Description

Unlocks a Media Foundation transform (MFT) so that the application can use it.

## Parameters

### `pUnkMFT` [in]

A pointer to the **IUnknown** interface of the MFT.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method authenticates the caller, using a private communication channel between the MFT and the object that implements the [IMFFieldOfUseMFTUnlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffieldofusemftunlock) interface. The details of the communication depend entirely on the implementation.

## See also

[Field of Use Restrictions](https://learn.microsoft.com/windows/desktop/medfound/field-of-use-restrictions)

[IMFFieldOfUseMFTUnlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffieldofusemftunlock)