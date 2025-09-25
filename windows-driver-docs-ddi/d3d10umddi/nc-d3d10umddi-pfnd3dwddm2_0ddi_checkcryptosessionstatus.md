# PFND3DWDDM2_0DDI_CHECKCRYPTOSESSIONSTATUS callback function

## Description

**CheckCryptoSessionStatus** returns the status of a **CryptoSession** object.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `hCryptoSession`

A handle to the cryptographic session object that was created through a call to the [CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)DDI.

### `pStatus`

Receives a status as a value of the [D3DWDDM2_0DDI_CRYPTO_SESSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_crypto_session_status) enumeration.

## Remarks

The application may call this DDI after receiving a hardware content protection tear-down notification to determine the state of the underlying hardware key and protected content.

## See also

[CreateCryptoSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createcryptosession)

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DWDDM2_0DDI_CRYPTO_SESSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3dwddm2_0ddi_crypto_session_status)