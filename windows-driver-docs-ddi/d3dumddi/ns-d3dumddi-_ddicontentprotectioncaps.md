# _DDICONTENTPROTECTIONCAPS structure

## Description

The DDICONTENTPROTECTIONCAPS structure describes a specific encryption and decode combination that the driver uses.

## Members

### `CryptoType` [in]

A GUID that indicates the encryption type that the driver uses. The currently defined GUIDs are:

#### D3DCRYPTOTYPE_AES128_CTR

A GUID that indicates the 128-bit AES-CRT block cipher.

#### D3DCRYPTOTYPE_PROPRIETARY

A GUID that indicates a proprietary encryption algorithm.

A **NULL** value indicates that no encryption is used.

### `DecodeProfile` [in]

A GUID that indicates the DirectX Video Acceleration (DirectX VA) decode profile that the driver uses along with the encryption type, which the **CryptoType** member specifies. Not all drivers allow all types of encryption. For example, MPEG2 IDCT frequently requires that the private libraries, which the hardware vendor supplies, perform the proprietary encryption. A **NULL** value indicates that DirectX VA decode profile is not used.

## Remarks

The runtime specifies a pointer to a DDICONTENTPROTECTIONCAPS structure in the **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure--along with the D3DDDICAPS_GETCONTENTPROTECTIONCAPS value in the **Type** member of D3DDDIARG_GETCAPS--in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to determine the content-protection capabilities that the driver supports. The driver's **GetCaps** returns a pointer to a populated D3DCONTENTPROTECTIONCAPS structure in the **pData** member of D3DDDIARG_GETCAPS that describes the content-protection capabilities that the driver supports. An application calls the **IDirect3DDevice9Video::GetContentProtectionCaps** method to retrieve these content-protection capabilities. For more information about **IDirect3DDevice9Video::GetContentProtectionCaps** and D3DCONTENTPROTECTIONCAPS, see the DirectX SDK documentation.

If the runtime specifies NULL_GUID (all zeros) in **DecodeProfile**, the driver should return the content-protection capabilities that are relevant for when a DirectX VA decode profile is not used. These content-protection capabilities correspond to the content-protection DDI functions that the driver optionally implements. For more information about these optional functions, see [Content Protection DDI](https://learn.microsoft.com/windows-hardware/drivers/display/content-protection-ddi).

If the encryption type that is specified in the **CryptoType** member is supported by the graphics hardware and the driver, but is not supported by the DirectX VA decode profile that is specified in the **DecodeProfile** member, the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function should return D3DDDIERR_UNSUPPORTEDCRYPTO. If the encryption type that is specified in the **CryptoType** member is not supported at all, the driver's **GetCaps** function should return D3DDDIERR_NOTAVAILABLE.

If the runtime specifies NULL_GUID in the **CryptoType** member, the driver should report a superset of its content-protection capabilities. For example, if encryption type A supports some capabilities and encryption type B supports some other capabilities, the driver should return the cumulative capabilities.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)