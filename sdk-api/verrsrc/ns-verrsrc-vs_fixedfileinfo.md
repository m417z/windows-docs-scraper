# VS_FIXEDFILEINFO structure

## Description

Contains version information for a file. This information is language and code page independent.

## Members

### `dwSignature`

Type: **DWORD**

Contains the value 0xFEEF04BD. This is used with the
**szKey** member of the [VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo) structure when searching a file for the **VS_FIXEDFILEINFO** structure.

### `dwStrucVersion`

Type: **DWORD**

The binary version number of this structure. The high-order word of this member contains the major version number, and the low-order word contains the minor version number.

### `dwFileVersionMS`

Type: **DWORD**

The most significant 32 bits of the file's binary version number. This member is used with
**dwFileVersionLS** to form a 64-bit value used for numeric comparisons.

### `dwFileVersionLS`

Type: **DWORD**

The least significant 32 bits of the file's binary version number. This member is used with
**dwFileVersionMS** to form a 64-bit value used for numeric comparisons.

### `dwProductVersionMS`

Type: **DWORD**

The most significant 32 bits of the binary version number of the product with which this file was distributed. This member is used with
**dwProductVersionLS** to form a 64-bit value used for numeric comparisons.

### `dwProductVersionLS`

Type: **DWORD**

The least significant 32 bits of the binary version number of the product with which this file was distributed. This member is used with
**dwProductVersionMS** to form a 64-bit value used for numeric comparisons.

### `dwFileFlagsMask`

Type: **DWORD**

Contains a bitmask that specifies the valid bits in
**dwFileFlags**. A bit is valid only if it was defined when the file was created.

### `dwFileFlags`

Type: **DWORD**

Contains a bitmask that specifies the Boolean attributes of the file. This member can include one or more of the following values.

