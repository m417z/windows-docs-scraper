# ComponentSummary structure

## Description

Represents summary information about a COM+ component hosted in a particular process. It can also represent a Services Without Components (SWC) context.

## Members

### `ApplicationInstanceId`

The application instance GUID that uniquely identifies the process that hosts the component.

### `PartitionId`

The partition ID of the component.

### `ApplicationId`

The application ID of the component. The special value {84ac4168-6fe5-4308-a2ed-03688a023c7a} indicates that this is an SWC context.

### `Clsid`

The CLSID of the component.

### `ClassName`

The name of the component. Usually, this is the component's ProgID (or the string representation of the component's CLSID if the component does not have a ProgID). For SWC contexts, this is the context name property configured for the context. Space for this string is allocated by the method called and freed by the caller (for more information, see [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). This member is not returned by default. To return this member, specify the GATD_INCLUDE_CLASS_NAME flag when you call a method that returns a **ComponentSummary** structure.

### `ApplicationName`

The name of the COM+ application, or the application name property configured for an SWC context. Space for this string is allocated by the method called and freed by the caller (for more information, see [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). This member is not returned by default. To return this member, specify the GATD_INCLUDE_APPLICATION_NAME flag when you call a method that returns a **ComponentSummary** structure.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)