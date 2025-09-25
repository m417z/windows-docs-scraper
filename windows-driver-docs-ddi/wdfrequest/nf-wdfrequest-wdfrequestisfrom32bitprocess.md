# WdfRequestIsFrom32BitProcess function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestIsFrom32BitProcess** method checks whether the originator of a specified I/O request is a 32-bit user-mode application.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

On 64-bit systems,**WdfRequestIsFrom32BitProcess** returns **TRUE** if the originator of the current I/O request is a 32-bit user-mode process, and **FALSE** otherwise. On 32-bit systems, **WdfRequestIsFrom32BitProcess** always returns **TRUE**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers can call **WdfRequestIsFrom32BitProcess** to determine whether an I/O request is likely to contain data elements that need to be converted, or "thunked," before they can be used in a 64-bit driver.

The specified request handle must have been obtained from one of the driver's I/O queues and not from a call to [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate).

#### Examples

The following code example determines if an I/O request came from a 32-bit application.

```cpp
VOID
MyEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
...
    if (WdfRequestIsFrom32BitProcess(Request)) {
        //
        // The driver is running on a 64-bit computer and the
        // I/O request came from a 32-bit application.
        //
...
    }
...
}
```

## See also

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)