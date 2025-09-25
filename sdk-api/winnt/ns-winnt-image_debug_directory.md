# IMAGE_DEBUG_DIRECTORY structure

## Description

Represents the debug directory format.

## Members

### `Characteristics`

Reserved.

### `TimeDateStamp`

The time and date the debugging information was created.

### `MajorVersion`

The major version number of the debugging information format.

### `MinorVersion`

The minor version number of the debugging information format.

### `Type`

The format of debugging information. This field enables support of multiple debuggers. For more information, see [Debug Type](https://learn.microsoft.com/windows/win32/debug/pe-format#debug-type) in PE Format specification.

### `SizeOfData`

The size of the debugging information, in bytes. This value does not include the debug directory itself.

### `AddressOfRawData`

The address of the debugging information when the image is loaded, relative to the image base.

### `PointerToRawData`

A file pointer to the debugging information.

## See also

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)