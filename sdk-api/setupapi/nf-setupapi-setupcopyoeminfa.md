# SetupCopyOEMInfA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetupCopyOEMInf** function copies a specified .inf file to the %windir%/Inf directory.

A caller of this function is required have administrative privileges, otherwise the function fails.

## Parameters

### `SourceInfFileName` [in]

Full path to the source .inf file. You should use a null-terminated string. This path should not exceed **MAX_PATH** in size, including the terminating **NULL**.

### `OEMSourceMediaLocation` [in]

Source location information to be stored in the precompiled .inf (.pnf). This location information is specific to the source media type specified. You should use a null-terminated string. This path should not exceed **MAX_PATH** in size, including the terminating **NULL**.

### `OEMSourceMediaType` [in]

Source media type referenced by the location information. This parameter may be one of the following values.

| Value | Meaning |
| --- | --- |
| **SPOST_NONE** | No source media information is stored in the .pnf file. The value of *OEMSourceMediaLocation* is ignored in this case. |
| **SPOST_PATH** | *OEMSourceMediaLocation* contains a path to the source media. For example, if the media is on a floppy, this path might be "A:\". If *OEMSourceMediaLocation* is **NULL**, the path is assumed to be the path where the .inf is located. If the .inf has a corresponding .pnf in that location, the .pnf file's source media information is transferred to the destination .pnf file. |
| **SPOST_URL** | *OEMSourceMediaLocation* contains a universal resource locator (URL) that specifies the Internet location from where the .inf/driver files were retrieved. If *OEMSourceMediaLocation* is **NULL**, it is assumed that the default Code Download Manager location was used. |

### `CopyStyle` [in]

Specifies how the .inf file is copied into the .inf directory. The following flags can be combined.

| Value | Meaning |
| --- | --- |
| **SP_COPY_DELETESOURCE** | Delete source file on successful copy. |
| **SP_COPY_REPLACEONLY** | Copy only if this file already exists in the Inf directory. This flag could be used to update the source location information for an existing .inf. |
| **SP_COPY_NOOVERWRITE** | Copy only if the specified files do not currently exist in the Inf directory. If the .inf does currently exist, this API fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_FILE_EXISTS. In this case, the existing .inf file's filename is placed into the appropriate field in the destination .inf file's information output buffers. |
| **SP_COPY_OEMINF_CATALOG_ONLY** | The specified .inf file's corresponding catalog files is copied to %windir%\Inf. If this flag is specified, the destination filename information is entered upon successful return if the specified .inf file already exists in the Inf directory. |

### `DestinationInfFileName` [out, optional]

Pointer to a buffer to receive the .inf file name assigned to it at the time it was copied to the Inf directory. The buffer, if specified, should typically be **MAX_PATH** in length. If the SP_COPY_NOOVERWRITE flag is specified and the **SetupCopyOEMInf** function fails with a return code of ERROR_FILE_EXISTS, this buffer contains the name of the existing .inf file. If the SP_COPY_OEMINF_CATALOG_ONLY flag is specified, this buffer contains the destination .inf filename if the .inf file is already present in the Inf directory. Otherwise, this buffer is set to the empty string. This parameter can be **NULL**.

### `DestinationInfFileNameSize` [in]

Size of the *DestinationInfFileName* buffer, in characters, or zero if the buffer is not specified. If *DestinationInfFileName* is specified and this buffer size is less than the size required to return the destination .inf filename (including full path), this function fails. In this case [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

### `RequiredSize` [out, optional]

Pointer to a variable that receives the size (in characters) required to store the destination .inf file name including a terminating **NULL**. If the SP_COPY_OEMINF_CATALOG_ONLY flag is specified, this variable receives a string length only if the .inf file already exists in the Inf directory. Otherwise, this variable is set to zero. This parameter can be **NULL**.

### `DestinationInfFileNameComponent` [out, optional]

Pointer to a string that is set upon successful return (or ERROR_FILE_EXISTS) to point to the beginning of the filename component of the path stored in the *DestinationInfFileName* parameter. If the SP_COPY_OEMINF_CATALOG_ONLY flag is specified, the *DestinationInfFileName* parameter may be an empty string. In this case, the character pointer is set to **NULL** upon successful return. This parameter can be **NULL**.

## Return value

This function returns WINSETUPAPI BOOL.

## Remarks

The
**SetupCopyOEMInf** function copies a specified .inf file into the %windir%\Inf directory.
**SetupCopyOEMInf** does not recopy the file if it finds that a binary image of the specified .inf file already exists in the Inf directory with the same name or a name of the form OEM*.inf. When
**SetupCopyOEMInf** copies a file, it renames the copied file to OEM*.inf. Name provided is unique and cannot be predicted.

**SetupCopyOEMInf** uses the following procedure to determine if the .inf file already exists in the Inf directory:

All .inf files with names of the form OEM*.inf are enumerated and any files that have the same file size as the specified .inf file are binary compared.

The Inf directory is searched for the source filename of the .inf file. If an .inf file of the same name exists and is the same size as that of the specified .inf file, the two files are binary compared to determine if they are identical.

If the specified .inf file already exists a further check is performed to determine if the specified .inf file contains a CatalogFile= entry in its [Version] section. If it does, the .inf file's %windir%\Inf primary filename with a ".cat" extension is used to determine if the catalog is already installed. If there is a catalog installed, but it is not the same as the catalog associated with the source .inf, this is not considered to be a match and enumerations continue. It is possible to have multiple identical .inf files with unique catalogs contained in %windir%\Inf directory. If an existing match is not found, the .inf and .cat files are installed under a new and unique name.

OEM .inf files that do not specify a CatalogFile= entry are considered invalid with respect to digital signature verification.

In cases where the .inf file must be copied to the %windir%\Inf directory, any digital signature verification failures are reported.

If the .inf and .cat files already exist, these existing filenames are used and the file replacement behavior is based on the specified CopyStyle flags. Replacement behavior refers only to the source media information stored in the .pnf. Existing .inf, .pnf, and .cat files are not modified.

> [!NOTE]
> The setupapi.h header defines SetupCopyOEMInf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupUninstallOEMInf](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupuninstalloeminfa)