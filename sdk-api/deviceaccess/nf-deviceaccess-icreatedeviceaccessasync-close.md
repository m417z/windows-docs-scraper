# ICreateDeviceAccessAsync::Close

## Description

The **Close** method performs cleanup after the asynchronous operation is completed and you retrieve the results.

## Return value

This method supports standard return values, in addition to these:

| Return code | Description |
| --- | --- |
| **S_OK** | The property value was retrieved successfully. |
| **E_ILLEGAL_METHOD_CALL** | The operation did not finish. |

## Remarks

If the binding is successful, it doesn't invalidate the interface that the [GetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-icreatedeviceaccessasync-getresult) method returns.

It isn't strictly necessary to call this method, because resources are cleaned up when the underlying object is deleted. But doing so allows the system to free up resources that are associated with the asynchronous binding. As such, it's good practice to call **Close** after you retrieve the results.

## See also

[ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync)