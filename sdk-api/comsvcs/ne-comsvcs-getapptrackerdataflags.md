# GetAppTrackerDataFlags enumeration

## Description

Controls what data is returned from calls to the [IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata) interface.

## Constants

### `GATD_INCLUDE_PROCESS_EXE_NAME:0x1`

Include the name of the process's executable image in the [ApplicationProcessSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationprocesssummary) structure. If set, it is the caller's responsibility to free the memory allocated for this string.

### `GATD_INCLUDE_LIBRARY_APPS:0x2`

Include COM+ library applications in the tracking data. By default, these are excluded.

### `GATD_INCLUDE_SWC:0x4`

Include Services Without Components contexts in the tracking data. By default, these are excluded.

### `GATD_INCLUDE_CLASS_NAME:0x8`

Include the class name in the [ComponentSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componentsummary) structure. If set, it is the caller's responsibility to free the memory allocated for this string.

### `GATD_INCLUDE_APPLICATION_NAME:0x10`

Include the application name in the [ApplicationSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-applicationsummary) and [ComponentSummary](https://learn.microsoft.com/windows/desktop/api/comsvcs/ns-comsvcs-componentsummary) structures. If set, it is the caller's responsibility to free the memory allocated for this string.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)