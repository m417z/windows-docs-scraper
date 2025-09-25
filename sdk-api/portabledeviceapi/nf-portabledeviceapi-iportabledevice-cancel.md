# IPortableDevice::Cancel

## Description

The **Cancel** method cancels a pending operation on this interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was canceled successfully. |

## Remarks

If your application invokes the WPD API from multiple threads, each thread should create a new instance of the [IPortableDevice](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice) interface. Doing this ensures that any cancel operation affects only the I/O for the affected thread.

If an **IStream** write operation is underway when the **Cancel** method is invoked, your application should discard all changes by invoking the **IStream::Revert** method. Once the changes are discarded, the application should also close the stream by invoking the **IUnknown::Release** method.

Also, note that if the **Cancel** method is invoked before an **IStream::Write** method has completed, the data being written may be corrupted.

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)