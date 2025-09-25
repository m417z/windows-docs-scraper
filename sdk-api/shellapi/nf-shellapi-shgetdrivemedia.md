# SHGetDriveMedia function

## Description

Returns the type of media that is in the given drive.

## Parameters

### `pszDrive` [in]

Type: **PCWSTR**

The drive in which to check the media type.

### `pdwMediaContent` [out]

Type: **DWORD***

A pointer to the type of media in the given drive. A combination of [ARCONTENT](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iquerycancelautoplay-allowautoplay) flags.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.