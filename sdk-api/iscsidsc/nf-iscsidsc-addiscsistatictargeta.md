# AddIScsiStaticTargetA function

## Description

The **AddIscsiStaticTarget** function adds a target to the list of static targets available to the iSCSI initiator.

## Parameters

### `TargetName` [in]

The name of the target to add to the static target list.

### `TargetAlias` [in, optional]

An alias associated with the *TargetName*.

### `TargetFlags` [in]

A bitmap of flags that affect how, and under what circumstances, a target is discovered and enumerated.

The following table lists the flags that can be associated with a target and the meaning of each flag.

| Value | Meaning |
| --- | --- |
| **ISCSI_TARGET_FLAG_HIDE_STATIC_TARGET** | The target is added to the list of static targets. However, [ReportIscsiTargets](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsitargetsa) does not report the target, unless it was also discovered dynamically by the iSCSI initiator, the Internet Storage Name Service (iSNS), or a **SendTargets** request. |
| **ISCSI_TARGET_FLAG_MERGE_TARGET_INFORMATION** | The iSCSI initiator service merges the information (if any) that it already has for this static target with the information that the caller passes to **AddIscsiStaticTarget**. <br><br>If this flag is not set, the iSCSI initiator service overwrites the stored information with the information that the caller passes in. |

### `Persist` [in]

If **true**, the target information persists across restarts of the iSCSI initiator service.

### `Mappings` [in, optional]

A pointer to a structure of type [ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga) that contains a set of mappings that the initiator uses when assigning values for the bus, target, and LUN numbers to the iSCSI LUNs associated with the target.
If *Mappings* is **null**, the initiator will select the bus, target, and LUN numbers.

### `LoginOptions` [in, optional]

A pointer to a structure of type [ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options) that contains the options that specify the default login parameters that an initiator uses to login to a target.

### `PortalGroup` [in, optional]

A pointer to a structure of type [ISCSI_TARGET_PORTAL_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_groupa) that indicates the group of portals that an initiator can use login to the target.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

This routine adds a target to the iSCSI initiator service's list of static targets. If the caller specifies a value of **true** in *Persist*, the target is stored in the registry and information about the target persists across restarts of the initiator service and reboots of the operating system.

By setting the **ISCSI_TARGET_FLAG_HIDE_STATIC_TARGET** flag, callers can configure default login information for a target prior to its discovery by an iSCSI initiator, the iSNS service, or a SendTargets request.

> [!NOTE]
> The iscsidsc.h header defines AddIScsiStaticTarget as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ISCSI_LOGIN_OPTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_login_options)

[ISCSI_TARGET_MAPPING](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_mappinga)

[ISCSI_TARGET_PORTAL_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portal_groupa)

[RemoveIscsiStaticTarget](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removeiscsistatictargeta)