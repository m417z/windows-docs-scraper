# FILE_IN_CABINET_INFO_A structure

## Description

The
**FILE_IN_CABINET_INFO** structure provides information about a file found in the cabinet. The
[SetupIterateCabinet](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupiteratecabineta) function sends this structure as one of the parameters when it sends a
[SPFILENOTIFY_FILEINCABINET](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-fileincabinet) notification to the cabinet callback routine.

## Members

### `NameInCabinet`

File name as it exists within the cabinet file.

### `FileSize`

Uncompressed size of the file in the cabinet, in bytes.

### `Win32Error`

If an error occurs, this member is the [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If no error has occurred, it is NO_ERROR.

### `DosDate`

Date that the file was last saved.

### `DosTime`

MS-DOS time stamp of the file in the cabinet.

### `DosAttribs`

Attributes of the file in the cabinet.

### `FullTargetName`

Target path and file name.

## See also

[CABINET_INFO](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-cabinet_info_a)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines FILE_IN_CABINET_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).