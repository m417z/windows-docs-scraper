# MFTRegister function

## Description

Adds information about a Media Foundation transform (MFT) to the registry.

Applications can enumerate the MFT by calling the [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum) or [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function.

## Parameters

### `clsidMFT` [in]

The CLSID of the MFT.
The MFT must also be registered as a COM object using the same CLSID.

### `guidCategory` [in]

GUID that specifies the category of the MFT. For a list of MFT categories, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `pszName` [in]

Wide-character string that contains the friendly name of the MFT.

### `Flags` [in]

Bitwise **OR** of zero or more of the following flags from the [_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag) enumeration:

| Value | Meaning |
| --- | --- |
| **MFT_ENUM_FLAG_ASYNCMFT** | The MFT performs asynchronous processing in software. See [Asynchronous MFTs](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-mfts). This flag does not apply to hardware transforms.<br><br>Requires Windows 7. |
| **MFT_ENUM_FLAG_FIELDOFUSE** | The application must unlock the MFT in order to use it. See [IMFFieldOfUseMFTUnlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffieldofusemftunlock).<br><br>Requires Windows 7. |
| **MFT_ENUM_FLAG_HARDWARE** | The MFT performs hardware-based data processing, using either the AVStream driver or a GPU-based proxy MFT. MFTs in this category always process data asynchronously. See [Hardware MFTs](https://learn.microsoft.com/windows/desktop/medfound/hardware-mfts).<br><br>**Note** This flag applies to video codecs and video processors that perform their work entirely in hardware. It does not apply to software decoders that use DirectX Video Acceleration to assist decoding.<br><br>Requires Windows 7. |
| **MFT_ENUM_FLAG_SYNCMFT** | The MFT performs synchronous processing in software. This flag does not apply to hardware transforms. |
| **MFT_ENUM_FLAG_TRANSCODE_ONLY** | The MFT is optimized for transcoding and should not be used for playback.<br><br>Requires Windows 7. |

Setting *Flags* to zero is equivalent to setting the **MFT_ENUM_FLAG_SYNCMFT** flag. The default processing model for MFTs is synchronous processing.

Prior to Windows 7, the *Flags* parameter was reserved.

### `cInputTypes` [in]

Number of elements in the *pInputTypes* array.

### `pInputTypes` [in]

Pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array specifies an input format that the MFT supports. This parameter can be **NULL**.

This parameter can be **NULL**. However, if the parameter is **NULL**, the MFT will be enumerated only when an application specifies **NULL** for the desired input type.

### `cOutputTypes` [in]

Number of elements in the *pOutputTypes* array.

### `pOutputTypes` [in]

Pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array defines an output format that the MFT supports.

This parameter can be **NULL**. However, if the parameter is **NULL**, the MFT will be enumerated only when an application specifies **NULL** for the desired output type.

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store that contains additional registry information. This parameter can be **NULL**. If the parameter is non-**NULL**, the attributes are written to the registry as a byte array.
You can use the [MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo) function to retrieve the attributes.

The following attribute is defined for this parameter:

| Value | Meaning |
| --- | --- |
| **[MFT_CODEC_MERIT_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-codec-merit-attribute)** | Contains the merit value of a hardware codec. See [Codec Merit](https://learn.microsoft.com/windows/desktop/medfound/codec-merit). |

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The registry entries created by this function are read by the following functions:

| Function | Description |
| --- | --- |
| [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum) | Enumerates MFTs by media type and category. |
| [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) | Extended version of [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum). |
| [MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo) | Looks up an MFT by CLSID and retrieves the registry information. |

This function does not register the CLSID of the MFT for the **CoCreateInstance** or **CoGetClassObject** functions.

To remove the entries from the registry, call [MFTUnregister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftunregister).
If you remove an MFT from the system, you should always call **MFTUnregister**.

The formats given in the *pInputTypes* and *pOutputTypes* parameters are intended to help applications search for MFTs by format. Applications can use the [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum) or [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) functions to enumerate MFTs that match a particular set of formats.

It is recommended
to specify at least one input type in *pInputTypes* and one output type in the *pOutputTypes* parameter. Otherwise, the MFT might be skipped in the enumeration.

On 64-bit Windows, the 32-bit version of this function registers the MFT in the 32-bit node of the registry. For more information, see [32-bit and 64-bit Application Data in the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/32-bit-and-64-bit-application-data-in-the-registry).

## See also

[MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)

[_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag)