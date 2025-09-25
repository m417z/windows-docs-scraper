# DD_MISCELLANEOUS2CALLBACKS structure

## Description

The DD_MISCELLANEOUS2CALLBACKS structure is used to return the addresses of miscellaneous callback routines. These routines are new for Microsoft DirectX 7.0 and later and are exposed through [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) by responding to the GUID_Miscellaneous2Callbacks GUID.

## Members

### `dwSize`

Specifies the size, in bytes, of this structure.

### `dwFlags`

Indicates which miscellaneous callback functions the driver implemented. For every bit set in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be one or more of the following flags:

DDHAL_MISC2CB32_CREATESURFACEEX

DDHAL_MISC2CB32_GETDRIVERSTATE

DDHAL_MISC2CB32_DESTROYDDLOCAL

### `AlphaBlt`

Unused and must be set to **NULL**.

### `CreateSurfaceEx`

Points to the driver's [D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex) implementation. This callback creates an association between a DirectDraw surface and a small integer handle.

### `GetDriverState`

Points to the driver's [D3dGetDriverState](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverstate) implementation.

### `DestroyDDLocal`

Points to the driver's [D3dDestroyDDLocal](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_destroyddlocal) implementation. Used to destroy the local copy of the device context.

## See also

[D3dCreateSurfaceEx](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createsurfaceex)

[D3dDestroyDDLocal](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_destroyddlocal)

[D3dGetDriverState](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverstate)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)