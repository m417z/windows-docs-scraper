# MFTRegisterLocal function

## Description

Registers a Media Foundation transform (MFT) in the caller's process.

## Parameters

### `pClassFactory` [in]

A pointer to the **IClassFactory** interface of a class factory object. The class factory creates the MFT.

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

The *pClassFactory* parameter specifies a class factory object that creates the MFT. The class factory's **IClassFactory::CreateInstance** method must return an object that supports the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface.

**Note** The [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function retrieves a list of [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointers. However, the class factory does not need to support the **IMFActivate** interface. Instead, the **MFTEnumEx** function provides an implementation of **IMFActivate** that wraps the class factory.

To unregister the MFT from the current process, call [MFTUnregisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftunregisterlocal).

If you need to register an MFT in the Protected Media Path (PMP) process, use the [IMFLocalMFTRegistration](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imflocalmftregistration) interface.

## See also

[MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)