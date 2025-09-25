# MINIDUMP_HEADER structure

## Description

Contains header information for the minidump file.

## Members

### `Signature`

The signature. Set this member to MINIDUMP_SIGNATURE.

### `Version`

The version of the minidump format. The low-order word is MINIDUMP_VERSION. The high-order word is an internal value that is implementation specific.

### `NumberOfStreams`

The number of streams in the minidump directory.

### `StreamDirectoryRva`

The base RVA of the minidump directory. The directory is an array of
[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory) structures.

### `CheckSum`

The checksum for the minidump file. This member can be zero.

### `Reserved`

This member is reserved.

### `TimeDateStamp`

Time and date, in **time_t** format.

### `Flags`

One or more values from the
[MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type) enumeration type.

## See also

[MINIDUMP_DIRECTORY](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_directory)

[MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type)