| Value | Meaning |
| --- | --- |
| **VS_FF_DEBUG**<br><br>0x00000001L | The file contains debugging information or is compiled with debugging features enabled. |
| **VS_FF_INFOINFERRED**<br><br>0x00000010L | The file's version structure was created dynamically; therefore, some of the members in this structure may be empty or incorrect. This flag should never be set in a file's [VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo) data. |
| **VS_FF_PATCHED**<br><br>0x00000004L | The file has been modified and is not identical to the original shipping file of the same version number. |
| **VS_FF_PRERELEASE**<br><br>0x00000002L | The file is a development version, not a commercially released product. |
| **VS_FF_PRIVATEBUILD**<br><br>0x00000008L | The file was not built using standard release procedures. If this flag is set, the [StringFileInfo](https://learn.microsoft.com/windows/desktop/menurc/stringfileinfo) structure should contain a PrivateBuild entry. |
| **VS_FF_SPECIALBUILD**<br><br>0x00000020L | The file was built by the original company using standard release procedures but is a variation of the normal file of the same version number. If this flag is set, the [StringFileInfo](https://learn.microsoft.com/windows/desktop/menurc/stringfileinfo) structure should contain a SpecialBuild entry. |

### `dwFileOS`

Type: **DWORD**

The operating system for which this file was designed. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VOS_DOS**<br><br>0x00010000L | The file was designed for MS-DOS. |
| **VOS_NT**<br><br>0x00040000L | The file was designed for Windows NT. |
| **VOS__WINDOWS16**<br><br>0x00000001L | The file was designed for 16-bit Windows. |
| **VOS__WINDOWS32**<br><br>0x00000004L | The file was designed for 32-bit Windows. |
| **VOS_OS216**<br><br>0x00020000L | The file was designed for 16-bit OS/2. |
| **VOS_OS232**<br><br>0x00030000L | The file was designed for 32-bit OS/2. |
| **VOS__PM16**<br><br>0x00000002L | The file was designed for 16-bit Presentation Manager. |
| **VOS__PM32**<br><br>0x00000003L | The file was designed for 32-bit Presentation Manager. |
| **VOS_UNKNOWN**<br><br>0x00000000L | The operating system for which the file was designed is unknown to the system. |

An application can combine these values to indicate that the file was designed for one operating system running on another. The following
**dwFileOS** values are examples of this, but are not a complete list.

| Value | Meaning |
| --- | --- |
| **VOS_DOS_WINDOWS16**<br><br>0x00010001L | The file was designed for 16-bit Windows running on MS-DOS. |
| **VOS_DOS_WINDOWS32**<br><br>0x00010004L | The file was designed for 32-bit Windows running on MS-DOS. |
| **VOS_NT_WINDOWS32**<br><br>0x00040004L | The file was designed for Windows NT. |
| **VOS_OS216_PM16**<br><br>0x00020002L | The file was designed for 16-bit Presentation Manager running on 16-bit OS/2. |
| **VOS_OS232_PM32**<br><br>0x00030003L | The file was designed for 32-bit Presentation Manager running on 32-bit OS/2. |

### `dwFileType`

Type: **DWORD**

The general type of file. This member can be one of the following values. All other values are reserved.

| Value | Meaning |
| --- | --- |
| **VFT_APP**<br><br>0x00000001L | The file contains an application. |
| **VFT_DLL**<br><br>0x00000002L | The file contains a DLL. |
| **VFT_DRV**<br><br>0x00000003L | The file contains a device driver. If **dwFileType** is **VFT_DRV**, **dwFileSubtype** contains a more specific description of the driver. |
| **VFT_FONT**<br><br>0x00000004L | The file contains a font. If **dwFileType** is **VFT_FONT**, **dwFileSubtype** contains a more specific description of the font file. |
| **VFT_STATIC_LIB**<br><br>0x00000007L | The file contains a static-link library. |
| **VFT_UNKNOWN**<br><br>0x00000000L | The file type is unknown to the system. |
| **VFT_VXD**<br><br>0x00000005L | The file contains a virtual device. |

### `dwFileSubtype`

Type: **DWORD**

The function of the file. The possible values depend on the value of
**dwFileType**. For all values of
**dwFileType** not described in the following list,
**dwFileSubtype** is zero.

If
**dwFileType** is **VFT_DRV**,
**dwFileSubtype** can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VFT2_DRV_COMM**<br><br>0x0000000AL | The file contains a communications driver. |
| **VFT2_DRV_DISPLAY**<br><br>0x00000004L | The file contains a display driver. |
| **VFT2_DRV_INSTALLABLE**<br><br>0x00000008L | The file contains an installable driver. |
| **VFT2_DRV_KEYBOARD**<br><br>0x00000002L | The file contains a keyboard driver. |
| **VFT2_DRV_LANGUAGE**<br><br>0x00000003L | The file contains a language driver. |
| **VFT2_DRV_MOUSE**<br><br>0x00000005L | The file contains a mouse driver. |
| **VFT2_DRV_NETWORK**<br><br>0x00000006L | The file contains a network driver. |
| **VFT2_DRV_PRINTER**<br><br>0x00000001L | The file contains a printer driver. |
| **VFT2_DRV_SOUND**<br><br>0x00000009L | The file contains a sound driver. |
| **VFT2_DRV_SYSTEM**<br><br>0x00000007L | The file contains a system driver. |
| **VFT2_DRV_VERSIONED_PRINTER**<br><br>0x0000000CL | The file contains a versioned printer driver. |
| **VFT2_UNKNOWN**<br><br>0x00000000L | The driver type is unknown by the system. |

If
**dwFileType** is **VFT_FONT**,
**dwFileSubtype** can be one of the following values.

| Value | Meaning |
| --- | --- |
| **VFT2_FONT_RASTER**<br><br>0x00000001L | The file contains a raster font. |
| **VFT2_FONT_TRUETYPE**<br><br>0x00000003L | The file contains a TrueType font. |
| **VFT2_FONT_VECTOR**<br><br>0x00000002L | The file contains a vector font. |
| **VFT2_UNKNOWN**<br><br>0x00000000L | The font type is unknown by the system. |

If
**dwFileType** is **VFT_VXD**,
**dwFileSubtype** contains the virtual device identifier included in the virtual device control block.

All
**dwFileSubtype** values not listed here are reserved.

### `dwFileDateMS`

Type: **DWORD**

The most significant 32 bits of the file's 64-bit binary creation date and time stamp.

### `dwFileDateLS`

Type: **DWORD**

The least significant 32 bits of the file's 64-bit binary creation date and time stamp.

## See also

**Conceptual**

**Reference**

[String](https://learn.microsoft.com/windows/desktop/menurc/string-str)

[StringFileInfo](https://learn.microsoft.com/windows/desktop/menurc/stringfileinfo)

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)