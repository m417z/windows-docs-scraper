# SOFTDISTINFO structure

## Description

Contains information about a software update.

## Members

### `cbSize`

Type: **ULONG**

The size of the structure, in bytes.

### `dwFlags`

Type: **DWORD**

This parameter can take one of the following values.

#### SOFTDIST_FLAG_USAGE_EMAIL

#### SOFTDIST_FLAG_USAGE_PRECACHE

#### SOFTDIST_FLAG_USAGE_AUTOINSTALL

#### SOFTDIST_FLAG_DELETE_SUBSCRIPTION

### `dwAdState`

Type: **DWORD**

The advertised state. It can take one of the following values.

#### SOFTDIST_ADSTATE_NONE (0x00000000)

"Update available" dialog box has not been presented to the user.

#### SOFTDIST_ADSTATE_AVAILABLE (0x00000001)

"Files downloaded" dialog box has not been presented to the user.

#### SOFTDIST_ADSTATE_DOWNLOADED (0x00000002)

"Program installed" dialog box has not been presented to the user.

#### SOFTDIST_ADSTATE_INSTALLED (0x00000003)

"Program installed" dialog box has been presented to the user.

### `szTitle`

Type: **LPWSTR**

A string that contains the contents of the TITLE flag from the associated .cdf file.

### `szAbstract`

Type: **LPWSTR**

A string that contains the contents of the ABSTRACT flag from the associated .cdf file.

### `szHREF`

Type: **LPWSTR**

A string that contains the URL of the webpage to advertise or install the update.

### `dwInstalledVersionMS`

Type: **DWORD**

The most-significant unsigned long integer value of the installed version number.

### `dwInstalledVersionLS`

Type: **DWORD**

The least-significant unsigned long integer value of the installed version number.

### `dwUpdateVersionMS`

Type: **DWORD**

The most-significant unsigned long integer value of the update version number.

### `dwUpdateVersionLS`

Type: **DWORD**

The least-significant unsigned long integer value of the update version number.

### `dwAdvertisedVersionMS`

Type: **DWORD**

The most-significant unsigned long integer value of the advertised version number.

### `dwAdvertisedVersionLS`

Type: **DWORD**

The least-significant unsigned long integer value of the advertised version number.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Remarks

The most-significant unsigned long integer of a version number contains the major and minor version numbers. The least-significant unsigned long integer of the version number contains the custom version and build numbers.