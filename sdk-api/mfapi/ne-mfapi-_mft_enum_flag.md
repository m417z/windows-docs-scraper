# _MFT_ENUM_FLAG enumeration

## Description

Contains flags for registering and enumeration Media Foundation transforms (MFTs).

These flags are used in the following functions:

* [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex): These flags control which Media Foundation transforms (MFTs) are enumerated, as well as the enumeration order.
* [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister): A subset of these flags are used when registering an MFT.

## Constants

### `MFT_ENUM_FLAG_SYNCMFT:0x00000001`

The MFT performs synchronous data processing in software.

This flag does not apply to hardware transforms.

### `MFT_ENUM_FLAG_ASYNCMFT:0x00000002`

The MFT performs asynchronous data processing in software. See [Asynchronous MFTs](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-mfts).

This flag does not apply to hardware transforms.

### `MFT_ENUM_FLAG_HARDWARE:0x00000004`

The MFT performs hardware-based data processing, using either the AVStream driver or a GPU-based proxy MFT. MFTs in this category always process data asynchronously. See [Hardware MFTs](https://learn.microsoft.com/windows/desktop/medfound/hardware-mfts).

**Note** This flag applies to video codecs and video processors that perform their work entirely in hardware. It does not apply to software decoders that use DirectX Video Acceleration to assist decoding.

### `MFT_ENUM_FLAG_FIELDOFUSE:0x00000008`

The MFT that must be unlocked by the application before use. Unlocking is performed using the [IMFFieldOfUseMFTUnlock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffieldofusemftunlock) interface. For more information, see [Field of Use Restrictions](https://learn.microsoft.com/windows/desktop/medfound/field-of-use-restrictions).

This flag does not apply to hardware transforms.

### `MFT_ENUM_FLAG_LOCALMFT:0x00000010`

For enumeration, include MFTs that were registered in the caller's process. To register an MFT in the caller's process, call the either the [MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal) or [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid) function.

This flag does not apply to hardware transforms.

Do not set this flag in the [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) function.

### `MFT_ENUM_FLAG_TRANSCODE_ONLY:0x00000020`

The MFT is optimized for transcoding rather than playback.

### `MFT_ENUM_FLAG_SORTANDFILTER:0x00000040`

For enumeration, sort and filter the results. For more information, see the Remarks section of [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex).

Do not set this flag in the [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) function.

### `MFT_ENUM_FLAG_SORTANDFILTER_APPROVED_ONLY:0x000000C0`

### `MFT_ENUM_FLAG_SORTANDFILTER_WEB_ONLY:0x00000140`

### `MFT_ENUM_FLAG_SORTANDFILTER_WEB_ONLY_EDGEMODE:0x00000240`

### `MFT_ENUM_FLAG_UNTRUSTED_STOREMFT:0x00000400`

### `MFT_ENUM_FLAG_ALL:0x0000003F`

Bitwise **OR** of all the flags, excluding **MFT_ENUM_FLAG_SORTANDFILTER**.

Do not set this flag in the [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) function.

## Remarks

For registration, these flags describe the MFT that is being registered. Some flags do not apply in that context. For enumeration, these flags control which MFTs are selected in the enumeration. For more details about the precise meaning of these flags, see the reference topics for [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) and [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex)

For registration, the **MFT_ENUM_FLAG_SYNCMFT**, **MFT_ENUM_FLAG_ASYNCMFT**, and **MFT_ENUM_FLAG_HARDWARE** flags are mutually exclusive. For enumeration, these three flags can be combined.

## See also

[Field of Use Restrictions](https://learn.microsoft.com/windows/desktop/medfound/field-of-use-restrictions)

[MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex)

[MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)