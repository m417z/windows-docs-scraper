# IWaaSAssessor::GetOSUpdateAssessment

## Description

Gets the OS update assessment by comparing the latest release OS version from Microsoft to the OS build running on the device.

## Parameters

### `result` [out, retval]

On success, contains a pointer to the OS update assessment.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

**GetOSUpdateAssessment** retrieves the OS update assessment. The assessment provides information on updates applicable to a device: specifically, if the OS on the device is up-to-date. If the OS is not up-to-date, the assessment provides some reasons why. The assessment also suggests the potential impact being out-of-date has on the device.

Your code must have administrator privileges to use the **GetOSUpdateAssessment** method. For more details about developing applications that require administrator privileges, see [this article](https://learn.microsoft.com/windows/win32/secauthz/developing-applications-that-require-administrator-privilege).

## See also

[IWaaSAssessor](https://learn.microsoft.com/windows/desktop/api/waasapi/nn-waasapi-iwaasassessor)