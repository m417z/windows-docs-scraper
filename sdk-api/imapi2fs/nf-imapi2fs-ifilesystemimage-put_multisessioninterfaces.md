# IFileSystemImage::put_MultisessionInterfaces

## Description

Sets the list of multi-session interfaces for the optical media.

## Parameters

### `newVal` [in]

List of multi-session interfaces for the optical media. Each element of the list is a VARIANT whose type is **VT_DISPATCH**. Query the multi-session interface for its **IDispatch** interface and set the **pdispVal** member of the variant to the **IDispatch** interface.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INCOMPATIBLE_MULTISESSION_TYPE** | IMAPI does not support the multisession type requested.<br><br>Value: 0xC0AAB15B |
| **IMAPI_E_IMPORT_MEDIA_NOT_ALLOWED** | IMAPI does not allow multi-session with the current media type.<br><br>Value: 0xC0AAB159 |
| **IMAPI_E_NO_COMPATIBLE_MULTISESSION_TYPE** | IMAPI supports none of the multisession type(s) provided on the current media.<br><br>Value: 0xC0AAB15C |
| **IMAPI_E_BAD_MULTISESSION_PARAMETER** | One of multisession parameters cannot be retrieved or has a wrong value.<br><br>Value: 0xC0AAB162 |
| **IMAPI_E_FSI_INTERNAL_ERROR** | Internal error occurred: %1!ls!.<br><br>Value: 0xC0AAB100 |
| **IMAPI_E_IMPORT_SEEK_FAILURE** | Cannot seek to block %1!I64d! on source disc. This value is also returned if the optical media is blank.<br><br>Value: 0xC0AAB156 |

**Note** Values returned by the IUnknown::QueryInterface method may also be returned here.

## Remarks

This method validates that the multi-session type is compatible. The method succeeds if either

* The list contains a single derived [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interface with [IMultisession::put_InUse](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-imultisession-put_inuse) set to VARIANT_TRUE and if the multi-session type is supported on the current media and supported by the [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) implementation.
* The list contains no derived [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interfaces whose [IMultisession::put_InUse](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-imultisession-put_inuse) property is set to VARIANT_TRUE, but contains at least one derived **IMultisession** that is supported on current media and supported by the [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) implementation.

Unless the media is overwritable (i.e. DVD+/-RW, BD-RE, etc..), this method will fail if the media is blank. Failure will also occur if the list contains more than one [IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession) interface whose [IMultisession::put_InUse](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-imultisession-put_inuse) property is set to VARIANT_TRUE, or no derived **IMultisession** interface is supported by the [IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage) implementation. Currently, only the [IMultisessionSequential](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisessionsequential) interface which derives from **IMultisession** is supported by **IFileSystemImage** implementation.

For an example, see [Creating a Multisession Disc](https://learn.microsoft.com/windows/desktop/imapi/creating-a-multisession-disc).

## See also

[IDiscFormat2Data::get_MultisessionInterfaces](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_multisessioninterfaces)

[IFileSystemImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimage)

[IFileSystemImage::get_MultisessionInterfaces](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-get_multisessioninterfaces)

[IMultisession](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-imultisession)