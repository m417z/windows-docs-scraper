# IBDA_DeviceControl::CheckChanges

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **CheckChanges** method queries the device filter as to whether the changes that are pending would succeed if they were committed.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method provides a means to determine whether a particular set of changes would be successful, without actually modifying any parameters on the device.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_DeviceControl Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_devicecontrol)