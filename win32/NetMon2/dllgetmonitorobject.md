# DllGetMonitorObject callback function

The **DllGetMonitorObject** function must be implemented by the monitor. The MCSVC calls this function to create an instance of the monitor.

## Parameters

*riid* \[in\]

UUID of monitors, shown below, as defined in the IMonitor.h header file. If an invalid UUID is provided, the function fails, and the monitor must return E\_NOINTERFACE.

``` syntax
IID_IMonitor
```

*ppObj* \[out\]

Pointer to a pointer that receives the interface requested in *riid*.

## Return value

If the function is successful, the return value is S\_OK (which is the same as NOERROR).

If the function is unsuccessful, the return value is a failure code. When a failure code is returned, the MCSVC does not create the monitor object, and the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method is not called on the interface pointer.

## Remarks

The **DllGetMonitorObject** function is called each time the MCSVC tries to create an instance of the monitor. This function intentionally bears a strong resemblance to the more common [**DllGetClassObject**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-dllgetclassobject) function. The main difference is that a CLSID is not passed in to **DllGetMonitorObject**.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

