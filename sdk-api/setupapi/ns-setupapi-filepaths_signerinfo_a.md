# FILEPATHS_SIGNERINFO_A structure

## Description

The **FILEPATHS_SINGNERINFO** structure stores source and target path information, and also file signature information. The setup functions send
**FILEPATHS_SIGNERINFO** as a parameter in several of the notifications sent to callback routines. For more information, see
[Notifications](https://learn.microsoft.com/windows/desktop/SetupApi/notifications).

## Members

### `Target`

Path to the target file.

### `Source`

Path to the source file. This member is not used when the
[FILEPATHS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-filepaths_a) structure is used with a file delete operation.

### `Win32Error`

If an error occurs, this member is the [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If no error has occurred, it is NO_ERROR.

### `Flags`

Additional information that depends on the notification sent with the
**FILEPATHS_SIGNERINFO** structure.

For
[SPFILENOTIFY_COPYERROR](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-copyerror) notifications, **Flags** specifies dialog box behavior and can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SP_COPY_NOBROWSE** | Do not offer the user the option to browse. |
| **SP_COPY_NOSKIP** | Do not offer the user the option to skip the file. |
| **SP_COPY_WARNIFSKIP** | Inform the user that skipping the file may affect the installation. |

For
[SPFILENOTIFY_FILEOPDELAYED](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-fileopdelayed) notifications, **Flags** specifies the type of file operation delayed and can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FILEOP_COPY** | A file copy operation was delayed. |
| **FILEOP_DELETE** | A file delete operation was delayed. |

### `DigitalSigner`

Digital signer of the file.

### `Version`

Version of the file.

### `CatalogFile`

Catalog file.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines FILEPATHS_SIGNERINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).