# CInstance::GetEmbeddedObject

## Description

[The [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetEmbeddedObject** method retrieves a pointer to an embedded [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) object. The pointer can be used to get and set properties of that embedded object.

## Parameters

### `name`

Name of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) property retrieved.

### `pInstance`

Buffer that receives the pointer to the embedded [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) object.

### `pMethodContext`

Additional information communicated to the provider.

## Return value

Returns **TRUE** if the operation was successful and **FALSE** if an attempt was made to retrieve a property that is not a [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance)-compatible type or a property that does not exist. More information is available in the log file, Framework.log.