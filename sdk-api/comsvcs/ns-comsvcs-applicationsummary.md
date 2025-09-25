# ApplicationSummary structure

## Description

Represents a COM+ application hosted in a particular process. It can also represent a pseudo-application entry for all Services Without Components (SWC) contexts in the process.

## Members

### `ApplicationInstanceId`

The application instance GUID that uniquely identifies the process hosting the COM+ application.

### `PartitionId`

The partition ID of the COM+ application.

### `ApplicationId`

The application ID of the COM+ application. The special value {84ac4168-6fe5-4308-a2ed-03688a023c7a} is used for the SWC pseudo-application.

### `Type`

The type of COM+ application. For a list of values, see [COMPLUS_APPTYPE](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-complus_apptype).

### `ApplicationName`

The name of the COM+ application, or an empty string for the SWC pseudo-application. Space for this string is allocated by the method called and freed by the caller (for more information, see [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). This member is not returned by default. To return this member, specify the GATD_INCLUDE_APPLICATION_NAME flag when you call a method that returns an [ApplicationProcessSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocesssummary) structure.

### `NumTrackedComponents`

The number of distinct components from this COM+ application instantiated in the hosting process.

### `NumComponentInstances`

The number of component instances from this COM+ application in the hosting process.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)