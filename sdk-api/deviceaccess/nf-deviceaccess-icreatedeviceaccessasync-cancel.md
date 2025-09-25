# ICreateDeviceAccessAsync::Cancel

## Description

The **Cancel** method attempts to cancel an asynchronous operation that is in progress.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the operation is successfully canceled, a call to the [GetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nf-deviceaccess-icreatedeviceaccessasync-getresult) method occurs.

Your application can call **Cancel** at any time. If the operation is already closed or completed, it has no effect.

## See also

[ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync)