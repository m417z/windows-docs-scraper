# NdisOpenFile function

## Description

The
**NdisOpenFile** function returns a handle for an opened file.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of the open file
operation, which can be one of the following:

#### NDIS_STATUS_SUCCESS

The handle at
*FileHandle* is valid for a subsequent call to
**NdisMapFile**.

#### NDIS_STATUS_FILE_NOT_FOUND

The given string at
*FileName* did not specify a name found in the system object namespace.

#### NDIS_STATUS_RESOURCES

NDIS could not allocate the resources it needed to open the file and allocate a buffer for the
file contents.

#### NDIS_STATUS_ERROR_READING_FILE

The specified file's data could not be read into system memory for subsequent access by the
caller.

### `FileHandle` [out]

A pointer to a caller-supplied variable in which this function returns the handle of the opened
file if the call succeeds.

### `FileLength` [out]

A pointer to a caller-supplied variable in which this function writes the number of bytes of data
in the opened file if the call succeeds.

### `FileName` [in]

A pointer to an NDIS_STRING type containing an initialized counted string, in the system-default
character set, naming the file to be opened. For Windows 2000 and later drivers, this string contains
Unicode characters. That is, for Windows 2000 and later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `HighestAcceptableAddress` [in]

The highest physical address in which the file data can be stored, or specifies -1 if the driver
places no restrictions.

## Remarks

**NdisOpenFile** opens a disk file, typically a file the driver will later download to program an
intelligent NIC.
**NdisOpenFile** also allocates storage to hold file contents for the driver's subsequent call to the
[NdisMapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismapfile) function.

A miniport driver should call
**NdisOpenFile** only from the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

When
**NdisOpenFile** returns, the miniport driver can access file data by calling
**NdisMapFile**. It can call the
[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile) function to page out the file
so it does not consume resources unnecessarily while the driver is not accessing the file data. When
finished using the file,
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) must call the
[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile) function.

> [!NOTE]
>  **NdisOpenFile**, **NdisCloseFile**, **NdisMapFile** and **NdisUnmapFile** are not supported on ARM64. On ARM64, replace these functions with calls to **ZwCreateFile**, **ZwReadFile**, or other similar operations.
>

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCloseFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclosefile)

[NdisMapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismapfile)

[NdisUnmapFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunmapfile)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)