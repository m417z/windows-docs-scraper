## Description

Queries the values of the application setting defined as type `stringlist` across all Application Control for Business policies in the supplied file.

Application settings provide Application Control customers with the ability to configure application-defined behvaiors when Application Control is enabled on systems. Software vendors pre-define the settings in manifests, and the behavior in their applications. Application Control provides the reconciled value of those settings from all policies on the system to the calling process. For example, script hosts can allow App Control customers to define whether the buffer, file or stream that failed policy should run in a sandbox or be blocked from executing. App Control defers the definition of application settings to the software vendors and returns the application setting results to the application to handle the behavior.

## Syntax

```c++
STDAPI
WldpGetApplicationSettingStringList(
    _In_ PCWSTR id,
    _In_ PCWSTR setting,
    _In_ SIZE_T dataCount,
    _Out_ SIZE_T *requiredCount,
    _Out_writes_to_opt_(*dataCount, *requiredCount) PZZWSTR result
    );
```

## Parameters

### `id` [in]

A string specifying the application to which the application setting applies.

### `setting` [in]

A string specifying the name of the setting for which to check all Application Control policies.

### `dataCount` [in]

Supplies the size of the `result` buffer, in characters.

### `requiredCount` [out]

On return, requiredCount will be populated with the required size of the `result` string, in characters.

### `result` [out, optional]

Contains a packed and null-terminated array of null-terminated strings of size `*requiredCount`. Callers can unpack the array into a collection of their choice.

## Return value

Returns S_OK on success and a failure code otherwise.

## Remarks

Callers should follow the methodology described in [Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/win32/seccrypto/retrieving-data-of-unknown-length) to properly size the Data buffer.

Across all Application Control policies on the system, all non empty values for the application setting is concatenated and returned. Policies which do not specify the value for the application setting queried is assumed to be an empty value.

![WldpGetApplicatSetting Value Resolution Diagram](https://learn.microsoft.com/windows/win32/api/wldp/images/wldpgetapplicationsetting-resolutiondiagram.png)

## See also

- [WldpGetApplicationSettingStringSet](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpgetapplicationsettingstringset)
- [WldpGetApplicationSettingBoolean](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpgetapplicationsettingboolean)
- [Microsoft Application Control App Manifests](https://github.com/MicrosoftDocs/MS-AppControl-AppManifests)