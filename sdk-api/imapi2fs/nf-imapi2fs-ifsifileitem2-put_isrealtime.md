# IFsiFileItem2::put_IsRealTime

## Description

Sets the 'Real-Time' attribute of a file in a file system. This attribute specifies whether or not the content requires a minimum data-transfer rate when writing or reading, for example, audio and video data.

## Parameters

### `newVal` [in]

Specify **VARIANT_TRUE** to set the Real-Time attribute of a file in the file system image; otherwise, **VARIANT_FALSE**. The default is **VARIANT_FALSE**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED**<br><br>Value: 0x00AAB15FL | Feature is not supported for the current file system revision, and as a result, the file has been marked as Real-Time but will not appear as such in the resultant file system image unless UDF revision 2.01 or higher is enabled in the file system object. |
| **IMAPI_E_PROPERTY_NOT_ACCESSIBLE**<br><br>Value: 0xC0AAB160L | Property '*%1!ls!*' is not accessible. |
| **IMAPI_E_INVALID_PARAM**<br><br>Value: 0xC0AAB101 | The value specified for parameter '*%1!ls!*' is invalid. |

**Note** Currently, S_OK is returned when using this method to set a Real-Time attribute value of a file that is 'Read Only' as a result of a successful [CreateResultImage](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifilesystemimage-createresultimage) operation.

## Remarks

The [IFsiDirectoryItem::AddTree](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem-addtree) and [IFsiDirectoryItem2::AddTreeWithNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsidirectoryitem2-addtreewithnamedstreams) methods do not set the Real-Time attribute while adding files to a file system image. To mark files as Real-time files, they must be enumerated after they have been added to the file system image and have the Real-Time attribute set individually.

If this method is invoked for a file item representing a named stream, this method returns error code **IMAPI_E_PROPERTY_NOT_ACCESSIBLE** as
named streams do not have the Real-Time attribute.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2)