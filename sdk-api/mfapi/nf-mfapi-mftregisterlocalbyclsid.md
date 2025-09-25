# MFTRegisterLocalByCLSID function

## Description

Registers a Media Foundation transform (MFT) in the caller's process.

## Parameters

### `clisdMFT` [in]

The class identifier (CLSID) of the MFT.

### `guidCategory` [in]

A GUID that specifies the category of the MFT. For a list of MFT categories, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `pszName` [in]

A wide-character null-terminated string that contains the friendly name of the MFT.

### `Flags` [in]

A bitwise **OR** of zero or more flags from the [_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag) enumeration.

### `cInputTypes` [in]

The number of elements in the *pInputTypes* array.

### `pInputTypes` [in]

A pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array specifies an input format that the MFT supports. This parameter can be **NULL** if *cInputTypes* is zero.

### `cOutputTypes` [in]

The number of elements in the *pOutputTypes* array.

### `pOutputTypes` [in]

A pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array defines an output format that the MFT supports. This parameter can be **NULL** if *cOutputTypes* is zero.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The primary purpose of this function is to make an MFT available for automatic topology resolution without making the MFT available to other processes or applications.

After you call this function, the MFT can be enumerated by calling the [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function with the **MFT_ENUM_FLAG_LOCALMFT** flag. The MFT can be enumerated from within the same process, but is not visible to other processes.

To unregister the MFT from the current process, call [MFTUnregisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftunregisterlocalbyclsid).

If you need to register an MFT in the Protected Media Path (PMP) process, use the [IMFLocalMFTRegistration](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imflocalmftregistration) interface.

## See also

[MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)