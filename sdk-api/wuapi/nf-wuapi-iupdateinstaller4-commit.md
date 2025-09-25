# IUpdateInstaller4::Commit

## Description

Finalizes updates that were previously staged or installed.

## Parameters

### `dwFlags`

Reserved for future use.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows

error code.

## Remarks
The **Commit** API was made public in the 1809 SDK. Any app compiled with the wuapi.h header can use the **Commit** method on previous versions of Windows 10 as well.

**Commit** should only be called once. This call should happen just prior to commencing a reboot. Calling it multiple times prior to a reboot is not supported and may cause the update to fail.

Calling **Commit** is required prior to rebooting when a feature update is pending reboot. If **Commit** is not called in this circumstance the update won’t be finalized and installed during the reboot.

**Commit** is safe to call prior to reboot for any other types of updates as well.

## See also

[IUpdateInstaller4](https://learn.microsoft.com/previous-versions/mt694206(v=vs.85))