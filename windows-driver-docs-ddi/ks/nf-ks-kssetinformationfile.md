# KsSetInformationFile function

## Description

The **KsSetInformationFile** function performs an information set against the specified file object. The function attempts to use **FastIoDispatch** if possible, or it generates an information set against the device object.

## Parameters

### `FileObject` [in]

Specifies the file object to set the standard information on.

### `FileInformation` [in]

Indicates the place in which to put the file information. The file information is assumed to be a valid or probed address.

### `Length` [in]

Specifies the correct length of the *FileInformation* buffer.

### `FileInformationClass` [in]

Specifies the class of information being set.

## Return value

The **KsSetInformationFile** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns a set error.

## Remarks

The **KsSetInformationFile** function should be used only when the set would result in an actual request to the underlying driver, not including complex operations that require additional parameters to be sent to the driver such as rename, deletion, and completion. For example, **FilePositionInformation** would not generate such a request and should not be used. It assumes the caller is serializing access to the file for operations against a FO_SYNCHRONOUS_IO file object.