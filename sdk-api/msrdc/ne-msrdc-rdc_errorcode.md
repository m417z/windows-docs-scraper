# RDC_ErrorCode enumeration

## Description

The
**RDC_ErrorCode** enumeration type
defines the set of RDC-specific error codes.

## Constants

### `RDC_NoError:0`

The operation was completed successfully.

### `RDC_HeaderVersionNewer`

The data header is incompatible with this library.

### `RDC_HeaderVersionOlder`

The data header is incompatible with this library.

### `RDC_HeaderMissingOrCorrupt`

The data header is missing or corrupt.

### `RDC_HeaderWrongType`

The data header format is incorrect.

### `RDC_DataMissingOrCorrupt`

The end of data was reached before all data expected was read.

### `RDC_DataTooManyRecords`

Additional data was found past where the end of data was expected.

### `RDC_FileChecksumMismatch`

The final file checksum doesn't match.

### `RDC_ApplicationError`

An application callback function returned failure.

### `RDC_Aborted`

The operation was aborted.

### `RDC_Win32Error`

The failure of the function is not RDC-specific and the **HRESULT** returned by
the function contains the specific error code.

## See also

[Remote Differential Compression Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/rdc/remote-differential-compression-enumerations)