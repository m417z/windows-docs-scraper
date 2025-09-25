## Description

Queries the values of the application setting defined as type `boolean` across all Application Control for Business policies in the supplied file.

Application settings provide Application Control customers with the ability to configure application-defined behvaiors when Application Control is enabled on systems. Software vendors pre-define the settings in manifests, and the behavior in their applications. Application Control provides the reconciled value of those settings from all policies on the system to the calling process. For example, script hosts can allow App Control customers to define whether the buffer, file or stream that failed policy should run in a sandbox or be blocked from executing. App Control defers the definition of application settings to the software vendors and returns the application setting results to the application to handle the behavior.

## Syntax

```c++
STDAPI
WldpGetApplicationSettingBoolean(
    _In_ PCWSTR id,
    _In_ PCWSTR setting,
    _Out_ BOOL_ *result,
    );
```

## Parameters

### `id` [in]

A string specifying the application to which the application setting applies.

### `setting` [in]

A string specifying the name of the setting for which to check all Application Control policies.

### `result` [out]

Supplies a pointer with the application setting value. The value should be interpreted as:

- `1` being a `true` value for the application setting
- `0` being a `false` value for the application setting

## Return value

Returns S_OK on success and a failure code otherwise.

## Remarks

Within an Application Control policy group, a base policy and its supplemental policies, the boolean values for the application setting are unioned together. The results from each policy group are then intersected together and returned. Any policy which does not specify a value for the given application setting is assumed to have the value `false`.

![WldpGetApplicatSetting Value Resolution Diagram](https://learn.microsoft.com/windows/win32/api/wldp/images/wldpgetapplicationsetting-resolutiondiagram.png)

## See also

- [WldpGetApplicationSettingStringList](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpgetapplicationsettingstringlist)
- [WldpGetApplicationSettingStringSet](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpgetapplicationsettingstringset)
- [Microsoft Application Control App Manifests](https://github.com/MicrosoftDocs/MS-AppControl-AppManifests)