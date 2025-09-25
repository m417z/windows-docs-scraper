# IApiTracingDataCollector::put_IncludeModules

## Description

Retrieves or sets the list of modules to include in the trace.

This property is read/write.

## Parameters

## Remarks

If you do not set this property, the trace will include the following modules:

* Advapi32.dll
* Gdi32.dll
* Kernel32.dll
* User32.dll

This property limits the trace to a subset of those DLLs. For example, you can use this property to limit the trace to only Kernel32.dll and Advapi32.dll.

## See also

[IApiTracingDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-iapitracingdatacollector)

[IApiTracingDataCollector::ExePath](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iapitracingdatacollector-get_exepath)