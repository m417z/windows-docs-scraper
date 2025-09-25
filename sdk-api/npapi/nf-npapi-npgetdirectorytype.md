# NPGetDirectoryType function

## Description

Determines the type of a network directory. The **NPGetDirectoryType** function is used by File Manager.

## Parameters

### `lpName` [in]

Pointer to the fully qualified name of the directory. The network provider returns the type to the address pointed to by *lpType*. If the value returned in *lpType* is zero or if the network provider returns an error, File Manager displays the directory as a "normal" directory.

### `lpType` [in]

Pointer to a value defined by the network provider. This value is used to modify the display of the drive tree in File Manager. In this way, the network provider can show special directories to the user.

### `bFlushCache` [in]

Set to **TRUE** when File Manager calls MPR to get the directory type for the first time while repainting a window on Refresh. Subsequently, it will be **FALSE**. This gives a provider the opportunity to optimize performance if it wants to just read the data for a drive once and then cache it until the next Refresh.

## Return value

This function should return WN_SUCCESS if it is successful. Otherwise, it should return an error code, which may include the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | [NPGetDirectoryType](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetdirectorytype) is not supported. |

## Remarks

File Manager will supply its own icon for all special network directories; that is, when *lpType* is set to a nonzero value, File Manager will display a special folder icon.

The implementation of this function should be high-performance, or fast, since the call occurs while File Manager is painting the directory tree.