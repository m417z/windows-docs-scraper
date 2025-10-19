# Status enumeration

## Description

The **Status** enumeration indicates the result of a Windows GDI+ method call.

## Constants

### `Ok:0`

Indicates that the method call was successful.

### `GenericError:1`

Indicates that there was an error on the method call, which is identified as something other than those defined by the other elements of this enumeration.

### `InvalidParameter:2`

Indicates that one of the arguments passed to the method was not valid.

### `OutOfMemory:3`

Indicates that the operating system is out of memory and could not allocate memory to process the method call. For an explanation of how constructors use the [OutOfMemory](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) status, see the Remarks section at the end of this topic.

### `ObjectBusy:4`

Indicates that one of the arguments specified in the API call is already in use in another thread.

### `InsufficientBuffer:5`

Indicates that a buffer specified as an argument in the API call is not large enough to hold the data to be received.

### `NotImplemented:6`

Indicates that the method is not implemented.

### `Win32Error:7`

Indicates that the method generated a Win32 error.

### `WrongState:8`

Indicates that the object is in an invalid state to satisfy the API call. For example, calling
[Pen::GetColor](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcolor) from a pen that is not a single, solid color results in a [WrongState](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) status.

### `Aborted:9`

Indicates that the method was aborted.

### `FileNotFound:10`

Indicates that the specified image file or metafile cannot be found.

### `ValueOverflow:11`

Indicates that the method performed an arithmetic operation that produced a numeric overflow.

### `AccessDenied:12`

Indicates that a write operation is not allowed on the specified file.

### `UnknownImageFormat:13`

Indicates that the specified image file format is not known.

### `FontFamilyNotFound:14`

Indicates that the specified font family cannot be found. Either the font family name is incorrect or the font family is not installed.

### `FontStyleNotFound:15`

Indicates that the specified style is not available for the specified font family.

### `NotTrueTypeFont:16`

Indicates that the font retrieved from an
**HDC** or
**LOGFONT** is not a TrueType font and cannot be used with GDI+.

### `UnsupportedGdiplusVersion:17`

Indicates that the version of GDI+ that is installed on the system is incompatible with the version with which the application was compiled.

### `GdiplusNotInitialized:18`

Indicates that the GDI+API is not in an initialized state. To function, all GDI+ objects require that GDI+ be in an initialized state. Initialize GDI+ by calling
[GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup).

### `PropertyNotFound:19`

Indicates that the specified property does not exist in the image.

### `PropertyNotSupported:20`

Indicates that the specified property is not supported by the format of the image and, therefore, cannot be set.

### `ProfileNotFound:21`

Indicates that the color profile required to save an image in CMYK format was not found.

## Remarks

If you construct a GDI+ object and then immediately call the
**GetLastStatus** method of that object, you can determine whether the constructor succeeded or failed. In such cases,
**GetLastStatus** might return **OutOfMemory** even though there was plenty of memory available to create the object. Several GDI+ constructors set the status to **OutOfMemory** when they fail regardless of the reason for failure.