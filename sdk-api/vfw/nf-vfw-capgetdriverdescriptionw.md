# capGetDriverDescriptionW function

## Description

The **capGetDriverDescription** function retrieves the version description of the capture driver.

## Parameters

### `wDriverIndex`

Index of the capture driver. The index can range from 0 through 9.

Plug-and-Play capture drivers are enumerated first, followed by capture drivers listed in the registry, which are then followed by capture drivers listed in SYSTEM.INI.

### `lpszName`

Pointer to a buffer containing a null-terminated string corresponding to the capture driver name.

### `cbName`

Length, in bytes, of the buffer pointed to by *lpszName*.

### `lpszVer`

Pointer to a buffer containing a null-terminated string corresponding to the description of the capture driver.

### `cbVer`

Length, in bytes, of the buffer pointed to by *lpszVer*.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

If the information description is longer than its buffer, the description is truncated. The returned string is always null-terminated. If a buffer size is zero, its corresponding description is not copied.

> [!NOTE]
> The vfw.h header defines capGetDriverDescription as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)