# SOURCE_MEDIA_A structure

## Description

The
**SOURCE_MEDIA** structure is used with the
[SPFILENOTIFY_NEEDMEDIA](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-needmedia) notification to pass source media information.

## Members

### `Reserved`

This member is not currently used.

### `Tagfile`

Optional tag file that can be used to identify the source media.

### `Description`

Human-readable description of the source media.

### `SourcePath`

Path to the source that needs the new media.

### `SourceFile`

Source file to be retrieved from the new media.

### `Flags`

Copy style information that modifies how errors are handled. This member can be one or more of the following values.

#### SP_COPY_WARNIFSKIP

Inform the user that skipping the file may affect the installation.

#### SP_COPY_NOSKIP

Do not offer the user the option to skip the file.

#### SP_FLAG_CABINETCONTINUATION

The current source file is continued in another cabinet file.

#### SP_COPY_NOBROWSE

Do not offer the user the option to browse.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SPFILENOTIFY_NEEDMEDIA](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-needmedia)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines SOURCE_MEDIA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).