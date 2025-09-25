# CSC_ThreadPool enumeration

## Description

Indicates the thread pool in which the work runs that is submitted through the activity returned from [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity).

## Constants

### `CSC_ThreadPoolNone:0`

No thread pool is used. If this value is used to configure a [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object that is passed to [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity), an error (CO_E_THREADPOOL_CONFIG) is returned. This is the default thread pool setting for **CServiceConfig** when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_ThreadPoolInherit`

The same type of thread pool apartment as the caller's thread apartment is used. If the caller's thread apartment is the neutral apartment, a single-threaded apartment is used. This is the default thread pool setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

### `CSC_STAThreadPool`

A single-threaded apartment (STA) is used.

### `CSC_MTAThreadPool`

A multithreaded apartment (MTA) is used.

## Remarks

This enumeration is used to set the thread pool for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) only when calling [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity). An error is returned if you try to set the thread pool when calling [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain).

## See also

[COM+ Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--threading-models)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[IServiceThreadPoolConfig::SelectThreadPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicethreadpoolconfig-selectthreadpool)