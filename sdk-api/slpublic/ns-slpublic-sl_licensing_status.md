# SL_LICENSING_STATUS structure

## Description

Represents the licensing status.

## Members

### `SkuId`

Type: **SLID**

The SKU ID.

### `eStatus`

Type: **[SLLICENSINGSTATUS](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sllicensingstatus)**

The licensing status.

### `dwGraceTime`

Type: **DWORD**

The grace time in minutes.

### `dwTotalGraceDays`

Type: **DWORD**

The predefined grace days in the license.

### `hrReason`

Type: **HRESULT**

The error of unlicensed status.

### `qwValidityExpiration`

Type: **UINT64**

The validity expiration day.