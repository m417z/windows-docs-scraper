# AVIFileOpen function

## Description

The **AVIFileOpen** function opens an AVI file and returns the address of a file interface used to access it. The AVIFile library maintains a count of the number of times a file is opened, but not the number of times it was released. Use the [AVIFileRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilerelease) function to release the file and decrement the count.

## Parameters

### `ppfile`

Pointer to a buffer that receives the new [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface pointer.

### `szFile`

Null-terminated string containing the name of the file to open.

### `uMode`

Access mode to use when opening the file. The default access mode is OF_READ. The following access modes can be specified with **AVIFileOpen**.

| Value | Meaning |
| --- | --- |
| OF_CREATE | Creates a new file. If the file already exists, it is truncated to zero length. |
| OF_PARSE | Skips time-consuming operations, such as building an index. Set this flag if you want the function to return as quickly as possible—for example, if you are going to query the file properties but not read the file. |
| OF_READ | Opens the file for reading. |
| OF_READWRITE | Opens the file for reading and writing. |
| OF_SHARE_DENY_NONE | Opens the file nonexclusively. Other processes can open the file with read or write access. **AVIFileOpen** fails if another process has opened the file in compatibility mode. |
| OF_SHARE_DENY_READ | Opens the file nonexclusively. Other processes can open the file with write access. **AVIFileOpen** fails if another process has opened the file in compatibility mode or has read access to it. |
| OF_SHARE_DENY_WRITE | Opens the file nonexclusively. Other processes can open the file with read access. **AVIFileOpen** fails if another process has opened the file in compatibility mode or has write access to it. |
| OF_SHARE_EXCLUSIVE | Opens the file and denies other processes any access to it. **AVIFileOpen** fails if any other process has opened the file. |
| OF_WRITE | Opens the file for writing. |

### `lpHandler`

Pointer to a class identifier of the standard or custom handler you want to use. If the value is **NULL**, the system chooses a handler from the registry based on the file extension or the RIFF type specified in the file.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **AVIERR_BADFORMAT** | The file couldn't be read, indicating a corrupt file or an unrecognized format. |
| **AVIERR_MEMORY** | The file could not be opened because of insufficient memory. |
| **AVIERR_FILEREAD** | A disk error occurred while reading the file. |
| **AVIERR_FILEOPEN** | A disk error occurred while opening the file. |
| **REGDB_E_CLASSNOTREG** | According to the registry, the type of file specified in **AVIFileOpen** does not have a handler to process it. |

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFileRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilerelease)