# IOfflineFilesEvents2::SettingsChangesApplied

## Description

Reports that the Offline Files service has applied the changes that were detected in Group Policy or preference values.

## Return value

The return value is ignored.

## Remarks

After the Offline Files service reports that it has detected changes in Group Policy or preference settings, it waits for up to 5 seconds before it applies the changes to the system and calls this method. Therefore, up to 5 seconds can elapse between the last [PolicyChangeDetected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-policychangedetected) or [PreferenceChangeDetected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-preferencechangedetected) event and the **SettingsChangesApplied** event. An event listener should not make assumptions or perform any actions based on this time interval.

## See also

[IOfflineFilesEvents2](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents2)