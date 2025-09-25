# KsQueryInformationFile function

## Description

The **KsQueryInformationFile** function performs an information query against the specified file object. The function attempts to use **FastIoDispatch** if possible, or it generates an information request against the device object*.*

## Parameters

### `FileObject` [in]

Specifies the file object from which to query the standard information.

### `FileInformation` [out]

Indicates the place in which to put the file information. This is assumed to be a valid or probed address.

### `Length` [in]

Specifies the correct length of the *FileInformation* buffer.

### `FileInformationClass` [in]

Specifies the class of information being requested.

## Return value

The **KsQueryInformationFile** function returns STATUS_SUCCESS if successful, or if unsuccessful it returns a query error.

## Remarks

The **KsQueryInformationFile** function should only be used in cases where the query would result in an actual request to the underlying driver. For example, **FilePositionInformation** would not generate such a request and should not be used. It assumes the caller is serializing access to the file for operations against a FO_SYNCHRONOUS_IO file object.